// Definition of the Showroom class
#include "Vehicle.h"
#include "Showroom.h"

Showroom::Showroom(string name, unsigned int capacity)
{
	showroomName = name;
	maxCapacity = capacity;
	vehiclesInShowroom = {};
}

const vector<Vehicle>& Showroom::GetVehicleList() const
{
	return vehiclesInShowroom;
}

void Showroom::AddVehicle(const Vehicle& v)
{
	if (vehiclesInShowroom.size() == maxCapacity)
	{
		cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
	}
	else
	{
		vehiclesInShowroom.push_back(v);
	}
}

void Showroom::ShowInventory() const
{
	if (vehiclesInShowroom.size() == 0) 
	{
		cout << showroomName << " is empty!" << endl;
	}
	
	else 
	{
		cout << "Vehicles in " << showroomName << endl;
		int numOfVehicles = vehiclesInShowroom.size();
		for (int i = 0; i < numOfVehicles; i++)
		{
			vehiclesInShowroom.at(i).Display();
		}
	}
}
