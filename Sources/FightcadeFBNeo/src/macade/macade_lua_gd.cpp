#include "burner.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
}

#include "png.h"

#include <algorithm>
#include <new>
#include <vector>

struct MacadeGdImage {
	int width;
	int height;
	std::vector<unsigned char> rgba;
};

struct MacadePngReadState {
	const unsigned char* data;
	size_t size;
	size_t offset;
};

static MacadeGdImage* MacadeGdCheck(lua_State* L, int index)
{
	return (MacadeGdImage*)luaL_checkudata(L, index, "macade.gd.image");
}

static MacadeGdImage* MacadeGdPush(lua_State* L, int width, int height)
{
	if (width <= 0 || height <= 0) luaL_error(L, "invalid image size");
	MacadeGdImage* image = (MacadeGdImage*)lua_newuserdata(L, sizeof(MacadeGdImage));
	new (image) MacadeGdImage();
	image->width = width;
	image->height = height;
	image->rgba.assign((size_t)width * (size_t)height * 4, 0);
	luaL_getmetatable(L, "macade.gd.image");
	lua_setmetatable(L, -2);
	return image;
}

static void MacadePngRead(png_structp png, png_bytep out, png_size_t count)
{
	MacadePngReadState* state = (MacadePngReadState*)png_get_io_ptr(png);
	if (state->offset + count > state->size) png_error(png, "png read overflow");
	memcpy(out, state->data + state->offset, count);
	state->offset += count;
}

static int MacadeGdLoadPng(lua_State* L, const unsigned char* data, size_t size)
{
	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png == NULL) return luaL_error(L, "unable to create png reader");
	png_infop info = png_create_info_struct(png);
	if (info == NULL) {
		png_destroy_read_struct(&png, NULL, NULL);
		return luaL_error(L, "unable to create png info");
	}
	if (setjmp(png_jmpbuf(png))) {
		png_destroy_read_struct(&png, &info, NULL);
		return luaL_error(L, "unable to decode png");
	}
	MacadePngReadState state = { data, size, 0 };
	png_set_read_fn(png, &state, MacadePngRead);
	png_read_info(png, info);
	png_uint_32 width = png_get_image_width(png, info);
	png_uint_32 height = png_get_image_height(png, info);
	int colorType = png_get_color_type(png, info);
	int bitDepth = png_get_bit_depth(png, info);
	if (bitDepth == 16) png_set_strip_16(png);
	if (colorType == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
	if (colorType == PNG_COLOR_TYPE_GRAY && bitDepth < 8) png_set_expand_gray_1_2_4_to_8(png);
	if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
	if (colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(png);
	if ((colorType & PNG_COLOR_MASK_ALPHA) == 0 && !png_get_valid(png, info, PNG_INFO_tRNS)) png_set_filler(png, 0xff, PNG_FILLER_AFTER);
	png_read_update_info(png, info);
	MacadeGdImage* image = MacadeGdPush(L, (int)width, (int)height);
	std::vector<png_bytep> rows(height);
	for (png_uint_32 y = 0; y < height; y++) rows[y] = image->rgba.data() + (size_t)y * width * 4;
	png_read_image(png, rows.data());
	png_read_end(png, NULL);
	png_destroy_read_struct(&png, &info, NULL);
	return 1;
}

static int MacadeGdCreateFromPng(lua_State* L)
{
	const char* path = luaL_checkstring(L, 1);
	FILE* file = fopen(path, "rb");
	if (file == NULL) return luaL_error(L, "unable to open png: %s", path);
	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (length <= 0) {
		fclose(file);
		return luaL_error(L, "empty png: %s", path);
	}
	std::vector<unsigned char> data((size_t)length);
	if (fread(data.data(), 1, data.size(), file) != data.size()) {
		fclose(file);
		return luaL_error(L, "unable to read png: %s", path);
	}
	fclose(file);
	return MacadeGdLoadPng(L, data.data(), data.size());
}

static int MacadeGdCreateFromPngStr(lua_State* L)
{
	size_t size = 0;
	const unsigned char* data = (const unsigned char*)luaL_checklstring(L, 1, &size);
	return MacadeGdLoadPng(L, data, size);
}

static unsigned char MacadeGdAlphaToPng(unsigned char alpha)
{
	if (alpha > 127) alpha = 127;
	return (unsigned char)(((127 - alpha) * 255) / 127);
}

static unsigned char MacadePngAlphaToGd(unsigned char alpha)
{
	return (unsigned char)(((255 - alpha) * 127) / 255);
}

static int MacadeGdCreateFromGdStr(lua_State* L)
{
	size_t size = 0;
	const unsigned char* data = (const unsigned char*)luaL_checklstring(L, 1, &size);
	if (size < 11 || data[0] != 255 || data[1] != 254 || data[6] == 0) return luaL_error(L, "bad gd image data");
	int width = (data[2] << 8) | data[3];
	int height = (data[4] << 8) | data[5];
	if (size < 11 + (size_t)width * (size_t)height * 4) return luaL_error(L, "truncated gd image data");
	MacadeGdImage* image = MacadeGdPush(L, width, height);
	const unsigned char* src = data + 11;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++, src += 4) {
			size_t offset = ((size_t)y * width + x) * 4;
			image->rgba[offset + 0] = src[1];
			image->rgba[offset + 1] = src[2];
			image->rgba[offset + 2] = src[3];
			image->rgba[offset + 3] = MacadeGdAlphaToPng(src[0]);
		}
	}
	return 1;
}

