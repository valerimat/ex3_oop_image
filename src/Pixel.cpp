#include "Pixel.h"



//____________C-tors___________________________
Pixel::Pixel(unsigned char pixel) :m_color(pixel)
{};

Pixel::Pixel(const Pixel& pixel)
{
	this->m_color = pixel.Get_Color();
}

//____________Setters___________________________

void Pixel::Set_Color(unsigned char color)
{
	m_color = color;
}

//____________Scoped Ops___________________________
Pixel& Pixel::operator=(const Pixel& pixel) {
	this->Set_Color(pixel.Get_Color());
	return *this;
}

Pixel& Pixel::operator|=(const Pixel& pixel) {
	if (*this == pixel)
		return *this;
	if (*this > pixel)
		return *this;

	//reloading value
	*this = pixel;
	
	return *this;
}



//____________Getters___________________________

unsigned char Pixel::Get_Color() const
{
	return m_color;
}


//____________Helpers___________________________

void Pixel::Flip()
{
	if (m_color == WHITE)
		Set_Color(BLACK);
	if (m_color == BLACK)
		Set_Color(WHITE);
}

//____________Global Ops___________________________
//based on color
bool operator!=(const Pixel& one, const Pixel& two) {

	if (one.Get_Color() != two.Get_Color())
		return true;

	return false;
}

//based on color
bool operator==(const Pixel& one, const Pixel& two) {

	if (one.Get_Color() != two.Get_Color())
		return false;

	return true;
}

//returns true if the color is darker
//false if not
bool operator>(const Pixel& one, const Pixel& two) {

	if ((int)one.Get_Color() > (int)two.Get_Color())
		return true;

	return false;
}

//returns true if the color is lighter
//false if not
bool operator<(const Pixel& one, const Pixel& two) {

	if ((int)one.Get_Color() < (int)two.Get_Color())
		return true;

	return false;
}

//prints pixel to the stream
std::ostream& operator<<(std::ostream& stream, const Pixel& pixel) {
	return stream << pixel.Get_Color();
}

Pixel operator|(const Pixel& one, const Pixel& two) {
	//if qual return the first one
	if (one == two)
		return Pixel(one);

	//return the grayer
	if (one > two)
		return Pixel(one);

	return Pixel(two);

}