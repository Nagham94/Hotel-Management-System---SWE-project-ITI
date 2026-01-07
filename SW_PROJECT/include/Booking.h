#ifndef BOOKING_H
#define BOOKING_H

#include "Guest.h"
#include "Room.h"
#include <iostream>
using namespace std;

/* Booking class definition */
/*
   Attributes:
   - int bookingId;
   - Guest guest;
   - Room room;
   - int numberOfNights;

    Methods:
    + Booking(int id, Guest guest, Room room, int nights);
    + double calculateTotal();
    + void confirmBooking();
    + int getBookingId();
    + Guest getGuest();
*/

class Booking
{
    public:
        Booking(int id, Guest guest, Room room, int nights){
            bookingId = id;
            this->guest = guest;
            this->room = room;
            numberOfNights = nights;
        };
        double calculateTotal(){
            return room.getPrice() * numberOfNights;
        };
        void confirmBooking(){
            room.setAvailability(false);
        };
        int getBookingId(){ return bookingId; };
        Guest getGuest(){ return guest; };

    protected:

    private:
        int bookingId;
        Guest guest;
        Room room;
        int numberOfNights;
};

#endif // BOOKING_H

