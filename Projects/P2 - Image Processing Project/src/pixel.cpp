#include "pixel.h"
Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}
unsigned char Pixel::getRed()
{
	return r;
}
unsigned char Pixel::getGreen()
{
	return g;
}
unsigned char Pixel::getBlue()
{
	return b;
}
void Pixel::setRed(unsigned char red)
{
	r = red;
}
void Pixel::setGreen(unsigned char green)
{
	g = green;
}
void Pixel::setBlue(unsigned char blue)
{
	b = blue;
}