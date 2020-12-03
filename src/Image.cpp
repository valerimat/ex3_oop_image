#include "Image.h"

// c-tors
Image::Image() :Image(0, 0, WHITE)
{}

Image::Image(int height, int width) : Image(height, width, WHITE)
{}

Image::Image(int height, int width, unsigned char pixel)
{
	m_height = height;
	m_width  = width;
	m_pixel  = pixel; // represents color { white, grey, black }

	m_image = new Pixel *[m_height];

	for (int i = 0; i < m_height; ++i)
		m_image[i] = new Pixel[m_width];

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Pixel temp(pixel);

			m_image[i][j] = temp;
		}
	}
}

// copy c-tor
Image::Image(const Image &other)
{
	m_height = other.m_height;
	m_width  = other.m_width;
	m_pixel  = other.m_pixel; // represents color { white, grey, black }

	m_image = new Pixel * [m_height];

	for (int i = 0; i < m_height; ++i)
		m_image[i] = new Pixel[m_width];

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Pixel temp(m_pixel);

			m_image[i][j] = temp;
		}
	}
}

// d-tor
Image::~Image()
{
	for (int i = 0; i < m_height; i++)
	{
		delete m_image[i];
	}

	delete [] m_image;

	std::cout << "Fuck u fuck u\n";
}

std::ostream &operator<<(std::ostream &stream, const Image &image)
{
	for (int i = 0; i < image.get_height(); i++)
	{
		for (int j = 0; j < image.get_width(); j++)
		{
			stream << (char)image.get_color();
		}
		stream << std::endl;
	}
	return stream;
}


bool operator==(const Image &left, const Image &right) 
{
	if (left.get_height() != right.get_height() || left.get_width() != right.get_width() ||
		left.get_color() != right.get_color())
		return false;
}

bool operator!=(const Image &left, const Image &right)
{
	return !(left == right);
}

Image &Image::operator=(const Image &other)
{
	for (int i = 0; i < m_height; i++)
	{
		delete m_image[i];
	}

	delete[] m_image;

	m_height = other.get_height();
	m_width = other.get_width();
	m_pixel = other.get_color();

	m_image = new Pixel * [m_height];

	for (int i = 0; i < m_height; ++i)
		m_image[i] = new Pixel[m_width];

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Pixel temp(m_pixel);

			m_image[i][j] = temp;
		}
	}

	return *this;
}

Image Image::operator+(const Image &other)
{
	int new_height = this->get_height() + other.get_height();
	int new_width  = this->get_width() +  other.get_width();

	Image new_image(new_height, new_width);

	for (int i = 0; i < this->get_height(); i++)
	{
		for (int j = 0; j < this->get_height(); j++)
		{
			new_image.set_image_pixel(i, j, this->get_color());
			std::cout << "we print the axis:" << i << " " << j << std::endl;
		}
	}

	for (int i = 0; i < other.get_height(); i++)
	{
		for (int j = this->get_width(); j < new_width; j++)
		{
			new_image.set_image_pixel(i, j, other.get_color());
			std::cout << "we print the axis:" << i << " " << j << std::endl;
		}
	}

	return new_image;
}

int Image::get_height() const
{
	return m_height;
}

int Image::get_width() const
{
	return m_width;
}

unsigned int Image::get_color() const
{
	return m_pixel;
}

void Image::set_image_pixel(int x, int y, unsigned char pixel)
{
	m_image[x][y].Set_Color(pixel);
}

void Image::print_image() const
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			std::cout << m_image[i][j].Get_Color();
		}
		std::cout << std::endl;
	}
}