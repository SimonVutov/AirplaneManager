#ifndef SEAT_H
#define SEAT_H

#include "Passenger.h"

class Seat {
private:
  int seatNumber;
  bool isReserved;
  Passenger *passenger; // Use a pointer to Passenger

public:
  Seat(int seatNumber);
  void reserve(Passenger *passenger); // Change to pointer
  void cancel();
  const Passenger *getPassenger() const { return passenger; }
  bool getIsReserved() const;
  int getSeatNumber() const;
};

#endif // SEAT_H