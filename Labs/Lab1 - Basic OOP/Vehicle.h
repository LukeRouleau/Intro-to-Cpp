/*===== #include statements go here =====*/
#pragma once
#include <iostream>
#include <string>
/*===== using statements go here =====*/
using namespace std;
class Vehicle
{
private:
	// Private stuff goes here: Data members, functions the "outside world" doesn't need to know about
	string _make;
	string _model;
	unsigned int _year;
	float _price;
	unsigned int _mileage;

public:
	// Functions go here, and any public variables, if you're using them (generally you shouldn't)
	// Default Constructor 
	Vehicle();

	// Initialization Constructor
	Vehicle(string make, string model, unsigned int year, float price, unsigned int mileage);

	// Print out vehicle's details in single line
	void Display() const;

	// Creat and return a string in form "YEAR MAKE MODEL"
	string GetYearMakeModel() const;

	// Return the price
	float GetPrice() const;
};
