#include "Database.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Add a flight to the database
void Database::addFlight(const Flight &flight) { flights.push_back(flight); }

// Remove a flight from the database by flight number
bool Database::removeFlight(const string &flightNumber) {
  auto it =
      find_if(flights.begin(), flights.end(), [&flightNumber](const Flight &f) {
        return f.getFlightNumber() == flightNumber;
      });
  if (it != flights.end()) {
    flights.erase(it);
    return true;
  }
  return false;
}

Flight *Database::searchFlightByNumber(const string &flightNumber) {
  auto it =
      find_if(flights.begin(), flights.end(), [&flightNumber](const Flight &f) {
        return f.getFlightNumber() == flightNumber;
      });
  if (it != flights.end()) {
    return &(*it); // Correctly returns a pointer to a modifiable Flight
  }
  return nullptr;
}

// Search for flights by destination
vector<Flight> Database::searchFlightsByDestination(const string &destination) {
  vector<Flight> foundFlights;
  copy_if(flights.begin(), flights.end(), back_inserter(foundFlights),
          [&destination](const Flight &f) {
            return f.getDestination() == destination;
          });
  return foundFlights;
}

// Display all flights in the database
void Database::displayAllFlights() const {
  if (flights.empty()) {
    cout << "No flights available." << endl;
    return;
  }
  for (const Flight &flight : flights) {
    flight.displayFlightInfo();
  }
}

void Database::searchFlightByNumberDisplayInfo(const string &flightNumber) {
  Flight *f = searchFlightByNumber(flightNumber);
  if (f) {
    const char *YELLOW = "\033[1;33m";
    const char *RESET = "\033[0m";
    cout << YELLOW << "Flight Details for " << flightNumber << ":" << RESET
         << endl;
    f->displayFlightInfo();

    cout << YELLOW << "Printing by seat:" << RESET << endl;
    f->printManifestBySeat();

    cout << YELLOW << "Printing by name:" << RESET << endl;
    f->printManifestByName();
  } else {
    cout << "Flight " << flightNumber << " not found." << endl;
  }
}

int Database::findMinFlights(const string &from, const string &to) {
  if (from == to)
    return 0; // No flights needed if start and destination are the same

  unordered_map<string, vector<string>> graph;
  queue<pair<string, int>>
      queue; // Pair of city and number of flights taken to reach there
  unordered_set<string> visited; // Set to track visited cities

  // Build the graph from the flights database
  for (const auto &flight : flights) {
    graph[flight.getFrom()].push_back(flight.getDestination());
  }

  // Initialize the queue with the starting city
  queue.push({from, 0});
  visited.insert(from);

  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();

    // Process all adjacent cities (destinations)
    for (const auto &adjacent : graph[current.first]) {
      if (adjacent == to) {
        return current.second +
               1; // Return the number of flights to get to 'to'
      }

      // If not visited, add to the queue
      if (visited.find(adjacent) == visited.end()) {
        visited.insert(adjacent);
        queue.push({adjacent, current.second + 1});
      }
    }
  }

  return -1; // Return -1 if no route exists
}

string Database::findFlightPath(const string &from, const string &to) {
  if (from == to)
    return "Start and destination are the same.";

  unordered_map<string, vector<string>> graph;
  queue<pair<string, vector<string>>> queue; // Now stores a vector of paths
  unordered_set<string> visited;

  // Build the graph from the flights database
  for (const auto &flight : flights) {
    graph[flight.getFrom()].push_back(flight.getDestination());
  }

  // Initialize the queue with the starting city
  queue.push({from, {from}});
  visited.insert(from);

  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    string currentCity = current.first;
    vector<string> currentPath = current.second;

    // Process all adjacent cities (destinations)
    for (const auto &adjacent : graph[currentCity]) {
      vector<string> newPath = currentPath;
      newPath.push_back(adjacent);

      if (adjacent == to) {
        // Convert vector path to string for output
        ostringstream pathStream;
        for (size_t i = 0; i < newPath.size(); ++i) {
          if (i > 0)
            pathStream << " -> ";
          pathStream << newPath[i];
        }
        return pathStream.str();
      }

      // If not visited, add to the queue
      if (visited.find(adjacent) == visited.end()) {
        visited.insert(adjacent);
        queue.push({adjacent, newPath});
      }
    }
  }

  return "No route found from " + from + " to " + to + ".";
}
