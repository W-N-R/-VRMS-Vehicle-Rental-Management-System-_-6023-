#include "Customer.h"

Customer::Customer(const string& name, const string& cnic, const string& mobile)
{
	this->name = name;
	this->cnic = cnic;
	this->mobileNumber = mobile;
}

string Customer::getName() const
{
	return name;
}

string Customer::getCNIC() const
{
	return cnic;
}

string Customer::getMobileNumber() const
{
	return mobileNumber;
}

void Customer::displayInfo() const
{
	cout << "************************************************"<<endl;
	cout << "Name: " << name << " , CNIC: " << cnic <<" , Mobile Number: " << mobileNumber << endl;
	cout << "************************************************" << endl;
}
