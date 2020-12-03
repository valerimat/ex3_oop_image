#pragma once

#include <iostream>
#include "Pixel.h"
#include "macros.h"


class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	Image(const Image &other);
	~Image(); // have issues we need to know why

	Image &operator=(const Image &other);
	Image operator+(const Image &other);

	int			 get_height() const;
	int			 get_width()  const;
	unsigned int get_color()  const;
	void print_image() const; // we can delete we have <<

private:

	int m_height, m_width;
	unsigned char m_pixel;
	Pixel **m_image;

	void set_image_pixel(int x, int y , unsigned char pixel);
};

bool operator==(const Image &left, const Image &right);
bool operator!=(const Image &left, const Image &right);

std::ostream &operator<<(std::ostream &stream, const Image &image);

