#include <iostream>
#include <string>
using namespace std;

// Base Class
class User {
public:
    string name;

    User(string n) {
        name = n;
    }
};

// Flight Class
class Flight {
public:
    string flightNo;
    string destination;
    int seats;

    Flight() {
        flightNo = "";
        destination = "";
        seats = 0;
    }

    Flight(string f, string d, int s) {
        flightNo = f;
        destination = d;
        seats = s;
    }

    bool bookSeat() {
        if (seats > 0) {
            seats--;
            return true;
        }
        return false;
    }
};

// Derived Class (Inheritance)
class Passenger : public User {
public:
    string bookings[5];   // Array for storing bookings
    int count;

    Passenger(string n) : User(n) {
        count = 0;
    }

    void bookFlight(Flight &f) {
        if (f.bookSeat()) {
            if (count < 5) {
                bookings[count] = f.flightNo + " to " + f.destination;
                count++;
                cout << "Ticket Booked Successfully!\n";
            }
        } else {
            cout << "Flight is Full!\n";
        }
    }
};

int main() {

    string name;
    cout << "Enter Your Name: ";
    getline(cin, name);

    Passenger p1(name);

    Flight flights[2];
    flights[0] = Flight("AA101", "New York", 2);
    flights[1] = Flight("BA202", "Tokyo", 1);

    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. View Flights\n";
        cout << "2. Book Flight\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << ". "
                     << flights[i].flightNo << " to "
                     << flights[i].destination
                     << " (Seats: " << flights[i].seats << ")\n";
            }
        }

        else if (choice == 2) {
            int num;
            cout << "Select Flight (1 or 2): ";
            cin >> num;

            if (num == 1 || num == 2) {
                p1.bookFlight(flights[num - 1]);
            } else {
                cout << "Invalid Choice!\n";
            }
        }

    } while (choice != 3);

    return 0;
}
