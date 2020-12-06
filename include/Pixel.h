#pragma once
/*
This class will store Pixels and all its essentials
Its operators, members, and functions
*/

//-------------------------------Include section
#include "macros.h"
#include <iostream>


//-------------------------------Class section
struct Pixel {
public:
	//--------C-tors:
	Pixel(unsigned char pixel = ' ');
	
	//--------Copy-C-Tor:
	Pixel(const Pixel& pixel);

	//--------Getters:
	unsigned char Get_Color() const;

	//--------Operators:
	Pixel& operator=(const Pixel& pixel);
	Pixel& operator|=(const Pixel& pixel);

	//--------Helppers:
	void Set_Color(unsigned char color);
	void Flip();

private:
	//--------Members:
	unsigned char m_color;
};


//--------Global Operators:
bool operator!=(const Pixel & one, const Pixel &two);
bool operator==(const Pixel& one, const Pixel& two);
bool operator>(const Pixel& one, const Pixel& two);
bool operator<(const Pixel& one, const Pixel& two);
Pixel operator|(const Pixel& one, const Pixel& two);
Pixel operator&(const Pixel& one, const Pixel& two);
Pixel& operator&=(Pixel& one, const Pixel& two);
std::ostream& operator<<(std::ostream&, const Pixel&);