static int MacadeGdCreate(lua_State* L)
{
	MacadeGdPush(L, luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
	return 1;
}

static void MacadeGdCopyPixel(MacadeGdImage* dst, const MacadeGdImage* src, int dx, int dy, int sx, int sy)
{
	if (dx < 0 || dy < 0 || sx < 0 || sy < 0 || dx >= dst->width || dy >= dst->height || sx >= src->width || sy >= src->height) return;
	memcpy(&dst->rgba[((size_t)dy * dst->width + dx) * 4], &src->rgba[((size_t)sy * src->width + sx) * 4], 4);
}

static int MacadeGdCopy(lua_State* L)
{
	MacadeGdImage* dst = MacadeGdCheck(L, 1);
	MacadeGdImage* src = MacadeGdCheck(L, 2);
	int dstX = luaL_checkinteger(L, 3);
	int dstY = luaL_checkinteger(L, 4);
	int srcX = luaL_checkinteger(L, 5);
	int srcY = luaL_checkinteger(L, 6);
	int width = luaL_checkinteger(L, 7);
	int height = luaL_checkinteger(L, 8);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) MacadeGdCopyPixel(dst, src, dstX + x, dstY + y, srcX + x, srcY + y);
	}
	return 0;
}

static int MacadeGdCopyResampled(lua_State* L)
{
	MacadeGdImage* dst = MacadeGdCheck(L, 1);
	MacadeGdImage* src = MacadeGdCheck(L, 2);
	int dstX = luaL_checkinteger(L, 3);
	int dstY = luaL_checkinteger(L, 4);
	int srcX = luaL_checkinteger(L, 5);
	int srcY = luaL_checkinteger(L, 6);
	int dstW = luaL_checkinteger(L, 7);
	int dstH = luaL_checkinteger(L, 8);
	int srcW = luaL_checkinteger(L, 9);
	int srcH = luaL_checkinteger(L, 10);
	if (dstW <= 0 || dstH <= 0 || srcW <= 0 || srcH <= 0) return 0;
	for (int y = 0; y < dstH; y++) {
		int sy = srcY + (y * srcH) / dstH;
		for (int x = 0; x < dstW; x++) {
			int sx = srcX + (x * srcW) / dstW;
			MacadeGdCopyPixel(dst, src, dstX + x, dstY + y, sx, sy);
		}
	}
	return 0;
}

static int MacadeGdSizeX(lua_State* L)
{
	lua_pushinteger(L, MacadeGdCheck(L, 1)->width);
	return 1;
}

