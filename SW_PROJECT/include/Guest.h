#ifndef GUEST_H
#define GUEST_H

#include "Person.h"

class Guest : public Person {
private:
    int guestId;

public:
    Guest(int id, string name, string phone);
    int getGuestId();
    void displayInfo() override;
};

#endif // GUEST_H
