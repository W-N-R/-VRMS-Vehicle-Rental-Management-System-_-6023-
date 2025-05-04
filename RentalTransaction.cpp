#include "RentalTransaction.h"

RentalTransaction::RentalTransaction(const Customer* cust, const Vehicle* veh, const Date& start, const Date& end)
{
	customer = cust;
	vehicle = veh;
	rentalStartDate = start;
	rentalEndDate = end;
	int days = rentalEndDate - rentalStartDate; 
	totalCost = vehicle->calculateRentalCost(days);
}

const Customer* RentalTransaction::getCustomer() const
{
	return customer;
}

const Vehicle* RentalTransaction::getVehicle() const
{
	return vehicle;
}

Date RentalTransaction::getStartDate() const
{
	return rentalStartDate;
}

Date RentalTransaction::getEndDate() const
{
	return rentalEndDate;
}

double RentalTransaction::getTotalCost() const
{
	return totalCost;
}

void RentalTransaction::displayInfo() const
{
	cout << "Rental Transaction:" << endl;
	customer->displayInfo();
	vehicle->displayInfo();
	cout << "Start Date: " << rentalStartDate << endl;
	cout << "End Date: " << rentalEndDate << endl;
	cout << "Total Cost: " << totalCost << endl;
}