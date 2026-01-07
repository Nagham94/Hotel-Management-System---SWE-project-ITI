#include "Guest.h"

Guest::Guest(int id, string name, string phone): Person(name, phone) {
    guestId = id;
}

int Guest::getGuestId() {
    return guestId;
}

void Guest::displayInfo() {
    cout << "Guest ID   : " << guestId << endl;
    cout << "Name       : " << name << endl;
    cout << "Phone      : " << phone << endl;
}
