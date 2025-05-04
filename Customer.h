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
    Customer(const string& name, const string& cnic, const string& mobile)
        : name(name), cnic(cnic), mobileNumber(mobile) {
    }

    // Getters
    string getName() const { return name; }
    string getCNIC() const { return cnic; }
    string getMobileNumber() const { return mobileNumber; }

    void displayInfo() const {
        cout << "Name: " << name << ", CNIC: " << cnic
            << ", Mobile: " << mobileNumber << endl;
    }
};

#endif // CUSTOMER_H