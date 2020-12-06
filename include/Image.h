#pragma once
/*
This class will store Image and all its components,
Its operators, members, and functions
*/

//-------------------------------Include section
#include <iostream>
#include "Pixel.h"
#include "macros.h"
#include "ImageDataStructure.h"

//-------------------------------Class section
class Image
{
public:
	//--------C-tors:
	Image();
	Image(int height, int width);
	Image(int height, int width, unsigned char pixel);
	//--------Copy-C-Tor:
	Image(const Image& other);
	//--------D-tors:
	~Image();

	//--------Opperators:
	Image &operator=(const Image &other);
	Image operator+(const Image &other)const;
	Pixel& operator()(int unsigned i, int unsigned j) ;
	Pixel  operator()(int unsigned i, int unsigned j) const;
	Image operator|(const Image& other)const;
	Image operator&(const Image& other)const;

	//--------Helppers:
	int			 GetHeight() const;
	int			 GetWidth()  const;

private:

	//--------Members:
	int m_height, m_width;
	unsigned char m_pixel;
	ImageDataStructure m_data;

	//--------Helper Function:
	unsigned int get_color()  const;
	void set_image_pixel(int x, int y , unsigned char pixel);
};


//--------Global Operators:
bool operator==(const Image &left, const Image &right);
bool operator!=(const Image &left, const Image &right);

Image operator*(const Image& left, int n);
Image operator*(int n, const Image& image);
Image operator~(const Image& other);

Image& operator|=(Image& left, const Image& right);
Image& operator&=(Image& left, const Image& right);
Image& operator+=(Image& left, const Image& right);

std::ostream &operator<<(std::ostream &stream, const Image &image);

