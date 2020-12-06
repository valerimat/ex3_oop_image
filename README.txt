================================== EX03-OOP ===================================
                  ___           ___           ___           ___     
      ___        /\__\         /\  \         /\  \         /\  \    
     /\  \      /::|  |       /::\  \       /::\  \       /::\  \   
     \:\  \    /:|:|  |      /:/\:\  \     /:/\:\  \     /:/\:\  \  
     /::\__\  /:/|:|__|__   /::\~\:\  \   /:/  \:\  \   /::\~\:\  \ 
  __/:/\/__/ /:/ |::::\__\ /:/\:\ \:\__\ /:/__/_\:\__\ /:/\:\ \:\__\
 /\/:/  /    \/__/~~/:/  / \/__\:\/:/  / \:\  /\ \/__/ \:\~\:\ \/__/
 \::/__/           /:/  /       \::/  /   \:\ \:\__\    \:\ \:\__\  
  \:\__\          /:/  /        /:/  /     \:\/:/  /     \:\ \/__/  
   \/__/         /:/  /        /:/  /       \::/  /       \:\__\    
                 \/__/         \/__/         \/__/         \/__/
                                                            

name: Valeri Materman
name: David Yudin

===============================================================================
In this exercise we were asked to implement Image drawers
Each Image will consist of pixel, each pixel will have color - white or black or grey.
The assci symbol for each color are placed in the macros .h file
For those images and pixels we are asked to iplement few operartors:

Pixel:
P1==P2 P1!=P2 - comparison of 2 pixels based on color

<<P1 -Print of pixel to the stream

P1|P2 P1|=P2- if the pixels are equal will return same pixel, if they are diffrent will return the
pixle with the darker color.

P1&P2 P1&=P2- if the pixels are equal will return same pixel, if they are diffrent will return the
pixle with the lighter color.

Image:
A1==A2 A1!=A2 - equal images are the images which are of the same size and theyr pixels are of the
same color

A1=A2 - deep copying value of a2 into a1

A+B A+=B- sum of 2 images will result an image with the size max(height_a, height_b),
width_a+ width_b the empty spots will be colored in white, frist we "draw" the 
left image then near it we will draw the right image

<<A - printing image to the ostream

A|B A=|B - the result will be image with the size of max(height_a, height_b) and
max(width_a, width_b), we put one image on the other, the places where the images 
overlap, the color will be based on the | operator in the pixels;

A&B A=&B - the result will be image with the size of min(height_a, height_b) and
min(width_a, width_b), we put one image on the other, the places where the images 
overlap, the color will be based on the | operator in the pixels;

A*n n*A A*=n- multiplication by sclara - will result A+A+A n times

~A - will result an inverted image black will become white and white will become black

A(x,y) - will return the pixel with the coordinates x, y

GetWidth - return image width
GetHeight - returns image height
===============================================================================
Design:
We will be using 3 main classes:
ImageDataStructure - that will handle all the memory allocation
Image- which will be constructed of pixels that are placed on our DataStruct
Pixels - which will have colors.

Once the Image is ready to build it will ask the ImageDataStructure for memory 
and will fill it with pixels
Once the Image dies it will ask the ImageDataStructure to destroy it.


===============================================================================
classes and theyr uses:
---------main objets:
_________Image.cpp + .h_________
* Stores the image data structure
* Definition of all the diff kinds of the opertaors as explained above

_________Pixel.cpp + .h_________
* Defines a single pixel - Pixel is defined by its color
* Stores the defenitions of all the operators as explained above.

_________ImageDataStructure .cpp + .h_________
* Defines a data structure to store image
* Handles the memory allocation and frees.

_________macros .cpp + .h_________
* stores the consts and global functions

===============================================================================
The Main data structure:
ImageDataStructure stores the data in a doubl pointer  array of pixels allocated 
on the heap.

===============================================================================
Agoithms:
None
Bugs:
None


enjoy the images :)

