#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

/* Room class definition */
/*
   Attributes:   
   - int roomNumber;
   - string type;
   - double pricePerNight;
   - bool isAvailable;
    Methods:
   + Room(int number, string type, double price);
   + bool checkAvailability();
   + void setAvailability(bool status);
   + double getPrice();
   + string getType();
   + int getRoomNumber();
*/ 
class Room
{
    public:
        Room(int number, string type, double price);
        virtual ~Room();
        bool checkAvailability() const;
        void setAvailability(bool status);
        double getPrice() const;
        string getType() const;
        int getRoomNumber() const;

    protected:

    private:
        int roomNumber;
        string type;
        double pricePerNight;
        bool isAvailable;
};

#endif // ROOM_H

