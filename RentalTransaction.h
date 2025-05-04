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
    RentalTransaction(const Customer* cust, const Vehicle* veh, const Date& start, const Date& end);
    const Customer* getCustomer() const;
    const Vehicle* getVehicle() const;
    Date getStartDate() const;
    Date getEndDate() const;
    double getTotalCost() const;
    void displayInfo() const;
};

#endif // RENTALTRANSACTION_H