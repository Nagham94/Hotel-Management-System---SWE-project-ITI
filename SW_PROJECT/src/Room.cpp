#include "Room.h"

Room::~Room()
{
    //dtor
}

Room::Room(int number, string type, double price){
    roomNumber = number;
    this->type = type;
    pricePerNight = price;
    isAvailable = true; // Rooms are available by default
};

bool Room::checkAvailability() const { return isAvailable; };
void Room::setAvailability(bool status){ isAvailable = status; };
double Room::getPrice() const { return pricePerNight; };
string Room::getType() const { return type; };
int Room::getRoomNumber() const { return roomNumber; };