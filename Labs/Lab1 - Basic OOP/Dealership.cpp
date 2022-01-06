// Defintion of the Dealership class
#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"

Dealership::Dealership(string name, unsigned int capacity)
{
	dealershipName = name;
	dealerCapacity = capacity;
	showroomsInDealership = {};
}

void Dealership::AddShowroom(const Showroom &s)
{
	if (showroomsInDealership.size() == dealerCapacity)
	{
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else
	{
		showroomsInDealership.push_back(s);
	}
}

float Dealership::GetAveragePrice() const
{
	float total = 0;
	float number = 0;
	int numOfShowrooms = showroomsInDealership.size();
	for (int i = 0; i < numOfShowrooms; i++) //go through each showroom
	{
		int numOfVehicles = showroomsInDealership.at(i).GetVehicleList().size();
		for (int j = 0; j < numOfVehicles; j++) //go through each vehicle in each showroom
		{
			float currentCarPrice = showroomsInDealership.at(i).GetVehicleList().at(j).GetPrice();
			total = total + currentCarPrice;
			number = number + 1.00;
		}
	}

	float avePrice;
	if (number == 0 || total == 0)
	{
		avePrice = 0.00;
	}
	else
	{
		avePrice = (total) / (number);
	}
	return avePrice;
}

void Dealership::ShowInventory() const
{
	int numOfShowrooms = showroomsInDealership.size();
	if (numOfShowrooms == 0) 
	{
		cout << dealershipName << " is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < numOfShowrooms; i++)
		{
			showroomsInDealership.at(i).ShowInventory();
			cout << endl;
		}
	}
	cout << "Average car price: $" << GetAveragePrice() << endl;
}