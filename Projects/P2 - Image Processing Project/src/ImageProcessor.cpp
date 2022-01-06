#include "ImageProcessor.h"
#include <algorithm>

ImageProcessor::ImageProcessor()
{
	images.reserve(2);
}
vector<Image>& ImageProcessor::getImages()
{
	return images;
}
void ImageProcessor::readImage(string filename)
{

	ifstream file(filename, ios_base::binary);
	if (file.is_open())
	{
		Image image;
		char  tempIdLength;
		char  tempColorMapType;
		char  tempDataTypeCode;
		short tempColorMapOrigin;
		short tempColorMapLength;
		char  tempColorMapDepth;
		short tempXOrigin;
		short tempYOrigin;
		short tempWidth;
		short tempHeight;
		char  tempBitsPerPixel;
		char  tempImageDescriptor;

		// Read Header
		file.read(&tempIdLength, sizeof(tempIdLength));
		image.setIdLength(tempIdLength);
		file.read(&tempColorMapType, sizeof(tempColorMapType));
		image.setColorMapType(tempColorMapType);
		file.read(&tempDataTypeCode, sizeof(tempDataTypeCode));
		image.setDataTypeCode(tempDataTypeCode);
		file.read((char*)&tempColorMapOrigin, sizeof(tempColorMapOrigin));
		image.setColorMapOrigin(tempColorMapOrigin);
		file.read((char*)&tempColorMapLength, sizeof(tempColorMapLength));
		image.setColorMapLength(tempColorMapLength);
		file.read(&tempColorMapDepth, sizeof(tempColorMapDepth));
		image.setColorMapDepth(tempColorMapDepth);
		file.read((char*)&tempXOrigin, sizeof(tempXOrigin));
		image.setXOrigin(tempXOrigin);
		file.read((char*)&tempYOrigin, sizeof(tempYOrigin));
		image.setYOrigin(tempYOrigin);
		file.read((char*)&tempWidth, sizeof(tempWidth));
		image.setWidth(tempWidth);
		file.read((char*)&tempHeight, sizeof(tempHeight));
		image.setHeight(tempHeight);
		file.read(&tempBitsPerPixel, sizeof(tempBitsPerPixel));
		image.setBitsPerPixel(tempBitsPerPixel);
		file.read(&tempImageDescriptor, sizeof(tempImageDescriptor));
		image.setImageDescriptor(tempImageDescriptor);

		// Read Pixels
		int filePixelLength = image.getWidth() * image.getHeight();
		for (int i = 0; i < filePixelLength; i++)
		{
			char unsigned blue;
			char unsigned green;
			char unsigned red;
			file.read((char*)&blue, sizeof(blue));
			file.read((char*)&green, sizeof(green));
			file.read((char*)&red, sizeof(red));
			image.addPixelToImage(red, green, blue);
		}
		images.push_back(image);

		// Test Print Header
		//this->PrintHeaderInfo();
	}
	file.close();
}
void ImageProcessor::writeFile(int index, string filename)
{
	ofstream file(filename, ios_base::binary);
	if (file.is_open())
	{
		// Write Header
		char tempIdLength = images[index].getIdLength();
		char tempColorMapType = images[index].getColorMapType();
		char tempDataTypeCode = images[index].getDataTypeCode();
		short tempColorMapOrigin = images[index].getColorMapOrigin();
		short tempColorMapLength = images[index].getColorMapLength();
		char tempColorMapDepth = images[index].getColorMapDepth();
		short tempXOrigin = images[index].getXOrigin();
		short tempYOrigin = images[index].getYOrigin();
		short tempWidth = images[index].getWidth();
		short tempHeight = images[index].getHeight();
		char tempBitsPerPixel = images[index].getBitsPerPixel();
		char tempImageDescriptor = images[index].getImageDescriptor();

		file.write(&tempIdLength, sizeof(tempIdLength));
		file.write(&tempColorMapType, sizeof(tempColorMapType));
		file.write(&tempDataTypeCode, sizeof(tempDataTypeCode));
		file.write((char*)&tempColorMapOrigin, sizeof(tempColorMapOrigin));
		file.write((char*)&tempColorMapLength, sizeof(tempColorMapLength));
		file.write(&tempColorMapDepth, sizeof(tempColorMapDepth));
		file.write((char*)&tempXOrigin, sizeof(tempXOrigin));
		file.write((char*)&tempYOrigin, sizeof(tempYOrigin));
		file.write((char*)&tempWidth, sizeof(tempWidth));
		file.write((char*)&tempHeight, sizeof(tempHeight));
		file.write(&tempBitsPerPixel, sizeof(tempBitsPerPixel));
		file.write(&tempImageDescriptor, sizeof(tempImageDescriptor));
		
		// Write Pixels
		for (unsigned int i = 0; i < images[index].getImagePixels().size(); i++)		//will this cause a problem with the imagePixels.reserve? 
		{
			unsigned char r = images[index].getImagePixels()[i].getRed();
			unsigned char g = images[index].getImagePixels()[i].getGreen();
			unsigned char b = images[index].getImagePixels()[i].getBlue();
			file.write((char*)&b, sizeof(b));
			file.write((char*)&g, sizeof(g));
			file.write((char*)&r, sizeof(r));
		}
	}
	file.close();
}
void ImageProcessor::PrintHeaderInfo()
{
	cout << "ID Length: " << +images[0].getIdLength() << endl;
	cout << "Color Map Type: " << +images[0].getColorMapType() << endl;
	cout << "Data Type Code: " << +images[0].getDataTypeCode() << endl;
	cout << "Color Map Origin: " << +images[0].getColorMapOrigin() << endl;
	cout << "Color Map Length: " << +images[0].getColorMapLength() << endl;
	cout << "Color Map Depth: " << +images[0].getColorMapDepth() << endl;
	cout << "X Origin: " << +images[0].getXOrigin() << endl;
	cout << "Y Origin: " << +images[0].getYOrigin() << endl;
	cout << "Width: " << +images[0].getWidth() << endl;
	cout << "Height: " << +images[0].getHeight() << endl;
	cout << "Bits Per Pixel: " << +images[0].getBitsPerPixel() << endl;
	cout << "Image Descriptor: " << +images[0].getImageDescriptor() << endl;
}
void ImageProcessor::ChangeAllPixelValues(int index, unsigned char r, unsigned char g, unsigned char b)
{
	for (unsigned int i = 0; i < images[index].getImagePixels().size(); i++)
	{
		images[index].getImagePixels()[i].setRed(r);
		images[index].getImagePixels()[i].setGreen(g);
		images[index].getImagePixels()[i].setBlue(b);
	}
}
void ImageProcessor::ChangeToRandomColors(int index)
{
	for (unsigned int i = 0; i < images[index].getImagePixels().size(); i++)
	{
		unsigned char r = (rand() % 256);
		unsigned char g = (rand() % 256);
		unsigned char b = (rand() % 256);
		images[index].getImagePixels()[i].setRed(r);
		images[index].getImagePixels()[i].setGreen(g);
		images[index].getImagePixels()[i].setBlue(b);
	}
}
void ImageProcessor::Multiply(int top, int bottom)
{
	if (images[top].getImagePixels().size() == images[bottom].getImagePixels().size())
	{
		Image composite;
		composite.copyHeader(images[top]);
		float compositeValue;
		float tempColor;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned int size = images[top].getImagePixels().size();
		for (unsigned int i = 0; i < size; i++)	//Go to each pixel and perform calculation
		{
			tempColor = ((float)images[top].getImagePixels()[i].getRed()) * (images[bottom].getImagePixels()[i].getRed());
			tempColor = tempColor / 255.0f;
			compositeValue = tempColor + 0.5f;
			r = (unsigned char)compositeValue;

			tempColor = ((float)images[top].getImagePixels()[i].getGreen()) * (images[bottom].getImagePixels()[i].getGreen());
			tempColor = tempColor / 255.0f;
			compositeValue = tempColor + 0.5f;
			g = (unsigned char)compositeValue;

			tempColor = ((float)images[top].getImagePixels()[i].getBlue()) * (images[bottom].getImagePixels()[i].getBlue());
			tempColor = tempColor / 255.0f;
			compositeValue = tempColor + 0.5f;
			b = (unsigned char)compositeValue;
			
			composite.addPixelToImage(r, g, b);
		}
		images.push_back(composite);
	}
}
void ImageProcessor::Subtract(int top, int bottom)	// Bottom - Top
{
	if (images[top].getImagePixels().size() == images[bottom].getImagePixels().size())
	{
		Image composite;
		composite.copyHeader(images[top]);
		float compositeValue;
		float tempColor;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned int size = images[top].getImagePixels().size();
		for (unsigned int i = 0; i < size; i++)
		{
			tempColor = ((float)images[bottom].getImagePixels()[i].getRed()) - ((float)images[top].getImagePixels()[i].getRed());
			if (tempColor < 0)
				tempColor = 0;
			compositeValue = tempColor + 0.5f;
			r = (unsigned char)compositeValue;

			tempColor = ((float)images[bottom].getImagePixels()[i].getGreen()) - ((float)images[top].getImagePixels()[i].getGreen());
			if (tempColor < 0)
				tempColor = 0;
			compositeValue = tempColor + 0.5f;
			g = (unsigned char)compositeValue;

			tempColor = ((float)images[bottom].getImagePixels()[i].getBlue()) - ((float)images[top].getImagePixels()[i].getBlue());
			if (tempColor < 0)
				tempColor = 0;
			compositeValue = tempColor + 0.5f;
			b = (unsigned char)compositeValue;

			composite.addPixelToImage(r, g, b);
		}
		images.push_back(composite);
	}
}
void ImageProcessor::Screen(int top, int bottom)
{
	if (images[top].getImagePixels().size() == images[bottom].getImagePixels().size())
	{
		Image composite;
		composite.copyHeader(images[top]);
		float tempColor;
		float normalizedTop;
		float normalizedBottom;
		float compositeValue;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned int size = images[top].getImagePixels().size();
		for (unsigned int i = 0; i < size; i++)	//Go to each pixel and perform calculation
		{
			normalizedTop = ((float)images[top].getImagePixels()[i].getRed()) / 255.0f;
			normalizedBottom = ((float)images[bottom].getImagePixels()[i].getRed()) / 255.0f;
			tempColor = 1-((1- normalizedTop) * (1- normalizedBottom));
			tempColor = tempColor * 255.0f;
			compositeValue = tempColor + 0.5f;
			r = (unsigned char)compositeValue;

			normalizedTop = ((float)images[top].getImagePixels()[i].getGreen()) / 255.0f;
			normalizedBottom = ((float)images[bottom].getImagePixels()[i].getGreen()) / 255.0f;
			tempColor = 1 - ((1 - normalizedTop) * (1 - normalizedBottom));
			tempColor = tempColor * 255.0f;
			compositeValue = tempColor + 0.5f;
			g = (unsigned char)compositeValue;

			normalizedTop = ((float)images[top].getImagePixels()[i].getBlue()) / 255.0f;
			normalizedBottom = ((float)images[bottom].getImagePixels()[i].getBlue()) / 255.0f;
			tempColor = 1 - ((1 - normalizedTop) * (1 - normalizedBottom));
			tempColor = tempColor * 255.0f;
			compositeValue = tempColor + 0.5f;
			b = (unsigned char)compositeValue;

			composite.addPixelToImage(r, g, b);
		}
		images.push_back(composite);
	}
}
void ImageProcessor::Overlay(int top, int bottom)
{
	if (images[top].getImagePixels().size() == images[bottom].getImagePixels().size())
	{
		int testSum = 0;

		Image composite;
		composite.copyHeader(images[top]);
		float tempColor;
		float normalizedTop;
		float normalizedBottom;
		float compositeValue;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		short sum;
		short middleGraySum = 381;	//value to compare to 
		unsigned int size = images[top].getImagePixels().size();
		for (unsigned int i = 0; i < size; i++)	//Go to each pixel and perform calculation
		{

			sum = (short)images[bottom].getImagePixels()[i].getRed() + (short)images[bottom].getImagePixels()[i].getGreen() + (short)images[bottom].getImagePixels()[i].getBlue();
			if (sum <= middleGraySum)
			{
				normalizedTop = ((float)images[top].getImagePixels()[i].getRed()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getRed()) / 255.0f;
				tempColor = 2 * normalizedTop * normalizedBottom;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				r = (unsigned char)compositeValue;

				normalizedTop = ((float)images[top].getImagePixels()[i].getGreen()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getGreen()) / 255.0f;
				tempColor = 2 * normalizedTop * normalizedBottom;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				g = (unsigned char)compositeValue;

				normalizedTop = ((float)images[top].getImagePixels()[i].getBlue()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getBlue()) / 255.0f;
				tempColor = 2 * normalizedTop * normalizedBottom;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				b = (unsigned char)compositeValue;
			}
			else
			{
				normalizedTop = ((float)images[top].getImagePixels()[i].getRed()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getRed()) / 255.0f;
				tempColor = 1 - 2 * (1 - normalizedTop) * (1 - normalizedBottom);
				if (tempColor < 0)
					tempColor = 0;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				r = (unsigned char)compositeValue;

				normalizedTop = ((float)images[top].getImagePixels()[i].getGreen()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getGreen()) / 255.0f;
				tempColor = 1 - (2 * (1 - normalizedTop) * (1 - normalizedBottom));
				if (tempColor < 0)
					tempColor = 0;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				g = (unsigned char)compositeValue;

				normalizedTop = ((float)images[top].getImagePixels()[i].getBlue()) / 255.0f;
				normalizedBottom = ((float)images[bottom].getImagePixels()[i].getBlue()) / 255.0f;
				tempColor = 1 - (2 * (1 - normalizedTop) * (1 - normalizedBottom));
				if (tempColor < 0)
					tempColor = 0;
				tempColor = tempColor * 255.0f;
				compositeValue = tempColor + 0.5f;
				b = (unsigned char)compositeValue;
			}
			composite.addPixelToImage(r, g, b);
		}
		images.push_back(composite);
	}
}
void ImageProcessor::AddToChannel(int index, unsigned int red, unsigned int green, unsigned int blue)
{
	Image result;
	result.copyHeader(images[index]);
	unsigned int tempColor;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned int size = images[index].getImagePixels().size();
	for (unsigned int i = 0; i < size; i++)
	{
		tempColor = images[index].getImagePixels()[i].getRed() + red;
		if (tempColor <= 255)
			r = (unsigned char)tempColor;
		else
			r = 255;

		tempColor = images[index].getImagePixels()[i].getGreen() + green;
		if (tempColor <= 255)
			g = (unsigned char)tempColor;
		else
			g = 255;

		tempColor = images[index].getImagePixels()[i].getBlue() + blue;
		if (tempColor <= 255)
			b = (unsigned char)tempColor;
		else
			b = 255;
		result.addPixelToImage(r, g, b);
	}
	images.push_back(result);
}
void ImageProcessor::MultiplyToChannel(int index, unsigned int red, unsigned int green, unsigned int blue)
{
	Image result;
	result.copyHeader(images[index]);
	unsigned int tempColor;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned int size = images[index].getImagePixels().size();
	for (unsigned int i = 0; i < size; i++)
	{
		tempColor = images[index].getImagePixels()[i].getRed() * red;
		if (tempColor <= 255)
			r = (unsigned char)tempColor;
		else
			r = 255;

		tempColor = images[index].getImagePixels()[i].getGreen() * green;
		if (tempColor <= 255)
			g = (unsigned char)tempColor;
		else
			g = 255;

		tempColor = images[index].getImagePixels()[i].getBlue() * blue;
		if (tempColor <= 255)
			b = (unsigned char)tempColor;
		else
			b = 255;
		result.addPixelToImage(r, g, b);
	}
	images.push_back(result);
}
void ImageProcessor::SeparateIntoChannels(int index)
{
	Image redChannel;
	Image greenChannel;
	Image blueChannel;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	redChannel.copyHeader(images[index]);
	greenChannel.copyHeader(images[index]);
	blueChannel.copyHeader(images[index]);
	unsigned int size = images[index].getImagePixels().size();
	for (unsigned int i = 0; i < size; i++)	
	{
		r = images[index].getImagePixels()[i].getRed();
		g = images[index].getImagePixels()[i].getGreen();
		b = images[index].getImagePixels()[i].getBlue();
		redChannel.addPixelToImage(r, r, r);
		greenChannel.addPixelToImage(g, g, g);
		blueChannel.addPixelToImage(b, b, b);
	}
	images.push_back(redChannel);
	images.push_back(greenChannel);
	images.push_back(blueChannel);
}
void ImageProcessor::CombineChannels(int redIndex, int greenIndex, int blueIndex)
{
	if (images[redIndex].getImagePixels().size() == images[greenIndex].getImagePixels().size() && images[redIndex].getImagePixels().size() == images[blueIndex].getImagePixels().size())
	{
		Image composite;
		composite.copyHeader(images[redIndex]);
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned int size = images[redIndex].getImagePixels().size();
		for (unsigned int i = 0; i < size; i++)
		{
			r = images[redIndex].getImagePixels()[i].getRed();
			g = images[greenIndex].getImagePixels()[i].getGreen();
			b = images[blueIndex].getImagePixels()[i].getBlue();
			composite.addPixelToImage(r, g, b);
		}
		images.push_back(composite);
	}
}
void ImageProcessor::Rotate180(int index)
{
	Image result;
	result.copyHeader(images[index]);
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned int size = images[index].getImagePixels().size();
	for (unsigned int i = 0; i < size; i++)
	{
		r = images[index].getImagePixels()[i].getRed();
		g = images[index].getImagePixels()[i].getGreen();
		b = images[index].getImagePixels()[i].getBlue();
		result.addPixelToImage(r, g, b);
	}
	reverse(result.getImagePixels().begin(), result.getImagePixels().end());
	images.push_back(result);
}
void ImageProcessor::CreateFourImageCombination(int image1, int image2, int image3, int image4)
{
	Image composite;
	composite.copyHeader(images[image1]);
	composite.setWidth(images[image1].getWidth() * 2);
	composite.setHeight(images[image1].getHeight() * 2);
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
	int position1 = 0;
	int position2 = 0;
	for (int i = 0; i < (composite.getHeight() / 2); i++)
	{
		for (int j = 0; j < (composite.getWidth() / 2); j++)	//Print image 1
		{
			r = images[image1].getImagePixels()[position1].getRed();
			g = images[image1].getImagePixels()[position1].getGreen();
			b = images[image1].getImagePixels()[position1].getBlue();
			composite.addPixelToImage(r, g, b);
			position1++;
		}
		for (int j = (composite.getWidth() / 2); j < composite.getWidth(); j++)	//Print image 2
		{
			r = images[image2].getImagePixels()[position2].getRed();
			g = images[image2].getImagePixels()[position2].getGreen();
			b = images[image2].getImagePixels()[position2].getBlue();
			composite.addPixelToImage(r, g, b);
			position2++;
		}
	}
	position1 = 0;
	position2 = 0;
	for (int i = (composite.getHeight() / 2); i < composite.getHeight(); i++)
	{
		for (int j = 0; j < (composite.getWidth() / 2); j++)	//Print image 3
		{
			r = images[image3].getImagePixels()[position1].getRed();
			g = images[image3].getImagePixels()[position1].getGreen();
			b = images[image3].getImagePixels()[position1].getBlue();
			composite.addPixelToImage(r, g, b);
			position1++;
		}
		for (int j = (composite.getWidth() / 2); j < composite.getWidth(); j++)	//print image 4
		{
			r = images[image4].getImagePixels()[position2].getRed();
			g = images[image4].getImagePixels()[position2].getGreen();
			b = images[image4].getImagePixels()[position2].getBlue();
			composite.addPixelToImage(r, g, b);
			position2++;
		}
	}
	images.push_back(composite);
}
void ImageProcessor::ClearImages()
{
	images.clear();
}