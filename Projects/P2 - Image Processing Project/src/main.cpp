#include "ImageProcessor.h"

class Tester
{
public:
	bool Compare(string filename1, string filename2)
	{
		ImageProcessor processor;
		processor.readImage(filename1);	//processor.images[0]
		processor.readImage(filename2); //processor.images[1]
		
		// Compare Headers and imagePixels
		if (processor.getImages()[0].getIdLength() != processor.getImages()[1].getIdLength())
			return 0;
		if (processor.getImages()[0].getColorMapType() != processor.getImages()[1].getColorMapType())
			return 0;
		if (processor.getImages()[0].getDataTypeCode() != processor.getImages()[1].getDataTypeCode())
			return 0;
		if (processor.getImages()[0].getColorMapOrigin() != processor.getImages()[1].getColorMapOrigin())
			return 0;
		if (processor.getImages()[0].getColorMapLength() != processor.getImages()[1].getColorMapLength())
			return 0;
		if (processor.getImages()[0].getColorMapDepth() != processor.getImages()[1].getColorMapDepth())
			return 0;
		if (processor.getImages()[0].getXOrigin() != processor.getImages()[1].getXOrigin())
			return 0;
		if (processor.getImages()[0].getYOrigin() != processor.getImages()[1].getYOrigin())
			return 0;
		if (processor.getImages()[0].getWidth() != processor.getImages()[1].getWidth())
			return 0;
		if (processor.getImages()[0].getHeight() != processor.getImages()[1].getHeight())
			return 0;
		if (processor.getImages()[0].getBitsPerPixel() != processor.getImages()[1].getBitsPerPixel())
			return 0;
		if (processor.getImages()[0].getImageDescriptor() != processor.getImages()[1].getImageDescriptor())
			return 0;
		
		if (processor.getImages()[0].getImagePixels().size() != processor.getImages()[0].getImagePixels().size())
			return 0;
		else
		{	
			for (unsigned int i = 0; i < processor.getImages()[0].getImagePixels().size(); i++)	// Go to each Pixel 
			{

				if (processor.getImages()[0].getImagePixels()[i].getRed() != processor.getImages()[1].getImagePixels()[i].getRed())
				{
					cout << "Example Colors:" << endl;
					cout << "exR: " << +processor.getImages()[1].getImagePixels()[i].getRed() << endl;
					cout << "exG: " << +processor.getImages()[1].getImagePixels()[i].getGreen() << endl;
					cout << "exB: " << +processor.getImages()[1].getImagePixels()[i].getBlue() << endl;
					cout << "Your Colors:" << endl;
					cout << "pR: " << +processor.getImages()[0].getImagePixels()[i].getRed() << endl;
					cout << "pG: " << +processor.getImages()[0].getImagePixels()[i].getGreen() << endl;
					cout << "pB: " << +processor.getImages()[0].getImagePixels()[i].getBlue() << endl;
					return 0;
				}	
				if (processor.getImages()[0].getImagePixels()[i].getGreen() != processor.getImages()[1].getImagePixels()[i].getGreen())
				{
					cout << "Example Colors:" << endl;
					cout << "exR: " << +processor.getImages()[1].getImagePixels()[i].getRed() << endl;
					cout << "exG: " << +processor.getImages()[1].getImagePixels()[i].getGreen() << endl;
					cout << "exB: " << +processor.getImages()[1].getImagePixels()[i].getBlue() << endl;
					cout << "Your Colors:" << endl;
					cout << "pR: " << +processor.getImages()[0].getImagePixels()[i].getRed() << endl;
					cout << "pG: " << +processor.getImages()[0].getImagePixels()[i].getGreen() << endl;
					cout << "pB: " << +processor.getImages()[0].getImagePixels()[i].getBlue() << endl;
					return 0;
				}
				if (processor.getImages()[0].getImagePixels()[i].getBlue() != processor.getImages()[1].getImagePixels()[i].getBlue())
				{
					cout << "Example Colors:" << endl;
					cout << "exR: " << +processor.getImages()[1].getImagePixels()[i].getRed() << endl;
					cout << "exG: " << +processor.getImages()[1].getImagePixels()[i].getGreen() << endl;
					cout << "exB: " << +processor.getImages()[1].getImagePixels()[i].getBlue() << endl;
					cout << "Your Colors:" << endl;
					cout << "pR: " << +processor.getImages()[0].getImagePixels()[i].getRed() << endl;
					cout << "pG: " << +processor.getImages()[0].getImagePixels()[i].getGreen() << endl;
					cout << "pB: " << +processor.getImages()[0].getImagePixels()[i].getBlue() << endl;
					return 0;
				}
			}
		}
		return 1;
	}
};

