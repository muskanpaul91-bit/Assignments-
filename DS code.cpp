#include <iostream>
#include <string>
using namespace std;
struct Passenger {
    int seatNo;
    string name;
    int age;
    char gender;
    Passenger* next;
};
int totalSeats = 30;
int* seats; 
Passenger* head = NULL;
void bookTicket() {
    int seatNo = -1;

    for (int i = 0; i < totalSeats; i++) {
        if (seats[i] == 0) {
            seatNo = i + 1; 
            seats[i] = 1;   
            break;
        }
    }

    if (seatNo == -1) {
        cout << "Sorry! No seats available.\n";
        return;
    }

    Passenger* newPassenger = new Passenger;
    newPassenger->seatNo = seatNo;
    cout << "Enter Name: ";
    cin >> newPassenger->name;
    cout << "Enter Age: ";
    cin >> newPassenger->age;
    cout << "Enter Gender (M/F): ";
    cin >> newPassenger->gender;
    newPassenger->next = NULL;

    
    if (head == NULL) {
        head = newPassenger;
    } else {
        Passenger* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPassenger;
    }

    cout << "Ticket booked successfully! Seat No: " << seatNo << endl;
}
void cancelTicket() {
    int seatNo;
    cout << "Enter seat number to cancel: ";
    cin >> seatNo;

    if (seatNo < 1 || seatNo > totalSeats || seats[seatNo - 1] == 0) {
        cout << "Invalid seat number or seat already empty.\n";
        return;
    }


    seats[seatNo - 1] = 0;

    
    Passenger* temp = head;
    Passenger* prev = NULL;

    while (temp != NULL && temp->seatNo != seatNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Passenger not found.\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Ticket for Seat No " << seatNo << " has been cancelled.\n";
}


void viewTrainStatus() {
    cout << "\nTrain Seat Status:\n";
    for (int i = 0; i < totalSeats; i++) {
        cout << "Seat " << i + 1 << ": "
             << (seats[i] == 1 ? "Booked" : "Available") << endl;
    }
}


void viewPassengerList() {
    if (head == NULL) {
        cout << "No passengers found.\n";
        return;
    }

    Passenger* temp = head;
    cout << "\nPassenger List:\n";
    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNo
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Gender: " << temp->gender << endl;
        temp = temp->next;
    }
}


void freeMemory() {
    delete[] seats;
    Passenger* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    seats = new int[totalSeats]; 
    for (int i = 0; i < totalSeats; i++) {
        seats[i] = 0; 
    }

    int choice;
    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: viewTrainStatus(); break;
            case 4: viewPassengerList(); break;
            case 5: freeMemory(); cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

