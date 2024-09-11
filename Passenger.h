#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

using namespace std;

class Passenger {
private:
  string name;
  string address;
  string phoneNumber;

public:
  Passenger(const string &name, const string &address, const string &phoneNumber);
  void updateInformation(const string &address, const string &phoneNumber);
  string getName() const;
  string getContactInfo() const;
};

#endif // PASSENGER_H