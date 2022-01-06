#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>
#include <limits>
#include <memory>
#include <iomanip>
using namespace std;

void TestOne();
void TestTwo();
void TestThree();
void TestFour(Vehicle vehicles[]);
void TestFive(Vehicle v[]);
void TestSix(Vehicle v[]);
void TestSeven(Vehicle v[]);


int main()
{
	// Initialize some data. It's hard-coded here, but this data could come from a file, database, etc
	Vehicle vehicles[] =
	{
		Vehicle("Ford", "Mustang", 1973, 9500, 113000),
		Vehicle("Mazda", "CX-5", 2017, 24150, 5900),
		Vehicle("Dodge", "Charger", 2016, 18955, 9018),
		Vehicle("Tesla", "Model S", 2018, 74500, 31),
		Vehicle("Toyota", "Prius", 2015, 17819, 22987),
		Vehicle("Nissan", "Leaf", 2016, 12999, 16889),
		Vehicle("Chevrolet", "Volt", 2015, 16994, 12558),
	};

	// Set the precision for showing prices with 2 decimal places
	cout << std::fixed << std::setprecision(2);

	int testNum;
	cin >> testNum;

	if (testNum == 1)
		TestOne();
	else if (testNum == 2)
		TestTwo();
	else if (testNum == 3)
		TestThree();
	else if (testNum == 4)
		TestFour(vehicles);
	else if (testNum == 5)
		TestFive(vehicles);
	else if (testNum == 6)
		TestSix(vehicles);
	else if (testNum == 7)
		TestSeven(vehicles);
	

	return 0;
}

void TestOne()
{
	// Test the default constructors of all the classes
	Vehicle testVehicle;
	testVehicle.Display();	
}

void TestTwo()
{
	Showroom testShowroom;
	testShowroom.ShowInventory();
}

void TestThree()
{
	Dealership testDealership;
	testDealership.ShowInventory();
}

void TestFour(Vehicle vehicles[])
{
	Showroom one("Test Four Showroom", 2);
	one.AddVehicle(vehicles[2]);
	one.AddVehicle(vehicles[4]);
	one.AddVehicle(vehicles[3]);

	one.ShowInventory();
}
void TestFive(Vehicle vehicles[])
{
	// Showrooms to store the vehicles
	Showroom one("Test Room One", 3);
	one.AddVehicle(vehicles[2]);
	one.AddVehicle(vehicles[6]);
	//showroom.AddVehicle(&vehicles[2]);

	Showroom two("Test Room Two", 4);
	two.AddVehicle(vehicles[1]);
	two.AddVehicle(vehicles[2]);
	two.AddVehicle(vehicles[3]);

	// A "parent" object to store the Showrooms
	Dealership dealership("COP3503 Vehicle Emporium", 2);
	dealership.AddShowroom(one);
	dealership.AddShowroom(two);
	dealership.AddShowroom(two);

	dealership.ShowInventory();
}

void TestSix(Vehicle vehicles[])
{
	// Showrooms to store the vehicles
	Showroom showroom("Primary Showroom", 3);
	showroom.AddVehicle(vehicles[0]);
	showroom.AddVehicle(vehicles[1]);
	//showroom.AddVehicle(&vehicles[2]);

	Showroom secondary("Fuel-Efficient Showroom", 4);
	secondary.AddVehicle(vehicles[3]);
	secondary.AddVehicle(vehicles[4]);
	secondary.AddVehicle(vehicles[5]);
	secondary.AddVehicle(vehicles[6]);

	// A "parent" object to store the Showrooms
	Dealership dealership("COP3503 Vehicle Emporium", 2);
	dealership.AddShowroom(showroom);
	dealership.AddShowroom(secondary);

	dealership.ShowInventory();
}

void TestSeven(Vehicle vehicles[])
{
	// Showrooms to store the vehicles
	Showroom showroom("Primary Showroom", 3);
	showroom.AddVehicle(vehicles[0]);
	showroom.AddVehicle(vehicles[1]);
	showroom.AddVehicle(vehicles[6]);

	Showroom secondary("Fuel-Efficient Showroom", 4);

	secondary.AddVehicle(vehicles[4]);
	secondary.AddVehicle(vehicles[5]);

	Showroom third("Fuel-Efficient Showroom", 4);
	third.AddVehicle(vehicles[3]);
	third.AddVehicle(vehicles[3]);
	third.AddVehicle(vehicles[3]);
	// A "parent" object to store the Showrooms
	Dealership dealership("COP3503 Vehicle Emporium", 3);
	dealership.AddShowroom(showroom);
	dealership.AddShowroom(secondary);
	dealership.AddShowroom(third);

	cout << "Using just the GetAveragePrice() function\n\n";

	cout << "Average price of the cars in the dealership: $";
	cout << dealership.GetAveragePrice();	
}
