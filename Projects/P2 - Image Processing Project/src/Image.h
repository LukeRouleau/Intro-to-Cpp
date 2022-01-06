#pragma once
#include "pixel.h"
#include <vector>

class Image
{
	char  idLength;
	char  colorMapType;
	char  dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char  colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char  bitsPerPixel;
	char  imageDescriptor;
	vector<Pixel> imagePixels;
public:
	
	Image();
	void copyHeader(Image& image);
	void addPixelToImage(unsigned char r, unsigned char g, unsigned char b);
	void setIdLength(char length);
	void setColorMapType(char type);
	void setDataTypeCode(char code);
	void setColorMapOrigin(short origin);
	void setColorMapLength(short length);
	void setColorMapDepth(char depth);
	void setXOrigin(short x);
	void setYOrigin(short y);
	void setWidth(short w);
	void setHeight(short h);
	void setBitsPerPixel(char bpp);
	void setImageDescriptor(char descriptor);
	vector<Pixel>& getImagePixels();
	char getIdLength();
	char getColorMapType();
	char getDataTypeCode();
	short getColorMapOrigin();
	short getColorMapLength();
	char getColorMapDepth();
	short getXOrigin();
	short getYOrigin();
	short getWidth();
	short getHeight();
	char getBitsPerPixel();
	char getImageDescriptor();
};