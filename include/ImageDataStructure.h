#pragma once
#include "Pixel.h"



struct ImageDataStructure {

public:
	ImageDataStructure(int width, int height);
	ImageDataStructure();
	Pixel*& operator[](int height) const;
	void free();

private:
	int m_height;
	int m_width;
	Pixel** m_data;

};