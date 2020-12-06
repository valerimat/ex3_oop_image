#include "ImageDataStructure.h"


//____________C-tors___________________________
ImageDataStructure::ImageDataStructure(int height, int width)
	:m_width(width), m_height(height)
{
	m_data = new Pixel*[height];
	for (int i = 0; i < m_height; ++i)
		m_data[i] = new Pixel[m_width];

}
//---------------------------------------------

ImageDataStructure::ImageDataStructure():
	m_height(0) , m_width(0), m_data(NULL)
{}
//---------------------------------------------

//____________Scoped Ops___________________________
Pixel * & ImageDataStructure::operator[](int height) const
{
	return m_data[height];
}
//---------------------------------------------

//____________Helpers___________________________
void ImageDataStructure::free()
{
	if (m_data != NULL)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_data[i];
		}
		delete m_data;
		m_data = NULL;
	}
}
//---------------------------------------------
