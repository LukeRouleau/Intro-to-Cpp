#pragma once
#include <iostream>
#include <string>
using namespace std;
//Number,Theme,Name,Minifigs,Pieces,USPrice

class LegoSet
{
	string set_number;
	string theme;
	string name;
	unsigned int minifigures;
	unsigned int pieces;
	double price;
public:
	LegoSet();
	LegoSet(string set_number_, string theme_, string name_, unsigned int minifigures_, unsigned int pieces_, double price_);
	getSetNum() const;
	getTheme() const;
	getName() const;
	getMinifig() const;
	getPieces() const;
	getPrice() const;
};
