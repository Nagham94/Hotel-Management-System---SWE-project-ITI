#ifndef BOOKING_H
#define BOOKING_H

#include "Guest.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

/* Booking class definition */
/*
   Attributes:
   - int bookingId;
   - Guest guest;
   - Room room;
   - int numberOfNights;
   - BookingStatus status;
   - string checkInDate;
   - string checkOutDate;

    Methods:
    + Booking(int id, Guest guest, Room room, int nights);
    + double calculateTotal();
    + void confirmBooking();
    + int getBookingId();
    + Guest getGuest();
*/

enum BookingStatus {
    CONFIRMED,
    CHECKED_IN,
    CHECKED_OUT
};

class Booking
{
    public:
        Booking(int id, Guest& guest, Room& room, int nights);
        virtual ~Booking();
        double calculateTotal();
        void confirmBooking();
        void checkIn(string date);
        void checkOut(string date);
        int getBookingId();
        int getRoomNumber();
        int getNumberOfNights();
        Guest getGuest();
        Room getRoom();
        BookingStatus getStatus();
        string getStatusString();
        string getCheckInDate();
        string getCheckOutDate();

    protected:

    private:
        int bookingId;
        Guest guest;
        Room room;
        int numberOfNights;
        BookingStatus status;
        string checkInDate;
        string checkOutDate;
};

#endif // BOOKING_H

