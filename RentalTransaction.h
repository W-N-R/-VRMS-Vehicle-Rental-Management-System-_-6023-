#ifndef RENTALTRANSACTION_H
#define RENTALTRANSACTION_H

#include "Vehicle.h"
#include "Customer.h"
#include "Date.h"
#include <string>

using namespace std;

class RentalTransaction {
private:
    const Customer* customer;
    const Vehicle* vehicle;
    Date rentalStartDate;
    Date rentalEndDate;
    double totalCost;

public:
    RentalTransaction(const Customer* cust, const Vehicle* veh,
        const Date& start, const Date& end)
        : customer(cust), vehicle(veh),
        rentalStartDate(start), rentalEndDate(end) {
        int days = rentalEndDate - rentalStartDate; // Using overloaded operator
        totalCost = vehicle->calculateRentalCost(days);
    }

    const Customer* getCustomer() const { return customer; }
    const Vehicle* getVehicle() const { return vehicle; }
    Date getStartDate() const { return rentalStartDate; }
    Date getEndDate() const { return rentalEndDate; }
    double getTotalCost() const { return totalCost; }

    void displayInfo() const {
        cout << "Rental Transaction:" << endl;
        customer->displayInfo();
        vehicle->displayInfo();
        cout << "Start Date: " << rentalStartDate << endl;
        cout << "End Date: " << rentalEndDate << endl;
        cout << "Total Cost: " << totalCost << endl;
    }
};

#endif // RENTALTRANSACTION_H