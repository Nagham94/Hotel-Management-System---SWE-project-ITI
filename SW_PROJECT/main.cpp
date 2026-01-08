#include <iostream>
#include <limits>
#include "Hotel.h"
#include "Guest.h"
#include "Room.h"
#include "Booking.h"

using namespace std;

void displayMainMenu();
void addRoomToHotel(Hotel& hotel);
void viewAllRooms(Hotel& hotel);
void makeBooking(Hotel& hotel, int& bookingIdCounter);
void viewAllBookings(Hotel& hotel);
void checkInGuest(Hotel& hotel);
void checkOutGuest(Hotel& hotel);
void clearInputBuffer();

int main()
{
    Hotel hotel;
    int choice;
    int bookingIdCounter = 1;
    
    cout << "========================================" << endl;
    cout << "   HOTEL MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                addRoomToHotel(hotel);
                break;
            case 2:
                viewAllRooms(hotel);
                break;
            case 3:
                makeBooking(hotel, bookingIdCounter);
                break;
            case 4:
                viewAllBookings(hotel);
                break;
            case 5:
                checkInGuest(hotel);
                break;
            case 6:
                checkOutGuest(hotel);
                break;
            case 7:
                cout << "\nThank you for using the Hotel Management System!" << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please select 1-7." << endl;
        }
        
        if (choice != 7) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while(choice != 7);
    
    return 0;
}

void displayMainMenu() {
    cout << "\n========================================" << endl;
    cout << "           MAIN MENU" << endl;
    cout << "========================================" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. View All Rooms" << endl;
    cout << "3. Make a Booking" << endl;
    cout << "4. View All Bookings" << endl;
    cout << "5. Check-In Guest" << endl;
    cout << "6. Check-Out Guest" << endl;
    cout << "7. Exit" << endl;
    cout << "========================================" << endl;
}

void addRoomToHotel(Hotel& hotel) {
    int roomNumber;
    string roomType;
    double price;
    
    cout << "\n--- Add New Room ---" << endl;
    cout << "Enter room number: ";
    cin >> roomNumber;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    clearInputBuffer();
    
    cout << "Enter room type (Single/Double/Suite): ";
    getline(cin, roomType);
    
    cout << "Enter price per night: ";
    cin >> price;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    Room newRoom(roomNumber, roomType, price);
    hotel.addRoom(newRoom);
    
    cout << "\nRoom added successfully!" << endl;
}

void viewAllRooms(Hotel& hotel) {
    cout << "\n========================================" << endl;
    cout << "         ALL ROOMS" << endl;
    cout << "========================================" << endl;
    hotel.showAllRooms();
}

void makeBooking(Hotel& hotel, int& bookingIdCounter) {
    int guestId;
    string guestName, guestPhone;
    int roomNumber;
    int numberOfNights;
    
    cout << "\n--- Make a Booking ---" << endl;
    cout << "Enter Guest ID: ";
    cin >> guestId;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    clearInputBuffer();
    
    cout << "Enter Guest Name: ";
    getline(cin, guestName);
    
    cout << "Enter Guest Phone: ";
    getline(cin, guestPhone);
    
    Guest guest(guestId, guestName, guestPhone);
    
    cout << "\nAvailable Rooms:" << endl;
    cout << "----------------------------------------" << endl;
    hotel.showAllRooms();
    
    cout << "\nEnter Room Number to book: ";
    cin >> roomNumber;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    cout << "Enter number of nights: ";
    cin >> numberOfNights;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    // Get the actual room from the hotel
    Room* roomPtr = hotel.getRoomByNumber(roomNumber);
    
    if (roomPtr == nullptr) {
        cout << "\nRoom not found!" << endl;
        return;
    }
    
    if (!roomPtr->checkAvailability()) {
        cout << "\nRoom is not available!" << endl;
        return;
    }
    
    Booking booking(bookingIdCounter++, guest, *roomPtr, numberOfNights);
    booking.confirmBooking();
    hotel.addBooking(booking);
    
    cout << "\n========================================" << endl;
    cout << "Booking confirmed!" << endl;
    cout << "Booking ID: " << booking.getBookingId() << endl;
    cout << "Guest: " << guest.getName() << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Number of Nights: " << numberOfNights << endl;
    cout << "Total Amount: $" << booking.calculateTotal() << endl;
    cout << "========================================" << endl;
}

void viewAllBookings(Hotel& hotel) {
    cout << "\n========================================" << endl;
    cout << "         ALL BOOKINGS" << endl;
    cout << "========================================" << endl;
    hotel.showAllBookings();
}

void checkInGuest(Hotel& hotel) {
    int bookingId;
    string checkInDate;
    
    cout << "\n--- Check-In Guest ---" << endl;
    cout << "Enter Booking ID: ";
    cin >> bookingId;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    clearInputBuffer();
    
    cout << "Enter Check-In Date (DD/MM/YYYY): ";
    getline(cin, checkInDate);
    
    if (hotel.checkInGuest(bookingId, checkInDate)) {
        cout << "\n========================================" << endl;
        cout << "Guest checked in successfully!" << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Check-In Date: " << checkInDate << endl;
        cout << "========================================" << endl;
    } else {
        cout << "\nFailed to check in! Booking not found or already checked in." << endl;
    }
}

void checkOutGuest(Hotel& hotel) {
    int bookingId;
    string checkOutDate;
    
    cout << "\n--- Check-Out Guest ---" << endl;
    cout << "Enter Booking ID: ";
    cin >> bookingId;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Invalid input!" << endl;
        return;
    }
    
    clearInputBuffer();
    
    cout << "Enter Check-Out Date (DD/MM/YYYY): ";
    getline(cin, checkOutDate);
    
    if (hotel.checkOutGuest(bookingId, checkOutDate)) {
        cout << "\n========================================" << endl;
        cout << "Guest checked out successfully!" << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Check-Out Date: " << checkOutDate << endl;
        cout << "Room is now available for booking." << endl;
        cout << "========================================" << endl;
    } else {
        cout << "\nFailed to check out! Booking not found or not checked in yet." << endl;
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
