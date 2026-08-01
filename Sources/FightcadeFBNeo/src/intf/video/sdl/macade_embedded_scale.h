#pragma once

extern int MacadeEmbeddedVideoScale;

void MacadeEmbeddedPublishScaledFrame(
	const void* pixels,
	int width,
	int height,
	int pitch,
	int bytesPerPixel,
	int isRGB565
);
