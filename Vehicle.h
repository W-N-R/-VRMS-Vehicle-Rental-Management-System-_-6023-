#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <iomanip> 


using namespace std;

class Vehicle {
protected:
    string model;
    int manufacturingYear;
    double rentalPricePerDay;
    bool isAvailable;

public:
    Vehicle(string model, int year, double price);
    virtual ~Vehicle() {}
    virtual double calculateRentalCost(int days) const = 0;
    virtual string getType() const = 0;
    //getters aa gay------
    string getModel() const;
    int getManufacturingYear() const;
    double getRentalPricePerDay() const;
    bool getAvailability() const;
    // Setters aa gay-----
    void setAvailability(bool availability);
    virtual void displayInfo() const;
};

class Car : public Vehicle {
public:
    Car(string model, int year, double price)
        : Vehicle(model, year, price) {
    }
    double calculateRentalCost(int days) const override;
    string getType() const override;

    void displayInfo() const override;
};

class Truck : public Vehicle {
public:
    Truck(const string& model, int year, double price)
        : Vehicle(model, year, price) {
    }

    double calculateRentalCost(int days) const override;
    string getType() const override;
    void displayInfo() const override;
};

#endif // VEHICLE_H