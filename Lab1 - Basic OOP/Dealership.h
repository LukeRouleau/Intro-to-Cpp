#pragma once
#include <iostream>
#include <vector>
#include<string>
#include "Vehicle.h"
#include "Showroom.h"

using namespace std;

// Declaration of the Dealership class
class Dealership
{
private:
	// Private stuff goes here: Data members, functions the "outside world" doesn't need to know about
	string dealershipName;
	unsigned int dealerCapacity;
	vector<Showroom> showroomsInDealership;

public:
	// Functions go here, and any public variables, if you're using them (generally you shouldn't)
	// Constructor
	Dealership(string name = "Generic Dealership", unsigned int capacity = 0);

	// Behaviors
	void AddShowroom(const Showroom& s);
	float GetAveragePrice() const;
	void ShowInventory() const;
};