#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class SetCollection
{
	unsigned int count; //might not be needed size we can just do the size of a vector
	vector<string> setNumbers;
	vector<string> themes;
	vector<string> names;
	vector<unsigned int> minifigures;
	vector<unsigned int> pieces;
	vector<double> price;
public:
	SetCollection();
	void addToFromFile(string filepath);	//add to a set collection even if its empty or already has entries
	void testPrintFile();
	void fullPrint(int index);
	void shortPrint(int index);
	void printTotalNumSets();
	void printMostExpensive();
	void printLargestPieceCount();
	void searchByName();
	void searchByCollection();
	void partCountInfo();
	void priceInfo();
	void minifigureInfo();
	void boughtOneOfEverything();
};

