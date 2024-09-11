#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

// Define ANSI escape code for yellow text
const char *YELLOW = "\033[1;33m";
const char *RESET = "\033[0m";

int main() {
  Database *db = new Database();

  // Create multiple Flight objects and add them to the database
  Flight flight1("FL123", "New York", "Paris", "2023-05-01 10:00");
  Flight flight2("FL456", "Chicago", "Berlin", "2023-05-02 11:00");
  db->addFlight(flight1);
  db->addFlight(flight2);

  // Booking seats with different passengers on the first flight
  db->searchFlightByNumber("FL123")->bookSeat(
      1, Passenger("John Doe", "123 Main St", "555-1234"));
  db->searchFlightByNumber("FL123")->bookSeat(
      2, Passenger("Jane Smith", "456 Elm St", "555-5678"));
  db->searchFlightByNumber("FL123")->bookSeat(
      3, Passenger("Alice Johnson", "789 Pine St", "555-9012"));
  db->searchFlightByNumber("FL123")->bookSeat(
      4, Passenger("Bob Lee", "321 Oak St", "555-3456"));
  db->searchFlightByNumber("FL123")->bookSeat(
      7, Passenger("Eva Long", "210 Birch St", "555-8765"));
  db->searchFlightByNumber("FL123")->bookSeat(
      8, Passenger("Frank Poe", "123 Aspen St", "555-2345"));
  db->searchFlightByNumber("FL123")->bookSeat(
      9, Passenger("Grace Hopper", "456 Redwood St", "555-5679"));
  db->searchFlightByNumber("FL123")->bookSeat(
      10, Passenger("Henry Ford", "789 Sequoia St", "555-6789"));

  cout << " first : " << endl;
  db->searchFlightByNumber("FL123")->printManifestBySeat();

  db->searchFlightByNumber("FL123")->cancelSeat(1);

  cout << " after : " << endl;
  db->searchFlightByNumber("FL123")->printManifestBySeat();

  // Displaying all flights
  cout << YELLOW << "All Flights:" << RESET << endl;
  db->displayAllFlights();

  // Displaying flight details specifically
  db->searchFlightByNumberDisplayInfo("FL123");

  // Optionally, remove a flight and display all flights again
  if (db->removeFlight("FL456")) {
    cout << "Flight FL456 has been removed." << endl;
  }
  cout << YELLOW << "Updated Flight List:" << RESET << endl;
  db->displayAllFlights();

  // now we will use a breadth first search to find path between two cities
  db->addFlight(Flight("FL001", "New York", "Los Angeles", "2023-06-01 09:00"));
  db->addFlight(Flight("FL002", "Los Angeles", "Chicago", "2023-06-01 11:00"));
  db->addFlight(Flight("FL003", "New York", "Miami", "2023-06-01 12:00"));
  db->addFlight(Flight("FL004", "Miami", "Houston", "2023-06-01 13:00"));
  db->addFlight(Flight("FL005", "Houston", "Denver", "2023-06-01 14:00"));
  db->addFlight(Flight("FL006", "Denver", "Seattle", "2023-06-01 15:00"));
  db->addFlight(
      Flight("FL007", "Seattle", "San Francisco", "2023-06-01 16:00"));
  db->addFlight(
      Flight("FL008", "San Francisco", "Las Vegas", "2023-06-01 17:00"));
  db->addFlight(Flight("FL009", "Las Vegas", "Phoenix", "2023-06-01 18:00"));
  db->addFlight(Flight("FL010", "Phoenix", "Dallas", "2023-06-01 19:00"));
  db->addFlight(Flight("FL011", "Dallas", "Atlanta", "2023-06-02 09:00"));
  db->addFlight(
      Flight("FL012", "Atlanta", "Washington D.C.", "2023-06-02 10:00"));
  db->addFlight(
      Flight("FL013", "Washington D.C.", "Boston", "2023-06-02 11:00"));
  db->addFlight(Flight("FL014", "Boston", "Philadelphia", "2023-06-02 12:00"));
  db->addFlight(
      Flight("FL015", "Philadelphia", "New York", "2023-06-02 13:00"));
  db->addFlight(Flight("FL016", "Chicago", "Toronto", "2023-06-02 14:00"));
  db->addFlight(Flight("FL017", "Toronto", "Montreal", "2023-06-02 15:00"));
  db->addFlight(Flight("FL018", "Montreal", "Ottawa", "2023-06-02 16:00"));
  db->addFlight(Flight("FL019", "Ottawa", "New York", "2023-06-02 17:00"));
  db->addFlight(
      Flight("FL020", "Los Angeles", "San Diego", "2023-06-02 18:00"));
  db->addFlight(Flight("FL021", "San Diego", "Portland", "2023-06-02 19:00"));
  db->addFlight(Flight("FL022", "Portland", "Vancouver", "2023-06-03 09:00"));
  db->addFlight(Flight("FL023", "Vancouver", "Calgary", "2023-06-03 10:00"));
  db->addFlight(Flight("FL024", "Calgary", "Winnipeg", "2023-06-03 11:00"));
  db->addFlight(Flight("FL025", "Winnipeg", "Chicago", "2023-06-03 12:00"));
  db->addFlight(Flight("FL026", "Houston", "New Orleans", "2023-06-03 13:00"));
  db->addFlight(Flight("FL027", "New Orleans", "Orlando", "2023-06-03 14:00"));
  db->addFlight(Flight("FL028", "Orlando", "Charlotte", "2023-06-03 15:00"));
  db->addFlight(Flight("FL029", "Charlotte", "Cleveland", "2023-06-03 16:00"));
  db->addFlight(Flight("FL030", "Cleveland", "New York", "2023-06-03 17:00"));

  string fromCity = "Vancouver";
  string toCity = "Chicago";
  int minFlights = db->findMinFlights(fromCity, toCity);
  cout << "Minimum flights from " << fromCity << " to " << toCity << ": "
       << minFlights << endl;
  string routeDescription = db->findFlightPath(fromCity, toCity);
  cout << "Route from " << fromCity << " to " << toCity << ": "
       << routeDescription << std::endl;

  // Clean up dynamically allocated memory
  delete db;

  return 0;
}