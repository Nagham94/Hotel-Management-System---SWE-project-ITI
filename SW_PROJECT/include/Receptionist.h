#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <string>

#include "Person.h"
#include "Hotel.h"
#include "Guest.h"

class Receptionist : public Person {
private:
    int employeeId;

public:
    // Constructor
    Receptionist(int id, string name, string phone);

    // Methods
    void createBooking(Hotel& hotel, Guest& guest, int nights);
    void checkInGuest(Hotel& hotel, Guest& guest);
    void checkOutGuest(Hotel& hotel, Guest& guest);
    void viewRooms(Hotel& hotel);
    void viewBookings(Hotel& hotel);

    int getEmployeeID();
};

#endif
