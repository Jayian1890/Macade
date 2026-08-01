#include "macade_embedded_scale.h"
#include "macade_embedded.h"
#include <stdlib.h>
#include <string.h>

int MacadeEmbeddedVideoScale = 0;

static unsigned char* scaledPixels = NULL;
static size_t scaledPixelBytes = 0;

static int NormalizedScale()
{
	if (MacadeEmbeddedVideoScale < 1) return 1;
	if (MacadeEmbeddedVideoScale > 5) return 5;
	return MacadeEmbeddedVideoScale;
}

void MacadeEmbeddedPublishScaledFrame(
	const void* pixels,
	int width,
	int height,
	int pitch,
	int bytesPerPixel,
	int isRGB565
)
{
	int scale = NormalizedScale();
	if (scale == 1 || bytesPerPixel <= 0) {
		MacadeEmbeddedPublishFrame(pixels, width, height, pitch, bytesPerPixel, isRGB565);
		return;
	}

	int outputWidth = width * scale;
	int outputHeight = height * scale;
	int outputPitch = outputWidth * bytesPerPixel;
	size_t outputBytes = (size_t)outputPitch * (size_t)outputHeight;
	if (outputBytes > scaledPixelBytes) {
		unsigned char* replacement = (unsigned char*)realloc(scaledPixels, outputBytes);
		if (replacement == NULL) return;
		scaledPixels = replacement;
		scaledPixelBytes = outputBytes;
	}

	const unsigned char* source = (const unsigned char*)pixels;
	for (int y = 0; y < height; y++) {
		const unsigned char* sourceRow = source + (size_t)y * (size_t)pitch;
		unsigned char* outputRow = scaledPixels + (size_t)y * (size_t)scale * (size_t)outputPitch;

		for (int x = 0; x < width; x++) {
			const unsigned char* sourcePixel = sourceRow + (size_t)x * (size_t)bytesPerPixel;
			unsigned char* outputPixel = outputRow + (size_t)x * (size_t)scale * (size_t)bytesPerPixel;
			for (int sx = 0; sx < scale; sx++) {
				memcpy(outputPixel + (size_t)sx * (size_t)bytesPerPixel, sourcePixel, (size_t)bytesPerPixel);
			}
		}

		for (int sy = 1; sy < scale; sy++) {
			memcpy(outputRow + (size_t)sy * (size_t)outputPitch, outputRow, (size_t)outputPitch);
		}
	}

	MacadeEmbeddedPublishFrame(scaledPixels, outputWidth, outputHeight, outputPitch, bytesPerPixel, isRGB565);
}
