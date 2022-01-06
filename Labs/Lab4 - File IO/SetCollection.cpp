#include "SetCollection.h"

SetCollection::SetCollection()
{
	count = 0;
	setNumbers.reserve(700);
	themes.reserve(700);
	names.reserve(700);
	minifigures.reserve(700);
	pieces.reserve(700);
	price.reserve(700);
}

void SetCollection::addToFromFile(string filepath)
{
	ifstream file(filepath);
	if (file.is_open())
	{
		string ignoreHeader;
		getline(file, ignoreHeader);
		string fnumber;
		string ftheme;
		string fname;
		string fminifigures;
		string fpieces;
		string fprice;
		while (getline(file,fnumber,','))
		{
			count++;
			//evaluate a whole line of the file
			getline(file, ftheme, ',');
			getline(file, fname, ',');
			getline(file, fminifigures, ',');
			getline(file, fpieces, ',');
			getline(file, fprice, '\n');
			setNumbers.push_back(fnumber);
			themes.push_back(ftheme);
			names.push_back(fname);
			minifigures.push_back(stoi(fminifigures));
			pieces.push_back(stoi(fpieces));
			price.push_back(stod(fprice));
		}
	}
	file.close();
}
void SetCollection::testPrintFile()
{
	cout << "Number,Theme,Name,Minifigs,Pieces,USPrice" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << setNumbers.at(i) << "," << themes.at(i) << "," << names.at(i) << "," << minifigures.at(i) << "," << pieces.at(i) << "," << price.at(i) << endl;
	}
}
void SetCollection::fullPrint(int index)
{
	cout << "Name: " << names.at(index) << endl;
	cout << "Number: " << setNumbers.at(index) << endl;
	cout << "Theme: " << themes.at(index) << endl;
	cout << "Price: $" << price.at(index) << endl;
	cout << "Minifigures: " << minifigures.at(index) << endl;
	cout << "Piece count:" << pieces.at(index) << endl;
}
void SetCollection::shortPrint(int index)
{
	cout <<  setNumbers.at(index) << " " << names.at(index) << " $" << price.at(index) << endl;
}
void SetCollection::printTotalNumSets()
{
	cout << "Total number of sets: " << count << endl << endl;
}
void SetCollection::printMostExpensive()
{
	int index = 0;
	double value = 0.00;
	for (int i = 0; i < count; i++)
	{
		if (price.at(i) > value)
		{
			value = price.at(i);
			index = i;
		}
	}
	this->fullPrint(index);
}
void SetCollection::printLargestPieceCount()
{
	int index = 0;
	int value = 0;
	for (int i = 0; i < count; i++)
	{
		if (pieces.at(i) > value)
		{
			value = pieces.at(i);
			index = i;
		}
	}
	this->fullPrint(index);
}
void SetCollection::searchByName()
{
	string searchTerm;
	vector<int> indices;
	cout << "Enter a string to search for: \t";
	cin >> searchTerm;
	cout << endl << "Sets matching \"" << searchTerm << "\":" << endl;
	for (int i = 0; i < count; i++)
	{
		if (names.at(i).find(searchTerm) != string::npos)
		{
			indices.push_back(i);
		}
	}
	if (indices.size() == 0)
	{
		cout << "No sets found matching that search term" << endl;
	}
	else
	{
		for (int i = 0; i < indices.size(); i++)
			{
				this->shortPrint(indices.at(i));
			}
	}	
}
void SetCollection::searchByCollection()
{
	string searchTerm;
	vector<int> indices;
	cout << "Enter a string to search for: \t";
	cin >> searchTerm;
	cout << endl << "Sets matching \"" << searchTerm << "\":" << endl;
	for (int i = 0; i < count; i++)
	{
		if (themes.at(i).find(searchTerm) != string::npos)
		{
			indices.push_back(i);
		}
	}
	if (indices.size() == 0)
	{
		cout << "No sets found matching that search term" << endl;
	}
	else
	{
		for (int i = 0; i < indices.size(); i++)
		{
			this->shortPrint(indices.at(i));
		}
	}
}
void SetCollection::partCountInfo()
{
	int average = 0;
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum = sum + pieces.at(i);
	}
	average = (sum / count);
	cout << "Average part count for " << count << " sets: " << average << endl;
}
void SetCollection::priceInfo()
{
	int average = 0;
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum = sum + price.at(i);
	}
	average = (sum / count);
	cout << "Average price information for " << count << " sets: $" << average << endl << endl;
	
	int index = 0;
	double value = price.at(0);
	for (int i = 1; i < count; i++)
	{
		if (price.at(i) < value)
		{
			value = price.at(i);
			index = i;
		}
	}
	cout << "Set with the minimum price:" << endl;
	this->fullPrint(index);
	cout << endl;
	cout << "Set with the maximum price:" << endl;
	this->printMostExpensive();
	cout << endl;
}
void SetCollection::minifigureInfo()
{
	int average = 0;
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum = sum + minifigures.at(i);
	}
	average = (sum / count);
	cout << "Average number of minifigures: " << average << endl;
	cout << "Set with the most minifigures:" << endl;
	int index = 0;
	int value = minifigures.at(0);
	for (int i = 1; i < count; i++)
	{
		if (minifigures.at(i) > value)
		{
			value = minifigures.at(i);
			index = i;
		}
	}
	this->fullPrint(index);
}
void SetCollection::boughtOneOfEverything()
{
	double totalPrice = 0;
	int totalPieces = 0;
	int totalMinifigures = 0;
	for (int i = 0; i < count; i++)
	{
		totalPrice = totalPrice + price.at(i);
		totalPieces = totalPieces + pieces.at(i);
		totalMinifigures = totalMinifigures + minifigures.at(i);
	}
	cout << "It would cost: $" << totalPrice << endl;
	cout << "You would have " << totalPieces << " pieces in your collection" << endl;
	cout << "You would have an army of " << totalMinifigures << " mini-figures!" << endl;
}