#include "Passenger.h"
#include <iostream>

using namespace std;

Passenger::Passenger(const string &name, const string &address, const string &phoneNumber) : name(name), address(address), phoneNumber(phoneNumber) {}

void Passenger::updateInformation(const string &newAddress, const string &newPhoneNumber) {
  address = newAddress;
  phoneNumber = newPhoneNumber;
  cout << "Updated information for " << name << endl;
}

string Passenger::getName() const {
  return name;
}

string Passenger::getContactInfo() const {
  return address + ", " + phoneNumber;
}