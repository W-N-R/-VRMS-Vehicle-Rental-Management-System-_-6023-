#include "Vehicle.h"

Vehicle::Vehicle(string model, int year, double price)
{
	this->model = model;
	manufacturingYear = year;
	rentalPricePerDay = price;
}

string Vehicle::getModel() const
{
	return model;
}

int Vehicle::getManufacturingYear() const
{
	return manufacturingYear;
}

double Vehicle::getRentalPricePerDay() const
{
	return rentalPricePerDay;
}

bool Vehicle::getAvailability() const
{
	return isAvailable;
}

void Vehicle::setAvailability(bool availability)
{
	isAvailable = availability;
}

void Vehicle::displayInfo() const
{
	
	cout << "\nType: " << getType() << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << manufacturingYear << endl;
	cout << "Daily Rent: " << rentalPricePerDay;
	
}

double Car::calculateRentalCost(int days) const
{
	return days * rentalPricePerDay;
}

string Car::getType() const
{
	return "Car"; 
}

void Car::displayInfo() const
{

	Vehicle::displayInfo();
	cout << endl;

}

double Truck::calculateRentalCost(int days) const
{
   return (days * rentalPricePerDay) + (1.05 * (days * rentalPricePerDay));
}

string Truck::getType() const
{
	return "Truck"; 
}

void Truck::displayInfo() const
{
	Vehicle::displayInfo();
	cout << " (5% commercial tax is not included in it)\n" << endl;
}
