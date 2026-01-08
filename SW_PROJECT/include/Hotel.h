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
        Room* getRoomByNumber(int roomNumber);
        Booking* getBookingById(int bookingId);
        void showAllRooms();
        void showAllBookings();
        bool checkInGuest(int bookingId, string date);
        bool checkOutGuest(int bookingId, string date);

    private:
        vector<Room> rooms;
        vector<Booking> bookings;
};

#endif // HOTEL_H


