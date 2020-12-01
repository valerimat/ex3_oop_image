#pragma once
#include "macros.h"
#include <iostream>


struct Pixel {
public:
	//C-TORS
	Pixel(unsigned char pixel = ' ');
	void Flip();

	//copy 
	Pixel(const Pixel& pixel);

	//getters
	unsigned char Get_Color() const;

	//scoped opertators
	Pixel& operator=(const Pixel& pixel);
	Pixel& operator|=(const Pixel& pixel);
private:
	
	void Set_Color(unsigned char color);
	
	unsigned char m_color;
};


//global operators


bool operator!=(const Pixel & one, const Pixel &two);
bool operator==(const Pixel& one, const Pixel& two);
bool operator>(const Pixel& one, const Pixel& two);
bool operator<(const Pixel& one, const Pixel& two);
Pixel operator|(const Pixel& one, const Pixel& two);

std::ostream& operator<<(std::ostream&, const Pixel&);