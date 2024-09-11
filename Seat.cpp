#include "Seat.h"
#include <iostream>

using namespace std;

Seat::Seat(int seatNumber)
    : seatNumber(seatNumber), isReserved(false), passenger(nullptr) {}

void Seat::reserve(Passenger *newPassenger) {
  if (isReserved)
    cout << "Seat " << seatNumber << " is already reserved." << endl;
  else {
    passenger = newPassenger;
    isReserved = true;
    cout << "Seat " << seatNumber << " reserved for " << passenger->getName()
         << endl;
  }
}

void Seat::cancel() {
  if (isReserved) {
    cout << "Reservation for seat " << seatNumber << " cancelled." << endl;
    isReserved = false;
    passenger = nullptr; // Reset the passenger pointer
  } else {
    cout << "Seat " << seatNumber << " is not reserved." << endl;
  }
}

bool Seat::getIsReserved() const { return isReserved; }

int Seat::getSeatNumber() const { return seatNumber; }