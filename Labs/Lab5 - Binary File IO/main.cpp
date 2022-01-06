#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Armaments	//to store the data about the number of weapons
{
	unsigned int numWeapons;
	vector<string> weapName;
	vector<int> powerRating;
	vector<float> powerConsumption;
	
	Armaments()
	{
		numWeapons = 0;
		weapName.reserve(1);
		powerRating.reserve(1);
		powerConsumption.reserve(1);
	}

	unsigned int GetNumWeapons()
	{
		return numWeapons;
	}
	string GetWeapNameAt(unsigned int index)
	{
		return weapName[index];
	}
	int GetPowerRatingAt(unsigned int index)
	{
		return powerRating[index];
	}
	int GetMostPowerfulWeaponIndex()
	{
		if (numWeapons > 0)
		{
			unsigned int index = 0;
			int power = 0;
			for (unsigned int i = 0; i < numWeapons; i++)
			{
				if (GetPowerRatingAt(i) > power)
				{
					power = GetPowerRatingAt(i);
					index = i;
				}
			}
			return index;
		}
		else
			return -1;
	}
	float GetPowerConsumptionAt(unsigned int index)
	{
		return powerConsumption[index];
	}
	void PrintArmaments()
	{
		if (numWeapons == 0)
		{
			cout << "Unarmed" << endl;
		}
		else
		{
			int totalFirepower = 0;
			for (unsigned int i = 0; i < numWeapons; i++)
			{
				cout << GetWeapNameAt(i) << ", " << GetPowerRatingAt(i) << ", " << GetPowerConsumptionAt(i) << endl;
				totalFirepower += GetPowerRatingAt(i);
			}
			cout << "Total firepower: " << totalFirepower << endl;
		}
	}
};
class StarshipSearch
{
	unsigned int count;
	vector<string> names;
	vector<string> shipClasses;
	vector<short> lengths;
	vector<int> shieldCaps;
	vector<float> maxWarps;
	vector<Armaments> weapons;
	vector<int> totalFirepowers;
	ifstream file;
public:
	
	StarshipSearch()
	{
		count = 0;
		names.reserve(10);
		shipClasses.reserve(10);
		lengths.reserve(10);
		shieldCaps.reserve(10);
		maxWarps.reserve(10);
		weapons.reserve(10);
		totalFirepowers.reserve(10);
	}

	string ReadInString()
	{
		unsigned int length;
		file.read((char*)&length, 4);
		char* arr = new char[length];
		file.read(arr, length * sizeof(arr[0]));
		string str(arr);
		delete[] arr;
		return str;
	}


	void AddToFromFile(string filepath)
	{
		ifstream file(filepath, ios_base::binary);
		if (file.is_open())
		{
			string s;
			unsigned int numOfShips;
			unsigned int namelength;
			unsigned int classlength;
			short length;
			unsigned int shieldCapacity;
			float warpSpeed;
			file.read((char*)&numOfShips, 4);
			count += numOfShips;
			for (unsigned int i = 0; i < numOfShips; i++)
			{
				//get name of ship
				
				file.read((char*)&namelength, 4);
				char* arr1 = new char[namelength];
				file.read(arr1, namelength * sizeof(arr1[0]));
				s = arr1;
				delete[] arr1;
				names.push_back(s);
				
				//get ship class
				file.read((char*)&classlength, 4);
				char* arr2 = new char[classlength];
				file.read(arr2, classlength * sizeof(arr2[0]));
				s = arr2;
				delete[] arr2;
				shipClasses.push_back(s);

				
				//get ship length
				file.read((char*)&length, 2);
				lengths.push_back(length);

				//get shield capacity
				file.read((char*)&shieldCapacity, 4);
				shieldCaps.push_back(shieldCapacity);

				//get warp speed
				file.read((char*)&warpSpeed, 4);
				maxWarps.push_back(warpSpeed);

				//get weapons
				Armaments arsenal;
				//fill the obj variables
				unsigned int a_count;
				unsigned int s_length;
				int pRating;
				int totalFirepower = 0;
				float pConsumption;
				file.read((char*)&a_count, 4); //read the count
				arsenal.numWeapons = a_count;
				for (unsigned int i = 0; i < a_count; i++)
				{
					file.read((char*)&s_length, 4);
					char* name = new char[s_length];
					file.read(name, s_length * sizeof(name[0]));
					string s_name(name);
					arsenal.weapName.push_back(s_name);
					delete[] name;
					file.read((char*)&pRating, 4);
					totalFirepower += pRating;
					arsenal.powerRating.push_back(pRating);
					file.read((char*)&pConsumption, 4);
					arsenal.powerConsumption.push_back(pConsumption);
				}
				totalFirepowers.push_back(totalFirepower);
				weapons.push_back(arsenal);
			}
		}
		file.close();
	}

	void PrintAllShips()
	{
		for (unsigned int i = 0; i < count; i++)
		{
			PrintShip(i);
		}
	}

	void PrintShip(unsigned int index)
	{
		cout << "Name: " << names[index] << endl;
		cout << "Class: " << shipClasses[index] << endl;
		cout << "Length: " << lengths[index] << endl;
		cout << "Shield capacity: " << shieldCaps[index] << endl;
		cout << "Maximum Warp: " << maxWarps[index] << endl; //does this have to be formatted to a certain number of decimals?
		cout << "Armaments:" << endl;
		weapons[index].PrintArmaments();
		cout << endl;
	}

	void PrintMostPowerfulWeapon()
	{
		unsigned int index = 0;
		int currentPower = 0;
		for (unsigned int i = 0; i < count; i++)
		{
			if (weapons[i].GetMostPowerfulWeaponIndex() > currentPower)
			{
				currentPower = weapons[i].GetPowerRatingAt(weapons[i].GetMostPowerfulWeaponIndex());
				index = i;
			}
		}
		PrintShip(index);
	}
	void PrintMostPowerfulShip()
	{
		unsigned int index = 0;
		int currentFirepower = 0;
		for (unsigned int i = 0; i < count; i++)
		{
			if (totalFirepowers[i] > currentFirepower)
			{
				currentFirepower = totalFirepowers[i];
				index = i;
			}
		}
		PrintShip(index);
	}
	void PrintWeakestArmedShip()
	{
		unsigned int index = 0;
		int currentFirepower = totalFirepowers[0];
		for (unsigned int i = 1; i < count; i++)
		{
			if (totalFirepowers[i] > 0)	//only consider if the ship is armed
			{
				if (totalFirepowers[i] < currentFirepower)
				{
					currentFirepower = totalFirepowers[i];
					index = i;
				}
			}
		}
		PrintShip(index);
	}
	void PrintUnarmed()
	{
		for (unsigned int i = 0; i < count; i++)
		{
			if (totalFirepowers[i] == 0)
			{
				PrintShip(i);
			}
		}
	}
};

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	// Load files here
	StarshipSearch search;
	if (option == 1)
	{
		search.AddToFromFile("friendlyships.shp");
	}
	else if (option == 2)
	{
		search.AddToFromFile("enemyships.shp");
	}
	else
	{
		search.AddToFromFile("friendlyships.shp");
		search.AddToFromFile("enemyships.shp");
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	// Work your magic here
	if (option == 1)
	{
		search.PrintAllShips();
	}
	else if (option == 2)
	{
		search.PrintMostPowerfulWeapon();
	}
	else if (option == 3)
	{
		search.PrintMostPowerfulShip();
	}
	else if (option == 4)
	{
		search.PrintWeakestArmedShip();
	}
	else
	{
		search.PrintUnarmed();
	}
	return 0;
}
