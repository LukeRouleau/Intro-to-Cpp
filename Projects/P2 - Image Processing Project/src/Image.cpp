#include "Image.h"

Image::Image()
{
	idLength = 0;
	colorMapType = 0;
	dataTypeCode = 0;
	colorMapOrigin = 0;
	colorMapLength = 0;
	colorMapDepth = 0;
	xOrigin = 0;
	yOrigin = 0;
	width = 0;
	height = 0;
	bitsPerPixel = 0;
	imageDescriptor = 0;
	imagePixels.reserve(10000);
}
void Image::copyHeader(Image& image)
{
	this->idLength = image.getIdLength();
	this->colorMapType = image.getColorMapType();
	this->dataTypeCode = image.getDataTypeCode();
	this->colorMapOrigin = image.getColorMapOrigin();
	this->colorMapLength = image.getColorMapLength();
	this->colorMapDepth = image.getColorMapDepth();
	this->xOrigin = image.getXOrigin();
	this->yOrigin = image.getYOrigin();
	this->width = image.getWidth();
	this->height = image.getHeight();
	this->bitsPerPixel = image.getBitsPerPixel();
	this->imageDescriptor = image.getImageDescriptor();
}
void Image::addPixelToImage(unsigned char r, unsigned char g, unsigned char b)
{
	Pixel pixel;
	pixel.setRed(r);
	pixel.setGreen(g);
	pixel.setBlue(b);
	imagePixels.push_back(pixel);
}
void Image::setIdLength(char length)
{
	idLength = length;
}
void Image::setColorMapType(char type)
{
	colorMapType = type;
}
void Image::setDataTypeCode(char code)
{
	dataTypeCode = code;
}
void Image::setColorMapOrigin(short origin)
{
	colorMapOrigin = origin;
}
void Image::setColorMapLength(short length)
{
	colorMapLength = length;
}
void Image::setColorMapDepth(char depth)
{
	colorMapDepth = depth;
}
void Image::setXOrigin(short x)
{
	xOrigin = x;
}
void Image::setYOrigin(short y)
{
	yOrigin = y;
}
void Image::setWidth(short w)
{
	width = w;
}
void Image::setHeight(short h)
{
	height = h;
}
void Image::setBitsPerPixel(char bpp)
{
	bitsPerPixel = bpp;
}
void Image::setImageDescriptor(char descriptor)
{
	imageDescriptor = descriptor;
}
vector<Pixel>& Image::getImagePixels()
{
	return imagePixels;
}
char Image::getIdLength()
{
	return idLength;
}
char Image::getColorMapType()
{
	return colorMapType;
}
char Image::getDataTypeCode()
{
	return dataTypeCode;
}
short Image::getColorMapOrigin()
{
	return colorMapOrigin;
}
short Image::getColorMapLength()
{
	return colorMapLength;
}
char Image::getColorMapDepth()
{
	return colorMapDepth;
}
short Image::getXOrigin()
{
	return xOrigin;
}
short Image::getYOrigin()
{
	return yOrigin;
}
short Image::getWidth()
{
	return width;
}
short Image::getHeight()
{
	return height;
}
char Image::getBitsPerPixel()
{
	return bitsPerPixel;
}
char Image::getImageDescriptor()
{
	return imageDescriptor;
}