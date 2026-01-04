#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include "Room.h"
#include "Booking.h"

class Hotel
{
    public:
        Hotel();
        virtual ~Hotel();
        void addRoom(Room room);
        void addBooking(Booking booking);
        Room* findAvailableRoom();
        void showAllRooms();
        void showAllBookings();

    private:
        vector<Room> rooms;
        vector<Booking> bookings;
};

#endif // HOTEL_H


