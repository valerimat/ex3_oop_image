#pragma once
/*
This class will handle heap allocations for image
Image will request from it memory and it will give it to the image
When image is dertroyed the image will ask to free the heap in usage
*/
//-------------------------------Include section
#include "Pixel.h"

//-------------------------------Class section
struct ImageDataStructure {
public:
	//--------C-tors:
	ImageDataStructure(int width, int height);
	ImageDataStructure();

	//--------Opperators:
	Pixel*& operator[](int height) const;

	//--------Helppers:
	void free();

private:

	//--------Members:
	int m_height;
	int m_width;
	Pixel** m_data;
};