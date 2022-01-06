#pragma once
#include <string>
#include <math.h>
#include <map>
using namespace std;
class Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int value;
	string hexValue;
	string name;
public:
	Color();
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
	void SetValue(int val);
	void SetName(const char* n);
};