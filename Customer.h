#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;

using namespace std;

class Customer {
private:
    string name;
    string cnic;
    string mobileNumber;

public:
    Customer(const string& name, const string& cnic, const string& mobile);
    string getName() const;
    string getCNIC() const;
    string getMobileNumber() const;
    void displayInfo() const;
};

#endif // CUSTOMER_H