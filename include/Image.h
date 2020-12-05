#pragma once

#include <iostream>
#include "Pixel.h"
#include "macros.h"
#include "ImageDataStructure.h"

class Image
{
public:
	Image(const Image& other);
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	//(const Image &other);
	~Image(); // have issues we need to know why

	Image &operator=(const Image &other);
	Image operator+(const Image &other)const;
	Pixel& operator()(int unsigned i, int unsigned j) ;
	Pixel  operator()(int unsigned i, int unsigned j) const;
	Image operator|(const Image& other)const;
	Image operator&(const Image& other)const;

	int			 GetHeight() const;
	int			 GetWidth()  const;

private:

	unsigned int get_color()  const;
	int m_height, m_width;
	unsigned char m_pixel;
	ImageDataStructure m_data;
	void set_image_pixel(int x, int y , unsigned char pixel);
};

bool operator==(const Image &left, const Image &right);
bool operator!=(const Image &left, const Image &right);
Image &operator|=(Image& left, const Image& right);
Image& operator&=(Image& left, const Image& right);
Image &operator+=(Image& left, const Image& right);
Image operator*(const Image& left, int n);
Image operator*(int n, const Image& image);
Image operator~(const Image& other);
std::ostream &operator<<(std::ostream &stream, const Image &image);

