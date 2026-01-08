#include "Receptionist.h"

#include <iostream>
using namespace std;

// Constructor
Receptionist::Receptionist(int id, string name, string phone)
    : Person(name, phone), employeeId(id) {}

// Methods
void Receptionist::createBooking(Hotel& hotel, Guest& guest, int nights) {
    cout << "Booking created for " << guest.getName()
         << " for " << nights << " nights.\n";
}

void Receptionist::checkInGuest(Hotel& hotel, Guest& guest) {
    cout << guest.getName() << " has checked in.\n";
}

void Receptionist::checkOutGuest(Hotel& hotel, Guest& guest) {
    cout << guest.getName() << " has checked out.\n";
}

void Receptionist::viewRooms(Hotel& hotel) {
    hotel.showAllRooms();
}

void Receptionist::viewBookings(Hotel& hotel) {
    hotel.showAllBookings();
}

int Receptionist::getEmployeeID() {
    return employeeId;
}
