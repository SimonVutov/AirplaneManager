# AirplaneManager
- Designed and implemented the AirplaneManager system using C++ with comprehensive application of object-oriented principles such as encapsulation, inheritance, and polymorphism to structure a robust flight management and reservation system. This was part of an academic course on C++.
- Implemented complex data structures and algorithms including a breadth first search graph traversal.
- Employed smart pointers and principles to manage dynamic memory, ensuring leak-free code which enhances reliability and performance of the system through pointers.
Features of AirplaneManager
	1.	Flight Management
	•	Add Flights: Ability to add flight details into the system, including flight number, destination, date, and time.
	•	Remove Flights: Capability to remove flights from the system using the flight number.
	2.	Seat Reservation System
	•	Book Seats: Book specific seats on flights for passengers, recording passenger details.
	•	Cancel Seat Reservations: Cancel specific seat reservations, making them available for future bookings.
	3.	Flight Search and Display
	•	Search by Flight Number: Search for flights using their flight number to view detailed flight information.
	•	Search by Destination: Find all flights going to a specified destination.
	•	Display All Flights: List all flights currently managed by the system, showing comprehensive details including seat reservation statuses.
	4.	Detailed Flight Information
	•	Flight Details: View detailed information for a specific flight, including all seat bookings and available seats.
	•	Print Manifest by Seat: Display a list of all passengers according to their seat assignments.
	•	Print Manifest by Name: Display a list of all passengers sorted by their names.
	5.	Routing and Flight Connections
	•	Minimum Flight Connections: Calculate the minimum number of connecting flights required between two cities.
	•	Flight Route Description: Provide a detailed route description from one city to another, showing all intermediate stops.

Additional Features
	•	Dynamic Memory Management: Ensures efficient management of memory, preventing memory leaks.
	•	Error Handling: Robust error handling to ensure the system behaves gracefully under various scenarios like missing flight data or full flights.
	•	ANSI Color Coding: Utilizes ANSI escape codes to enhance readability of outputs, making it easier to distinguish between different sections of output.
 
# Sample Output from main.cpp
Seat 1 reserved for John Doe
Seat 2 reserved for Jane Smith
Seat 3 reserved for Alice Johnson
Seat 4 reserved for Bob Lee
Seat 7 reserved for Eva Long
Seat 8 reserved for Frank Poe
Seat 9 reserved for Grace Hopper
Seat 10 reserved for Henry Ford
 first : 
Seat 1: John Doe - 123 Main St, 555-1234
Seat 2: Jane Smith - 456 Elm St, 555-5678
Seat 3: Alice Johnson - 789 Pine St, 555-9012
Seat 4: Bob Lee - 321 Oak St, 555-3456
Seat 7: Eva Long - 210 Birch St, 555-8765
Seat 8: Frank Poe - 123 Aspen St, 555-2345
Seat 9: Grace Hopper - 456 Redwood St, 555-5679
Seat 10: Henry Ford - 789 Sequoia St, 555-6789
Reservation for seat 1 cancelled.
 after : 
Seat 2: Jane Smith - 456 Elm St, 555-5678
Seat 3: Alice Johnson - 789 Pine St, 555-9012
Seat 4: Bob Lee - 321 Oak St, 555-3456
Seat 7: Eva Long - 210 Birch St, 555-8765
Seat 8: Frank Poe - 123 Aspen St, 555-2345
Seat 9: Grace Hopper - 456 Redwood St, 555-5679
Seat 10: Henry Ford - 789 Sequoia St, 555-6789
All Flights:
Flight Number: FL123
Destination: Paris
Date and Time: 2023-05-01 10:00
Seat Information:
Seat 1: Available
Seat 2: Reserved
Seat 3: Reserved
Seat 4: Reserved
Seat 5: Available
Seat 6: Available
Seat 7: Reserved
Seat 8: Reserved
Seat 9: Reserved
Seat 10: Reserved
Flight Number: FL456
Destination: Berlin
Date and Time: 2023-05-02 11:00
Seat Information:
Seat 1: Available
Seat 2: Available
Seat 3: Available
Seat 4: Available
Seat 5: Available
Seat 6: Available
Seat 7: Available
Seat 8: Available
Seat 9: Available
Seat 10: Available
Flight Details for FL123:
Flight Number: FL123
Destination: Paris
Date and Time: 2023-05-01 10:00
Seat Information:
Seat 1: Available
Seat 2: Reserved
Seat 3: Reserved
Seat 4: Reserved
Seat 5: Available
Seat 6: Available
Seat 7: Reserved
Seat 8: Reserved
Seat 9: Reserved
Seat 10: Reserved
Printing by seat:
Seat 2: Jane Smith - 456 Elm St, 555-5678
Seat 3: Alice Johnson - 789 Pine St, 555-9012
Seat 4: Bob Lee - 321 Oak St, 555-3456
Seat 7: Eva Long - 210 Birch St, 555-8765
Seat 8: Frank Poe - 123 Aspen St, 555-2345
Seat 9: Grace Hopper - 456 Redwood St, 555-5679
Seat 10: Henry Ford - 789 Sequoia St, 555-6789
Printing by name:
Alice Johnson - Seat 3
Bob Lee - Seat 4
Eva Long - Seat 7
Frank Poe - Seat 8
Grace Hopper - Seat 9
Henry Ford - Seat 10
Jane Smith - Seat 2
Flight FL456 has been removed.
Updated Flight List:
Flight Number: FL123
Destination: Paris
Date and Time: 2023-05-01 10:00
Seat Information:
Seat 1: Available
Seat 2: Reserved
Seat 3: Reserved
Seat 4: Reserved
Seat 5: Available
Seat 6: Available
Seat 7: Reserved
Seat 8: Reserved
Seat 9: Reserved
Seat 10: Reserved
Minimum flights from Vancouver to Chicago: 3
Route from Vancouver to Chicago: Vancouver -> Calgary -> Winnipeg -> Chicago
