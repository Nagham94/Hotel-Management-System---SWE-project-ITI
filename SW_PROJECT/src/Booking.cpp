#include "Booking.h"

Booking::~Booking()
{
    //dtor
}

Booking::Booking(int id, Guest& guest, Room& room, int nights)
    : bookingId(id), guest(guest), room(room), numberOfNights(nights), 
      status(CONFIRMED), checkInDate(""), checkOutDate("")
{
    // Constructor body can be empty now
};

double Booking::calculateTotal() {
    return room.getPrice() * numberOfNights;
};

void Booking::confirmBooking(){
    // Booking is confirmed, but room stays available until check-in
};

int Booking::getBookingId() { return bookingId; };

int Booking::getNumberOfNights() { return numberOfNights; };

int Booking::getRoomNumber() { return room.getRoomNumber(); };

Guest Booking::getGuest() { return guest; };

Room Booking::getRoom() { return room; };

BookingStatus Booking::getStatus() { return status; };

string Booking::getStatusString() {
    switch(status) {
        case CONFIRMED: return "Confirmed";
        case CHECKED_IN: return "Checked In";
        case CHECKED_OUT: return "Checked Out";
        default: return "Unknown";
    }
};

string Booking::getCheckInDate() { return checkInDate; };

string Booking::getCheckOutDate() { return checkOutDate; };

void Booking::checkIn(string date) {
    checkInDate = date;
    status = CHECKED_IN;
};

void Booking::checkOut(string date) {
    checkOutDate = date;
    status = CHECKED_OUT;
};
