#pragma once
#include <iostream>
using namespace std;

class Pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	Pixel();
	unsigned char getRed();
	unsigned char getGreen();
	unsigned char getBlue();
	void setRed(unsigned char red);
	void setGreen(unsigned char green);
	void setBlue(unsigned char blue);
};