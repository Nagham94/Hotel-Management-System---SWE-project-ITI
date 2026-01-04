#include "Hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel()
{
    //ctor
}

Hotel::~Hotel()
{
    //dtor
}

void Hotel::addRoom(Room room)
{
    rooms.push_back(room);
}

void Hotel::addBooking(Booking booking)
{
    bookings.push_back(booking);
}

Room* Hotel::findAvailableRoom()
{
    for (auto& room : rooms)
    {
        if(room.checkAvailability())
        {
            return &room;
        }
    }
    return nullptr;
}

void Hotel::showAllRooms()
{
    for (const auto& room : rooms)
    {
        cout << "Room Number: " << room.getRoomNumber() << endl;
        cout << "Type: " << room.getType() << endl;
        cout << "Price per Night: " << room.getPrice() << endl;
        cout << "Available: "
             << (room.checkAvailability() ? "Yes" : "No") << endl;
        cout << "----------------------" << endl;
    }
}
void Hotel::showAllBookings()
{
    for (const auto& booking : bookings)
    {
        cout << "Booking ID: " << booking.getBookingId() << endl;
        cout << "Guest Name: " << booking.getGuest().getName() << endl;
        cout << "Total Price: " << booking.calculateTotal() << endl;
        cout << "----------------------" << endl;
    }
}
