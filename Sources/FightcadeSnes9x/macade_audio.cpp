#include "macade_audio.h"

#include <AudioToolbox/AudioToolbox.h>

#include <algorithm>
#include <cstring>
#include <mutex>
#include <vector>

namespace {

constexpr int kChannels = 2;
constexpr int kBytesPerSample = sizeof(int16_t);
constexpr int kQueueBufferCount = 3;
constexpr int kQueueBufferFrames = 2048;

struct AudioState {
    std::mutex mutex;
    AudioQueueRef queue = nullptr;
    AudioQueueBufferRef buffers[kQueueBufferCount] = {};
    std::vector<int16_t> ring;
    size_t readIndex = 0;
    size_t writeIndex = 0;
    size_t available = 0;
    bool started = false;
};

AudioState audio;

size_t queueBufferBytes()
{
    return kQueueBufferFrames * kChannels * kBytesPerSample;
}

void fillAudioBuffer(AudioQueueBufferRef buffer)
{
    auto *output = static_cast<int16_t *>(buffer->mAudioData);
    const size_t requestedSamples = buffer->mAudioDataBytesCapacity / kBytesPerSample;
    size_t copied = 0;

    {
        std::lock_guard<std::mutex> lock(audio.mutex);
        while (copied < requestedSamples && audio.available > 0) {
            const size_t chunk = std::min({
                requestedSamples - copied,
                audio.available,
                audio.ring.size() - audio.readIndex
            });
            std::memcpy(output + copied, audio.ring.data() + audio.readIndex, chunk * kBytesPerSample);
            audio.readIndex = (audio.readIndex + chunk) % audio.ring.size();
            audio.available -= chunk;
            copied += chunk;
        }
    }

    if (copied < requestedSamples) {
        std::memset(output + copied, 0, (requestedSamples - copied) * kBytesPerSample);
    }
    buffer->mAudioDataByteSize = static_cast<UInt32>(requestedSamples * kBytesPerSample);
}

void audioQueueCallback(void *, AudioQueueRef queue, AudioQueueBufferRef buffer)
{
    fillAudioBuffer(buffer);
    AudioQueueEnqueueBuffer(queue, buffer, 0, nullptr);
}

void pushSamples(const int16_t *samples, size_t sampleCount)
{
    if (samples == nullptr || sampleCount == 0) {
        return;
    }

    std::lock_guard<std::mutex> lock(audio.mutex);
    if (!audio.started || audio.ring.empty()) {
        return;
    }

    for (size_t index = 0; index < sampleCount; ++index) {
        if (audio.available == audio.ring.size()) {
            audio.readIndex = (audio.readIndex + 1) % audio.ring.size();
            --audio.available;
        }
        audio.ring[audio.writeIndex] = samples[index];
        audio.writeIndex = (audio.writeIndex + 1) % audio.ring.size();
        ++audio.available;
    }
}

void resetStateNoLock()
{
    audio.queue = nullptr;
    audio.started = false;
    audio.ring.clear();
    audio.readIndex = 0;
    audio.writeIndex = 0;
    audio.available = 0;
    for (AudioQueueBufferRef &buffer : audio.buffers) {
        buffer = nullptr;
    }
}

} // namespace

bool MacadeSnes9xAudioStart(double sampleRate)
{
    if (sampleRate <= 1.0) {
        sampleRate = 32040.0;
    }

    AudioQueueRef queueToStart = nullptr;
    {
        std::lock_guard<std::mutex> lock(audio.mutex);
        if (audio.started) {
            return true;
        }

        AudioStreamBasicDescription format {};
        format.mSampleRate = sampleRate;
        format.mFormatID = kAudioFormatLinearPCM;
        format.mFormatFlags = kAudioFormatFlagIsSignedInteger | kAudioFormatFlagIsPacked;
        format.mFramesPerPacket = 1;
        format.mChannelsPerFrame = kChannels;
        format.mBitsPerChannel = 16;
        format.mBytesPerFrame = kChannels * kBytesPerSample;
        format.mBytesPerPacket = format.mBytesPerFrame;

        OSStatus status = AudioQueueNewOutput(&format, audioQueueCallback, nullptr, nullptr, nullptr, 0, &audio.queue);
        if (status != noErr) {
            resetStateNoLock();
            return false;
        }

        audio.ring.assign(static_cast<size_t>(sampleRate) * kChannels, 0);
        audio.readIndex = 0;
        audio.writeIndex = 0;
        audio.available = 0;

        for (AudioQueueBufferRef &buffer : audio.buffers) {
            status = AudioQueueAllocateBuffer(audio.queue, static_cast<UInt32>(queueBufferBytes()), &buffer);
            if (status != noErr) {
                AudioQueueDispose(audio.queue, true);
                resetStateNoLock();
                return false;
            }
            buffer->mAudioDataByteSize = static_cast<UInt32>(queueBufferBytes());
            std::memset(buffer->mAudioData, 0, buffer->mAudioDataByteSize);
            AudioQueueEnqueueBuffer(audio.queue, buffer, 0, nullptr);
        }

        audio.started = true;
        queueToStart = audio.queue;
    }

    OSStatus status = AudioQueueStart(queueToStart, nullptr);
    if (status != noErr) {
        MacadeSnes9xAudioStop();
        return false;
    }
    return true;
}

void MacadeSnes9xAudioStop()
{
    AudioQueueRef queue = nullptr;
    {
        std::lock_guard<std::mutex> lock(audio.mutex);
        queue = audio.queue;
        audio.queue = nullptr;
        audio.started = false;
    }

    if (queue != nullptr) {
        AudioQueueStop(queue, true);
        AudioQueueDispose(queue, true);
    }

    std::lock_guard<std::mutex> lock(audio.mutex);
    resetStateNoLock();
}

void MacadeSnes9xAudioWriteSample(int16_t left, int16_t right)
{
    int16_t samples[2] = { left, right };
    pushSamples(samples, 2);
}

void MacadeSnes9xAudioWriteBatch(const int16_t *samples, size_t frames)
{
    pushSamples(samples, frames * kChannels);
}
