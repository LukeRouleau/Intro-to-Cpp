#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //for istringstream
#include <vector>
using namespace std;
/*
Batman,74, Robin
Superman,78,Krypto
Captain America,90,Bucky
Aquaman,45,All the fishes
Iron Man,52,War Machine
*/

class Character
{
	string _name;
	int _age;
	string _sidekick;
public:
	Character(string name, int age, string sidekick)
	{
		_name = name;
		_age = age;
		_sidekick = sidekick;
	}
	string GetName()
	{
		return _name;
	}
	int GetAge()
	{
		return _age;
	}
	string GetSidekick()
	{
		return _sidekick;
	}
};

void ReadCharactersFromFile(string path, vector<Character>& characters);

int main()
{
	vector<Character> characters;

	ReadCharactersFromFile("superheros.csv", characters);	//if I want to read from a specific file location i can do "data/hereos/superheroes.csv"
															// data/etc/etc, that goes INTO a file, you can go out of a file by doing "../../data/setting/superheroes.csv"

	cout << "Number of characters: " << characters.size() << endl;
	for (unsigned int i = 0; i < characters.size(); i++)
	{
		cout << characters[i].GetName() << endl;
		cout << characters[i].GetAge() << endl;
		cout << characters[i].GetSidekick() << endl;
	}
	
	ofstream outFile("heroes_modified.csv");							// lets make a output file
	if (outFile.is_open())
	{
		for (unsigned int i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].GetName() << ',' << characters[i].GetSidekick();
			if (i < characters.size() - 1)								// this prevents us from putting an extra newline character after the last line
				outFile << endl;
		}
	}
	else
	{
		cout << "File not opened, holy fucking shit, lets freak out!!!" << endl; //because the file is open in another program in it cannot write that file
	}
	return 0;
}

void ReadCharactersFromFile(string path, vector<Character> & characters) //output parameter
{
	characters.clear(); //clear output parameter first
	ifstream inFile(path);		 //For Windows, capitalization does not matter at all, for others yes.
	if (inFile.is_open())					 //A check to see if its open
	{
			// 1. Read a line from the file
			string lineFromFile;
			while (getline(inFile, lineFromFile))
			{

				//getline(inFile, lineFromFile); // if you had a header line you didnt want to read, you would have to put an extra getline(inFile, lineFromFile); before and do nothing with

				cout << lineFromFile << endl;
				// 2. Parse the line - break into separate tokens (tokenize)
				/*
				//Several different approaches, we can use substring
				int index = lineFromFile.find_first_of(','); //might not be the best approach, works fine for finding the first piece fo data, but difficult to get the next piece of data
				string hero = lineFromFile.substr(0, index);
				cout << "Hero : " << hero << endl;
				*/

				//Lets use the delimiter option of the getline() function, but first lets make lineFromFile a stringstream
				//create stream from our string
				istringstream stream(lineFromFile);
				string name, sidekick;
				int age;
				
				getline(stream, name, ',');			//get everything up to the indicated delimiter, but not including it

				//now stream == "75,Robin"
				string tempToken;
				getline(stream, tempToken, ',');	//we can overwrite token now because we already printed it
				age = stoi(tempToken);				//possible try catch, if you tried to read a value and there isn't a number there, then it can't convert and will throw an exception

				//stream == "Robin"
				getline(stream, sidekick, ',');
				
				Character c(name, age, sidekick);
				characters.push_back(c);
			}


	}
}