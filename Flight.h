#ifndef FLIGHT_H
#define FLIGHT_H

#include "Passenger.h"
#include "Seat.h"
#include <string>
#include <vector>

using namespace std;

class Flight {
private:
  string flightNumber;
  vector<Seat> seats;
  string from;        // <- from
  string destination; // <- to
  string dateTime;
  void quickSort(std::vector<Seat> &arr, int low, int high) const;

public:
  Flight(const string &flightNumber, const string &from,
         const string &destination, const string &dateTime);
  void bookSeat(int seatNumber, Passenger passenger);
  void cancelSeat(int seatNumber);
  void displayFlightInfo() const;
  void printManifestBySeat() const;
  void printManifestByName() const;
  string getFlightNumber() const;
  string getFrom() const;
  string getDestination() const;
  string getDateTime() const;
  void setDateTime(const string &dateTime);
  void setFrom(const string &from);
  void setDestination(const string &destination);
  void setFlightNumber(const string &flightNumber);
  void cancelFlight();
};

#endif // FLIGHT_H