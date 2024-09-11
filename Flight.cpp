#include "Flight.h"
#include <algorithm>
#include <iostream>

using namespace std;

Flight::Flight(const string &flightNumber, const string &from,
               const string &destination, const string &dateTime)
    : flightNumber(flightNumber), from(from), destination(destination),
      dateTime(dateTime) {
  // Initialize seats, assuming 10 seats per flight
  for (int i = 1; i <= 10; i++) {
    seats.push_back(Seat(i));
  }
}

void Flight::bookSeat(int seatNumber, Passenger passenger) {
  if (seatNumber < 1 || seatNumber > 10)
    cout << "Invalid seat number. Out of bounds." << endl;
  else
    seats[seatNumber - 1].reserve(&passenger);
}

void Flight::cancelSeat(int seatNumber) {
  if (seatNumber < 1 || seatNumber > 10)
    cout << "Invalid seat number. Out of bounds." << endl;
  else
    seats[seatNumber - 1].cancel();
}

void Flight::displayFlightInfo() const {
  cout << "Flight Number: " << flightNumber << endl;
  cout << "Destination: " << destination << endl;
  cout << "Date and Time: " << dateTime << endl;
  cout << "Seat Information:" << endl;
  for (const Seat &seat : seats) {
    cout << "Seat " << seat.getSeatNumber() << ": "
         << (seat.getIsReserved() ? "Reserved" : "Available") << endl;
  }
}

void Flight::printManifestBySeat() const {
  for (const Seat &seat : seats) {
    if (seat.getIsReserved()) {
      cout << "Seat " << seat.getSeatNumber() << ": "
           << seat.getPassenger()->getName() << " - "
           << seat.getPassenger()->getContactInfo() << endl;
    }
  }
}
// partition, quicksort, and printManifestByName work together to perform a
// manual quicksort, and print the list in alphabetical order of name of
// passengers.

// Utility function to perform partition
int partition(vector<Seat> &arr, int low, int high) {
  // Handling the pivot which might be nullptr
  const Seat &pivot = arr[high];
  if (pivot.getPassenger() == nullptr) {
    // You may choose to put all nullptrs at the end or handle this more
    // dynamically.
    return high; // For simplicity, we could decide to just return the high
                 // index.
  }

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (arr[j].getPassenger() == nullptr)
      continue;
    if (arr[j].getPassenger()->getName() < pivot.getPassenger()->getName()) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// QuickSort algorithm
void Flight::quickSort(vector<Seat> &arr, int low, int high) const {
  if (low < high) {
    int pi = partition(arr, low, high);
    // Recursively sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Method to print the manifest sorted by passenger name
void Flight::printManifestByName() const {
  vector<Seat> sortedSeats = seats; // Copy the seats

  // Call quickSort on the whole array
  quickSort(sortedSeats, 0, sortedSeats.size() - 1);
  for (const Seat &seat : sortedSeats) {
    if (seat.getIsReserved()) {
      cout << seat.getPassenger()->getName() << " - Seat "
           << seat.getSeatNumber() << endl;
    }
  }
}

string Flight::getFlightNumber() const { return flightNumber; }
string Flight::getFrom() const { return from; }
string Flight::getDestination() const { return destination; }
string Flight::getDateTime() const { return dateTime; }
void Flight::setFlightNumber(const string &flightNumber) {
  this->flightNumber = flightNumber;
}
void Flight::setFrom(const string &from) { this->from = from; }
void Flight::setDestination(const string &destination) {
  this->destination = destination;
}
void Flight::setDateTime(const string &dateTime) { this->dateTime = dateTime; }

void Flight::cancelFlight() {
  cout << "Flight cancellation with flight number " << flightNumber
       << " has been initiated." << endl;

  // Simply cancel all seat reservations
  for (Seat &seat : seats) {
    seat.cancel();
  }
  // No need to delete anything; the `Flight` object and its `Seat` objects will
  // be destroyed naturally when out of scope or deleted by the owner of
  // `Flight` objects.
}
