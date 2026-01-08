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

Room* Hotel::getRoomByNumber(int roomNumber)
{
    for (auto& room : rooms)
    {
        if(room.getRoomNumber() == roomNumber)
        {
            return &room;
        }
    }
    return nullptr;
}

Booking* Hotel::getBookingById(int bookingId)
{
    for (auto& booking : bookings)
    {
        if(booking.getBookingId() == bookingId)
        {
            return &booking;
        }
    }
    return nullptr;
}

bool Hotel::checkInGuest(int bookingId, string date)
{
    Booking* booking = getBookingById(bookingId);
    if (booking == nullptr) {
        return false;
    }
    
    if (booking->getStatus() != CONFIRMED) {
        return false;
    }
    
    booking->checkIn(date);
    
    // Mark room as unavailable when guest checks in
    Room* room = getRoomByNumber(booking->getRoomNumber());
    if (room != nullptr) {
        room->setAvailability(false);
    }
    
    return true;
}

bool Hotel::checkOutGuest(int bookingId, string date)
{
    Booking* booking = getBookingById(bookingId);
    if (booking == nullptr) {
        return false;
    }
    
    if (booking->getStatus() != CHECKED_IN) {
        return false;
    }
    
    booking->checkOut(date);
    
    // Make room available again
    Room* room = getRoomByNumber(booking->getRoomNumber());
    if (room != nullptr) {
        room->setAvailability(true);
    }
    
    return true;
}

void Hotel::showAllRooms()
{
    for (auto& room : rooms)
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
    for (auto& booking : bookings)
    {
        cout << "Booking ID: " << booking.getBookingId() << endl;
        cout << "Guest Name: " << booking.getGuest().getName() << endl;
        cout << "Room Number: " << booking.getRoom().getRoomNumber() << endl;
        cout << "Number of Nights: " << booking.getNumberOfNights() << endl;
        cout << "Status: " << booking.getStatusString() << endl;
        if (!booking.getCheckInDate().empty()) {
            cout << "Check-In Date: " << booking.getCheckInDate() << endl;
        }
        if (!booking.getCheckOutDate().empty()) {
            cout << "Check-Out Date: " << booking.getCheckOutDate() << endl;
        }
        cout << "Total Price: $" << booking.calculateTotal() << endl;
        cout << "----------------------" << endl;
    }
}
