#include "Color.h"


Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
	value = 0;
	hexValue = "";
	name = "";
}

unsigned char Color::GetR() const
{
	return r;
}

unsigned char Color::GetG() const
{
	return g;
}

unsigned char Color::GetB() const
{
	return b;
}

string Color::GetHexValue() const
{
	return hexValue;
}

string Color::GetName() const
{
	return name;
}

void Color::SetValue(int val)
{
	value = val;
	int shift;
	// Convert to RGB
	b = value & 255;
	shift = pow(2, 8);
	g = ((value - b)/ shift) & 255;
	shift = pow(2, 16);
	r = (((value - b) - g) / shift) & 255;
	// Convert to Hex
	map<int, char> hexMap;
	hexMap.emplace(0, '0');
	hexMap.emplace(1, '1');
	hexMap.emplace(2, '2');
	hexMap.emplace(3, '3');
	hexMap.emplace(4, '4');
	hexMap.emplace(5, '5');
	hexMap.emplace(6, '6');
	hexMap.emplace(7, '7');
	hexMap.emplace(8, '8');
	hexMap.emplace(9, '9');
	hexMap.emplace(10, 'A');
	hexMap.emplace(11, 'B');
	hexMap.emplace(12, 'C');
	hexMap.emplace(13, 'D');
	hexMap.emplace(14, 'E');
	hexMap.emplace(15, 'F');
	string tempHex = "000000";
	tempHex[0] = hexMap[r / 16];
	tempHex[1] = hexMap[r % 16];
	tempHex[2] = hexMap[g / 16];
	tempHex[3] = hexMap[g % 16];
	tempHex[4] = hexMap[b / 16];
	tempHex[5] = hexMap[b % 16];
	hexValue = "0x" + tempHex;
}

void Color::SetName(const char *n)
{
	name = n;
}