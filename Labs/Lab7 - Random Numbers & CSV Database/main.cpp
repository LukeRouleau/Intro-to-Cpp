#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

mt19937 random_mt;

class States
{
	string name;
	int perCapitaIncome;
	int population;
	int medianHHIncome;
	int numOfHH;
public:
	States()
	{
		name = "";
		perCapitaIncome = 0;
		population = 0;
		medianHHIncome = 0;
		numOfHH = 0;
	}
	States(string n, int pcIncome, int pop, int mhhIncome, int hhNum)
	{
		name = n;
		perCapitaIncome = pcIncome;
		population = pop;
		medianHHIncome = mhhIncome;
		numOfHH = hhNum;
	}
	void setName(string n)
	{
		name = n;
	}
	void setPerCapitaIncome(int pcIncome)
	{
		perCapitaIncome = pcIncome;
	}
	void setPopulation(int pop)
	{
		population = pop;
	}
	void setMedianHHIncome(int mhhIncome)
	{
		medianHHIncome = mhhIncome;
	}
	void setNumOfHH(int num)
	{
		numOfHH = num;
	}
	string getName()
	{
		return name;
	}
	int getPerCapitaIncome()
	{
		return perCapitaIncome;
	}
	int getPopulation()
	{
		return population;
	}
	int getMedianHHIncome()
	{
		return medianHHIncome;
	}
	int getNumOfHH()
	{
		return numOfHH;
	}
	void PrintState()
	{
		cout << name << endl;
		cout << "Population: " << population << endl;
		cout << "Per Capita Income: " << perCapitaIncome << endl;
		cout << "Median Household Income: " << medianHHIncome << endl;
		cout << "Number of Households: " << numOfHH << endl << endl;
	}
};

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}
void RollDice(int numberOfRolls, int numberOfSides)
{
	map<int, int> diceMap;
	for (int i = 1; i <= numberOfSides; i++)
		diceMap.emplace(i, 0);

	for (int i = 0; i < numberOfRolls; i++)
	{
		int rollResult = Random(1, numberOfSides);
		diceMap[rollResult]++;
	}
	cout << endl;
	auto iter = diceMap.begin();
	for (; iter != diceMap.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << endl;
	}
	cout << endl;
}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";
		// user input
		int numOfRolls;
		cin >> numOfRolls;
		cout << "Number of sides on this die: ";
		// user input
		int numOfSides;
		cin >> numOfSides;
		  // Roll Dice
		RollDice(numOfRolls, numOfSides);
	}
	else if (option == 2)
	{
		// Load the states
		//auto statesMap = ReadCSV("states.csv");

		map<string, States> statesMap;
		ifstream file("states.csv");
		string data;
		getline(file, data);
		while (getline(file, data, ','))
		{
			States state;
			state.setName(data);
			getline(file, data, ',');
			state.setPerCapitaIncome(stoi(data));
			getline(file, data, ',');
			state.setPopulation(stoi(data));
			getline(file, data, ',');
			state.setMedianHHIncome(stoi(data));
			getline(file, data);
			state.setNumOfHH(stoi(data));
			statesMap.emplace(state.getName(), state);
		}

		auto iter = statesMap.begin();
		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1. Print all states\n";
		cout << "2. Search for a state\n";
		cin >> option;
		if (option == 1)
		{
			for (; iter != statesMap.end(); iter++)
			{
				iter->second.PrintState();
			}
		}
		else if (option == 2)
		{
			string stateName;
			cin >> stateName;
			if (statesMap.find(stateName) != statesMap.end())
			{
				auto iter = statesMap.find(stateName);
				(iter->second).PrintState();
			}
				
			else
				cout << "No match found for " << stateName << "." << endl;
		}
	}

	return 0;
}
