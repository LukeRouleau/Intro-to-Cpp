// Definition of the Vehicle class
#include "Vehicle.h"

Vehicle::Vehicle()
{
	_make = "COP3503";
	_model = "Rust Bucket";
	_year = 1900;
	_price = 0.00;
	_mileage = 0;
}

Vehicle::Vehicle(string make, string model, unsigned int year, float price, unsigned int mileage)
{
	_make = make;
	_model = model;
	_year = year;
	_price = price;
	_mileage = mileage;
}

void Vehicle::Display() const
{
	cout << _year << " " << _make << " " << _model << " $" << _price << " " << _mileage << endl;
}

string Vehicle::GetYearMakeModel() const
{
	string yearStr = to_string(_year);
	string totalStr = yearStr + " " + _make + " " + _model;
	return totalStr;
}

float Vehicle::GetPrice() const
{
	return _price;
}
