#ifndef DATABASE_H
#define DATABASE_H

#include "Flight.h" // Make sure this includes all necessary headers for Flight and Passenger classes
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Database {
private:
  vector<Flight> flights; // Collection of flights

public:
  void addFlight(const Flight &flight);
  bool removeFlight(const string &flightNumber);
  Flight *searchFlightByNumber(const std::string &flightNumber);
  vector<Flight> searchFlightsByDestination(const string &destination);
  void displayAllFlights() const;
  void searchFlightByNumberDisplayInfo(const std::string &flightNumber);
  int findMinFlights(const std::string &from, const std::string &to);
  string findFlightPath(const std::string &from, const std::string &to);
};

#endif // DATABASE_H
