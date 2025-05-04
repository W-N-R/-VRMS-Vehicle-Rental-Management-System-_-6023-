#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "RentalTransaction.h"
#include "List.h"
#include "Date.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Vehicle Rental Management System ===" << endl;
    cout << "1. Book a Vehicle" << endl;
    cout << "2. Search Vehicle by Model" << endl;
    cout << "3. Filter Vehicles by Price Range" << endl;
    cout << "4. Show Rental History by Customer CNIC" << endl;
    cout << "5. Add New Customer" << endl;
    cout << "6. Show All Available Vehicles" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice (1-7): ";
}

void initializeSampleData(List<Vehicle*>& vehicles, List<Customer*>& customers) {
    // Add sample vehicles
    vehicles.add(new Car("Honda Civic", 2020, 4000));
    vehicles.add(new Truck("Ford F150", 2018, 5000));
    vehicles.add(new Car("Toyota Corolla", 2019, 3500));
    vehicles.add(new Truck("Mazda Titan", 2021, 7000));

    // Add sample customers
    customers.add(new Customer("Ali Khan", "12345-6789012-3", "0300-1234567"));
    customers.add(new Customer("Sara Ahmed", "98765-4321098-7", "0312-7654321"));
}

void showAvailableVehicles(const List<Vehicle*>& vehicles) {
    cout << "\n=== Available Vehicles ===" << endl;
    bool availableFound = false;
    for (int i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getAvailability()) {
            cout << i << ". ";
            vehicles[i]->displayInfo();
            availableFound = true;
        }
    }
    if (!availableFound) {
        cout << "No vehicles currently available." << endl;
    }
}

void bookVehicle(List<Vehicle*>& vehicles, List<Customer*>& customers, List<RentalTransaction*>& transactions) {
    showAvailableVehicles(vehicles);
    if (vehicles.size() == 0) return;

    cout << "\nEnter vehicle number to book: ";
    int vehicleIndex;
    cin >> vehicleIndex;
    cin.ignore();

    if (vehicleIndex < 0 || vehicleIndex >= vehicles.size()) {
        cout << "Invalid vehicle selection!" << endl;
        return;
    }

    if (!vehicles[vehicleIndex]->getAvailability()) {
        cout << "Selected vehicle is not available!" << endl;
        return;
    }

    cout << "Enter customer CNIC: ";
    string cnic;
    getline(cin, cnic);

    // Find customer
    Customer* customer = nullptr;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i]->getCNIC() == cnic) {
            customer = customers[i];
            break;
        }
    }

    if (!customer) {
        cout << "Customer not found! Please add customer first." << endl;
        return;
    }

    Date startDate, endDate;
    cout << "Enter rental start date (DD/MM/YYYY): ";
    cin >> startDate;
    cout << "Enter rental end date (DD/MM/YYYY): ";
    cin >> endDate;

    if (endDate < startDate) {
        cout << "Error: End date must be after start date!" << endl;
        return;
    }

    transactions.add(new RentalTransaction(customer, vehicles[vehicleIndex], startDate, endDate));
    vehicles[vehicleIndex]->setAvailability(false);

    cout << "\nBooking confirmed!" << endl;
    cout << "Customer: " << customer->getName() << endl;
    cout << "Vehicle: " << vehicles[vehicleIndex]->getModel() << endl;
    cout << "Period: " << startDate << " to " << endDate << endl;
    cout << "Total cost: " << vehicles[vehicleIndex]->calculateRentalCost(endDate - startDate) << endl;
}

void searchVehicleByModel(const List<Vehicle*>& vehicles) {
    cout << "Enter model to search: ";
    string model;
    getline(cin, model);

    cout << "\n=== Search Results ===" << endl;
    bool found = false;
    for (int i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getModel().find(model) != string::npos) {
            vehicles[i]->displayInfo();
            cout << "Status: " << (vehicles[i]->getAvailability() ? "Available" : "Rented") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No vehicles found with that model." << endl;
    }
}

void filterVehiclesByPrice(const List<Vehicle*>& vehicles) {
    double minPrice, maxPrice;
    cout << "Enter minimum price: ";
    cin >> minPrice;
    cout << "Enter maximum price: ";
    cin >> maxPrice;
    cin.ignore();

    if (minPrice < 0 || maxPrice < 0 || minPrice > maxPrice) {
        cout << "Invalid price range!" << endl;
        return;
    }

    cout << "\n=== Vehicles in Price Range ===" << endl;
    bool found = false;
    for (int i = 0; i < vehicles.size(); i++) {
        double price = vehicles[i]->getRentalPricePerDay();
        if (price >= minPrice && price <= maxPrice) {
            vehicles[i]->displayInfo();
            cout << "Status: " << (vehicles[i]->getAvailability() ? "Available" : "Rented") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No vehicles found in that price range." << endl;
    }
}

void showRentalHistory(const List<RentalTransaction*>& transactions) {
    cout << "Enter customer CNIC: ";
    string cnic;
    getline(cin, cnic);

    cout << "\n=== Rental History ===" << endl;
    bool found = false;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i]->getCustomer()->getCNIC() == cnic) {
            transactions[i]->displayInfo();
            cout << "-----------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No rental history found for that customer." << endl;
    }
}

void addNewCustomer(List<Customer*>& customers) {
    string name, cnic, mobile;
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter customer CNIC: ";
    getline(cin, cnic);
    cout << "Enter customer mobile number: ";
    getline(cin, mobile);

    // Check if customer already exists
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i]->getCNIC() == cnic) {
            cout << "Customer with this CNIC already exists!" << endl;
            return;
        }
    }

    customers.add(new Customer(name, cnic, mobile));
    cout << "Customer added successfully!" << endl;
}

int main() {
    List<Vehicle*> vehicles(100);
    List<Customer*> customers(50);
    List<RentalTransaction*> transactions(200);

    initializeSampleData(vehicles, customers);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1:
            bookVehicle(vehicles, customers, transactions);
            break;
        case 2:
            searchVehicleByModel(vehicles);
            break;
        case 3:
            filterVehiclesByPrice(vehicles);
            break;
        case 4:
            showRentalHistory(transactions);
            break;
        case 5:
            addNewCustomer(customers);
            break;
        case 6:
            showAvailableVehicles(vehicles);
            break;
        case 7:
            cout << "Exiting system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 7);

    // Clean up memory
    for (int i = 0; i < vehicles.size(); i++) {
        delete vehicles[i];
    }
    for (int i = 0; i < customers.size(); i++) {
        delete customers[i];
    }
    for (int i = 0; i < transactions.size(); i++) {
        delete transactions[i];
    }

    return 0;
}