int main()
{
	ImageProcessor processor;
	Tester tester;
	
	// Test 1
	processor.readImage("input/layer1.tga"); //change to "input/car.tga" 
	processor.readImage("input/pattern1.tga");
	processor.Multiply(0, 1);
	processor.writeFile(2, "output/part1.tga"); //change to "output/filename.tga"
	processor.ClearImages();

	// Test 2
	processor.readImage("input/layer2.tga"); //change to "input/car.tga"
	processor.readImage("input/car.tga"); //change to "input/car.tga"
	processor.Subtract(0, 1);
	processor.writeFile(2, "output/part2.tga");
	processor.ClearImages();

	// Test 3
	processor.readImage("input/layer1.tga");
	processor.readImage("input/pattern2.tga");
	processor.Multiply(0, 1); //result is index 2
	processor.readImage("input/text.tga"); //index 3
	processor.Screen(3, 2);	//result is index 4
	processor.writeFile(4, "output/part3.tga");
	processor.ClearImages();

	// Test 4
	processor.readImage("input/layer2.tga"); //change to "input/car.tga"	processor.readImage();
	processor.readImage("input/circles.tga");
	processor.Multiply(0, 1); //result is index 2
	processor.readImage("input/pattern2.tga"); //index 3
	processor.Subtract(3, 2);
	processor.writeFile(4, "output/part4.tga");
	processor.ClearImages();

	// Test 5
	processor.readImage("input/layer1.tga");
	processor.readImage("input/pattern1.tga");
	processor.Overlay(0, 1);	//index 2
	processor.writeFile(2, "output/part5.tga"); //change to "output/filename.tga"
	processor.ClearImages();
	
	// Test 6
	processor.readImage("input/car.tga");
	processor.AddToChannel(0, 0, 200, 0);
	processor.writeFile(1, "output/part6.tga"); //change to "output/filename.tga"
	processor.ClearImages();
	
	// Test 7
	processor.readImage("input/car.tga");
	processor.MultiplyToChannel(0, 4, 1, 0);
	processor.writeFile(1, "output/part7.tga"); //change to "output/filename.tga"
	processor.ClearImages();
	
	// Test 8
	processor.readImage("input/car.tga");
	processor.SeparateIntoChannels(0);
	processor.writeFile(1, "output/part8_r.tga");
	processor.writeFile(2, "output/part8_g.tga");
	processor.writeFile(3, "output/part8_b.tga");
	processor.ClearImages();

	// Test 9
	processor.readImage("input/layer_red.tga");
	processor.readImage("input/layer_green.tga");
	processor.readImage("input/layer_blue.tga");
	processor.CombineChannels(0, 1, 2);
	processor.writeFile(3, "output/part9.tga");
	processor.ClearImages();
	
	// Test 10
	processor.readImage("input/text2.tga");
	processor.Rotate180(0);
	processor.writeFile(1, "output/part10.tga");
	processor.ClearImages();
	
	// Extra Credit
	processor.readImage("input/text.tga");		//image1
	processor.readImage("input/pattern1.tga");	//image2
	processor.readImage("input/car.tga");		//image3
	processor.readImage("input/circles.tga");	//image4
	processor.CreateFourImageCombination(0, 1, 2, 3);
	processor.writeFile(4, "output/extracredit.tga");
	processor.ClearImages();
	
	/*
	bool value;
	
	value = tester.Compare("output/part1.tga", "examples/EXAMPLE_part1.tga");
	if (value == 1)
		cout << "Test #1......Passed!" << endl;
	else
		cout << "Test #1......Failed!" << endl;
	value = tester.Compare("output/part2.tga", "examples/EXAMPLE_part2.tga");
	if (value == 1)
		cout << "Test #2......Passed!" << endl;
	else
		cout << "Test #2......Failed!" << endl;
	value = tester.Compare("output/part3.tga", "examples/EXAMPLE_part3.tga");
	if (value == 1)
		cout << "Test #3......Passed!" << endl;
	else
		cout << "Test #3......Failed!" << endl;
	value = tester.Compare("output/part4.tga", "examples/EXAMPLE_part4.tga");
	if (value == 1)
		cout << "Test #4......Passed!" << endl;
	else
		cout << "Test #4......Failed!" << endl;
	value = tester.Compare("output/part5.tga", "examples/EXAMPLE_part5.tga");
	if (value == 1)
		cout << "Test #5......Passed!" << endl;
	else
		cout << "Test #5......Failed!" << endl;
	value = tester.Compare("output/part6.tga", "examples/EXAMPLE_part6.tga");
	if (value == 1)
		cout << "Test #6......Passed!" << endl;
	else
		cout << "Test #6......Failed!" << endl;
	value = tester.Compare("output/part7.tga", "examples/EXAMPLE_part7.tga");
	if (value == 1)
		cout << "Test #7......Passed!" << endl;
	else
		cout << "Test #7......Failed!" << endl;
	value = tester.Compare("output/part8_r.tga", "examples/EXAMPLE_part8_r.tga");
	if (value == 1)
		cout << "Test #8p1......Passed!" << endl;
	else
		cout << "Test #8p1......Failed!" << endl;
	value = tester.Compare("output/part8_g.tga", "examples/EXAMPLE_part8_g.tga");
	if (value == 1)
		cout << "Test #8p2......Passed!" << endl;
	else
		cout << "Test #8p2......Failed!" << endl;
	value = tester.Compare("output/part8_b.tga", "examples/EXAMPLE_part8_b.tga");
	if (value == 1)
		cout << "Test #8p3......Passed!" << endl;
	else
		cout << "Test #8p3......Failed!" << endl;
	value = tester.Compare("output/part9.tga", "examples/EXAMPLE_part9.tga");
	if (value == 1)
		cout << "Test #9......Passed!" << endl;
	else
		cout << "Test #9......Failed!" << endl;
	value = tester.Compare("output/part10.tga", "examples/EXAMPLE_part10.tga");
	if (value == 1)
		cout << "Test #10......Passed!" << endl;
	else
		cout << "Test #10......Failed!" << endl;
	value = tester.Compare("output/extracredit.tga", "examples/EXAMPLE_extracredit.tga");
	if (value == 1)
		cout << "Test #11......Passed!" << endl;
	else
		cout << "Test #11......Failed!" << endl;
		*/
	return 0;
}