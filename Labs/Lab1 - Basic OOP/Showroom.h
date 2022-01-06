/*===== #include statements go here =====*/
#pragma once
#include <iostream>
#include <vector>
#include<string>
#include "Vehicle.h"

// strings, vectors, anything you need access to
// Also, if since this class needs to know about Vehicle objects... you need to include "Vehicle.h" as well

/*===== using statements go here =====*/
using namespace std;

class Showroom
{
private:
	// Private stuff goes here: Data members, functions the "outside world" doesn't need to know about
	string showroomName;
	vector<Vehicle> vehiclesInShowroom;
	unsigned int maxCapacity;

public:
	// Functions go here, and any public variables, if you're using them (generally you shouldn't)
	// Default constructor
	Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
	//Showroom(string name, unsigned int capacity);


	// Accessor
	const vector<Vehicle>& GetVehicleList() const;

	// Behaviors
	void AddVehicle(const Vehicle& v);
	void ShowInventory() const;
};