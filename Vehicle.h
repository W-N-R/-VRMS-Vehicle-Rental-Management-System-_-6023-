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
    Vehicle(const string& model, int year, double price)
        : model(model), manufacturingYear(year), rentalPricePerDay(price), isAvailable(true) {
    }

    virtual ~Vehicle() {}

    virtual double calculateRentalCost(int days) const = 0;
    virtual string getType() const = 0;

    // Getters
    string getModel() const { return model; }
    int getManufacturingYear() const { return manufacturingYear; }
    double getRentalPricePerDay() const { return rentalPricePerDay; }
    bool getAvailability() const { return isAvailable; }

    // Setters
    void setAvailability(bool availability) { isAvailable = availability; }

    virtual void displayInfo() const {
        cout << "Type: " << getType() << ", Model: " << model
            << ", Year: " << manufacturingYear
            << ", Daily Rent: " << rentalPricePerDay;
    }
};

class Car : public Vehicle {
public:
    Car(const string& model, int year, double price)
        : Vehicle(model, year, price) {
    }

    double calculateRentalCost(int days) const override {
        return days * rentalPricePerDay;
    }

    string getType() const override { return "Car"; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << endl;
    }
};

class Truck : public Vehicle {
public:
    Truck(const string& model, int year, double price)
        : Vehicle(model, year, price) {
    }

    double calculateRentalCost(int days) const override {
        return (days * rentalPricePerDay) + (1.05* (days * rentalPricePerDay)); // 5% commercial tax
    }

    string getType() const override { return "Truck"; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " (5% commercial tax is not included in it)" << endl;
    }
};

#endif // VEHICLE_H