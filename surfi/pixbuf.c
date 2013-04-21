/* See LICENSE file for copyright and license details. */

#include <stdbool.h>

#include <gdk/gdk.h>

#include "surfi/pixbuf.h"


int surfi_pixbuf_get_bits_per_sample(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_bits_per_sample(pixbuf);
}

unsigned int surfi_pixbuf_get_byte_length(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_byte_length(pixbuf);
}

bool surfi_pixbuf_get_has_alpha(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_has_alpha(pixbuf);
}

int surfi_pixbuf_get_height(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_height(pixbuf);
}

int surfi_pixbuf_get_n_channels(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_n_channels(pixbuf);
}

const char* surfi_pixbuf_get_option(Pixbuf* pixbuf, const char* key)
{
	return gdk_pixbuf_get_option(pixbuf, key);
}

unsigned char* surfi_pixbuf_get_pixels(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_pixels(pixbuf);
}

unsigned char* surfi_pixbuf_get_pixels_with_length(Pixbuf* pixbuf, unsigned int* length)
{
	return gdk_pixbuf_get_pixels_with_length(pixbuf, length);
}

int surfi_pixbuf_get_rowstride(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_rowstride(pixbuf);
}

int surfi_pixbuf_get_width(Pixbuf* pixbuf)
{
	return gdk_pixbuf_get_width(pixbuf);
}

bool surfi_pixbuf_save(Pixbuf* pixbuf, const char* filename, const char* type)
{
	return gdk_pixbuf_save(pixbuf, filename, type, NULL, NULL);
}