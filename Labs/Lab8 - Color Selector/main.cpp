#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
	ifstream file(filename);
	string storage;
	if (file.is_open())
	{
		while (getline(file, storage, ' '))
		{
			Color color;
			color.SetName(storage.c_str());
			getline(file, storage);
			color.SetValue(stoi(storage));
			colors.emplace(color.GetName(), color);
		}
		file.close();
	}
}
void PrintColors(const map<string, Color>& colors)
{
	auto iter = colors.begin();
	for (;iter != colors.end(); iter++)
	{
		PrintColor(iter->second);
	}
	cout << "Number of colors: " << colors.size();
}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	string input;
	cin >> input;
	auto iter = colors.find(input);
	if (iter != colors.end())
		PrintColor(iter->second);
	else
		cout << input << " not found!" << endl;
}