static int MacadeGdSizeY(lua_State* L)
{
	lua_pushinteger(L, MacadeGdCheck(L, 1)->height);
	return 1;
}

static int MacadeGdStr(lua_State* L)
{
	MacadeGdImage* image = MacadeGdCheck(L, 1);
	std::vector<unsigned char> out(11 + (size_t)image->width * (size_t)image->height * 4);
	out[0] = 255;
	out[1] = 254;
	out[2] = (unsigned char)((image->width >> 8) & 0xff);
	out[3] = (unsigned char)(image->width & 0xff);
	out[4] = (unsigned char)((image->height >> 8) & 0xff);
	out[5] = (unsigned char)(image->height & 0xff);
	out[6] = 1;
	out[7] = 255;
	out[8] = 255;
	out[9] = 255;
	out[10] = 255;
	unsigned char* dst = out.data() + 11;
	for (int y = 0; y < image->height; y++) {
		for (int x = 0; x < image->width; x++, dst += 4) {
			size_t offset = ((size_t)y * image->width + x) * 4;
			dst[0] = MacadePngAlphaToGd(image->rgba[offset + 3]);
			dst[1] = image->rgba[offset + 0];
			dst[2] = image->rgba[offset + 1];
			dst[3] = image->rgba[offset + 2];
		}
	}
	lua_pushlstring(L, (const char*)out.data(), out.size());
	return 1;
}

static int MacadeGdPng(lua_State* L)
{
	MacadeGdImage* image = MacadeGdCheck(L, 1);
	const char* path = luaL_checkstring(L, 2);
	FILE* file = fopen(path, "wb");
	if (file == NULL) return luaL_error(L, "unable to open png for write: %s", path);
	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop info = png == NULL ? NULL : png_create_info_struct(png);
	if (png == NULL || info == NULL || setjmp(png_jmpbuf(png))) {
		if (png != NULL) png_destroy_write_struct(&png, info == NULL ? NULL : &info);
		fclose(file);
		return luaL_error(L, "unable to encode png: %s", path);
	}
	png_init_io(png, file);
	png_set_IHDR(png, info, image->width, image->height, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png, info);
	std::vector<png_bytep> rows(image->height);
	for (int y = 0; y < image->height; y++) rows[y] = image->rgba.data() + (size_t)y * image->width * 4;
	png_write_image(png, rows.data());
	png_write_end(png, NULL);
	png_destroy_write_struct(&png, &info);
	fclose(file);
	return 0;
}

static int MacadeGdGc(lua_State* L)
{
	MacadeGdCheck(L, 1)->~MacadeGdImage();
	return 0;
}

extern "C" int luaopen_gd(lua_State* L)
{
	static const luaL_Reg methods[] = {
		{ "copy", MacadeGdCopy },
		{ "gdStr", MacadeGdStr },
		{ "png", MacadeGdPng },
		{ "pngStr", MacadeGdStr },
		{ "sizeX", MacadeGdSizeX },
		{ "sizeY", MacadeGdSizeY },
		{ NULL, NULL }
	};
	static const luaL_Reg funcs[] = {
		{ "copyResampled", MacadeGdCopyResampled },
		{ "copyResized", MacadeGdCopyResampled },
		{ "create", MacadeGdCreate },
		{ "createFromGdStr", MacadeGdCreateFromGdStr },
		{ "createFromPng", MacadeGdCreateFromPng },
		{ "createFromPngStr", MacadeGdCreateFromPngStr },
		{ NULL, NULL }
	};
	luaL_newmetatable(L, "macade.gd.image");
	lua_pushcfunction(L, MacadeGdGc);
	lua_setfield(L, -2, "__gc");
	lua_newtable(L);
	luaL_register(L, NULL, methods);
	lua_setfield(L, -2, "__index");
	lua_pop(L, 1);
	lua_newtable(L);
	luaL_register(L, NULL, funcs);
	return 1;
}
