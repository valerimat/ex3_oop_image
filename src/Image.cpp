#include "Image.h"

//____________C-tors___________________________
Image::Image() :Image(0, 0, WHITE)
{}
//---------------------------------------------

Image::Image(int height, int width) : Image(height, width, WHITE)
{}
//---------------------------------------------

Image::Image(int height, int width, unsigned char pixel)
	:m_data(height, width)
{
	m_height = height;
	m_width  = width;
	m_pixel  = pixel; // represents color { white, grey, black }

	m_data = ImageDataStructure(height, width);
		
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Pixel temp(pixel);

			m_data[i][j] = temp;
		}
	}
}
//---------------------------------------------

//____________Copy-C-tors___________________________
Image::Image(const Image &other)
	:m_height (other.m_height),
	 m_width(other.m_width),
	 m_pixel(other.m_pixel)
{

	this->m_data.free();

	*this = other;

}
//---------------------------------------------

//____________D-tors___________________________
Image::~Image()
{
	m_data.free();

}
//---------------------------------------------

//____________Local Operators___________________________
Image& Image::operator=(const Image& other)
{
	m_data.free();

	m_height = other.GetHeight();
	m_width = other.GetWidth();
	m_pixel = other.get_color();

	m_data = ImageDataStructure(m_height, m_width);

	//// move to private fun copy color
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Pixel temp(other(i, j));

			m_data[i][j] = temp;
		}
	}

	return *this;
}
//---------------------------------------------
//Adds two images to one another suming theyr width and using the max height
//This fuction will result diffrent results for A+B and B+A
Image Image::operator+(const Image& other)const
{
	int new_height = max_value(this->GetHeight(), other.GetHeight());
	int new_width = this->GetWidth() + other.GetWidth();



	Image new_image(new_height, new_width);

	for (int i = 0; i < new_height; i++)
	{
		if (i < this->GetHeight())
		{
			for (int j = 0; j < this->GetWidth(); j++)
			{
				new_image.set_image_pixel(i, j, this->get_color());
			}

		}
		if (i < other.GetHeight()) {
			for (int j = this->GetWidth(); j < new_width; j++)
			{
				new_image.set_image_pixel(i, j, other.get_color());
			}
		}
	}
	return new_image;
}
//---------------------------------------------
//Does the same thign the | operator does in pixels but only 
//where the images overlap based on max height and max width
Image Image::operator|(const Image& other) const
{
	int new_height = max_value(this->GetHeight(), other.GetHeight());
	int new_width = max_value(this->GetWidth(), other.GetWidth());

	Image new_image(new_height, new_width);
	Pixel pixel;

	for (int i = 0; i < new_height; i++)
	{
		for (int j = 0; j < new_width; j++)
		{
			if ((j < this->GetWidth() && i < this->GetHeight()) && (j < other.GetWidth() && i < other.GetHeight()))
			{
				pixel = ((*this)(i, j)) | other(i, j);
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
			else if (j < this->GetWidth() && i < this->GetHeight())
			{
				pixel = ((*this)(i, j)) | new_image(i, j);
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
			else if (j < other.GetWidth() && i < other.GetHeight())
			{
				pixel = ((other(i, j)) | new_image(i, j));
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
		}
	}
	return new_image;
}
//---------------------------------------------

//Does the same thign the & operator does in pixels but only 
//where the images overlap based on max height and max width
Image Image::operator&(const Image& other)const
{
	int new_height = min_value(this->GetHeight(), other.GetHeight());
	int new_width = min_value(this->GetWidth(), other.GetWidth());

	Image new_image(new_height, new_width);
	Pixel pixel;

	//run on data structure
	for (int i = 0; i < new_height; i++)
	{
		for (int j = 0; j < new_width; j++)
		{
			if ((j < this->GetWidth() && i < this->GetHeight()) && (j < other.GetWidth() && i < other.GetHeight()))
			{
				pixel = ((*this)(i, j)) & other(i, j);
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
			else if (j < this->GetWidth() && i < this->GetHeight())
			{
				pixel = ((*this)(i, j)) & new_image(i, j);
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
			else if (j < other.GetWidth() && i < other.GetHeight())
			{
				pixel = ((other(i, j)) & new_image(i, j));
				new_image.set_image_pixel(i, j, pixel.Get_Color());
			}
		}
	}
	return new_image;
}
//---------------------------------------------

Pixel& Image::operator()(int unsigned i, int unsigned j)
{
	return m_data[i][j];
}
//---------------------------------------------

Pixel Image::operator()(int unsigned i, int unsigned j) const
{
	return this->m_data[i][j];
}
//---------------------------------------------

//____________Global Operators__________________________
std::ostream &operator<<(std::ostream &stream, const Image &image)
{
	for (int i = 0; i < image.GetHeight(); i++)
	{
		for (int j = 0; j < image.GetWidth(); j++)
		{
			stream << image(i,j).Get_Color();
		}
		stream << std::endl;
	}
	return stream;
}

//based on size and pixel colors
bool operator==(const Image &left, const Image &right) 
{
	if (left.GetHeight() != right.GetHeight() || left.GetWidth() != right.GetWidth())
		return false;

	//compare pixels
	for (int i = 0; i < left.GetHeight(); i++)
	{
		for (int j = 0; j < left.GetWidth(); j++)
		{
			if (left(i, j).Get_Color() != right(i, j).Get_Color())
				return false;
		}
	}
	return true;
}
//---------------------------------------------

Image operator*(const Image& image, int n) {

	Image temp(image);
	for (int i = 0; i < n; ++i)
	{
		temp += image;
	}
	return temp;
}

//---------------------------------------------
Image operator*(int n, const Image& image)
{

	return n * image;
}
//---------------------------------------------

Image& operator*=(Image& image, int n) {

	return image = image * n;
}
//---------------------------------------------
//inverts the image colors
Image operator~(const Image& other)
{
	Image temp(other);

	for (int j = 0; j < other.GetHeight(); j++)
	{
		for (int i = 0; i < other.GetWidth(); i++)
		{
			temp(j, i).Flip();
		}
	}

	return temp;
}
//---------------------------------------------

bool operator!=(const Image &left, const Image &right)
{
	return !(left == right);
}
//---------------------------------------------

Image & operator|=(Image& left, const Image& right)
{
	return left = left|right;
}
//---------------------------------------------

Image& operator&=(Image& left, const Image& right)
{
	return left = left & right;
}
//---------------------------------------------

Image &operator+=(Image& left, const Image& right)
{
	return left = left + right;
}
//---------------------------------------------

//____________Getters__________________________
int Image::GetHeight() const
{
	return m_height;
}
//---------------------------------------------

int Image::GetWidth() const
{
	return m_width;
}
//---------------------------------------------


//____________Private Helpers___________________________
unsigned int Image::get_color() const
{
	return m_pixel;
}
//---------------------------------------------

void Image::set_image_pixel(int x, int y, unsigned char pixel)
{
	m_data[x][y].Set_Color(pixel);
}
//---------------------------------------------

