#include "ImageDataStructure.h"
#include "Pixel.h"
#include "Image.h"


int main()
{
	Image image1(4, 4);
	Image image2(1, 1, BLACK);
	Image image3(2, 2, BLACK);
	Image image4(image3);
	Image image5 = image4 + image2; // cant understand why it calls the d-tor after completing the task

	std::cout << image4;

	std::cout << image5;

	return  0;
}