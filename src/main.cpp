#include "ImageDataStructure.h"
#include "Pixel.h"
#include "Image.h"


int main()
{
	Image image1(4, 4);
	Image image2(5, 5, GREY);
	Image image3(15, 15, BLACK);
	Image image5(image3);
	//std::cout << image3;


	///image5 += image4; // cant understand why it calls the d-tor after completing the task

	//std::cout << image4;

	std::cout << image3 << std::endl;
	std::cout << image5 << std::endl;
	image3 = image3 & image2;
	std::cout << image3 << std::endl;
	std::cout << image5 << std::endl;

	return  0;
}