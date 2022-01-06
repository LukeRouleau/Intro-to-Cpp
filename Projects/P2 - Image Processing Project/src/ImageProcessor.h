#pragma once
#include "Image.h"
#include <string>
#include <fstream>

class ImageProcessor
{
	vector<Image> images;
public:
	ImageProcessor();
	vector<Image>& getImages();
	void readImage(string filename);
	void writeFile(int index, string filename);
	void PrintHeaderInfo();
	void ChangeAllPixelValues(int index, unsigned char r, unsigned char g, unsigned char b);
	void ChangeToRandomColors(int index);
	void Multiply(int top, int bottom);
	void Subtract(int top, int bottom);
	void Screen(int top, int bottom);
	void Overlay(int top, int bottom);
	void AddToChannel(int index, unsigned int red, unsigned int green, unsigned int blue);
	void MultiplyToChannel(int index, unsigned int red, unsigned int green, unsigned int blue);
	void SeparateIntoChannels(int index);
	void CombineChannels(int redIndex, int blueIndex, int greenIndex);
	void Rotate180(int index);
	void CreateFourImageCombination(int image1, int image2, int image3, int image4);
	void ClearImages();
};