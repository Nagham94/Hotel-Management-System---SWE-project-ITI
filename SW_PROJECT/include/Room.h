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
        Room(int number, string type, double price){
            roomNumber = number;
            this->type = type;
            pricePerNight = price;
            isAvailable = true; // Rooms are available by default
        };
        bool checkAvailability(){ return isAvailable; };
        void setAvailability(bool status){ isAvailable = status; };
        double getPrice(){ return pricePerNight; };
        string getType(){ return type; };
        int getRoomNumber(){ return roomNumber; };

    protected:

    private:
        int roomNumber;
        string type;
        double pricePerNight;
        bool isAvailable;
};

#endif // ROOM_H

