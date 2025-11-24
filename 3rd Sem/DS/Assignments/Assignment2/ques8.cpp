// Q#8: Train Compartment Reservation System (Double-Ended Queue Application)
// The national railway’s reservation system must handle both VIP and regular passengers. VIP passengers get front-end bookings, while
// regular passengers are queued from the rear end.
// Design a double-ended circular queue (deque) to manage compartment reservations. Each record includes:
// • Passenger Name
// • Category (VIP/Regular)
// • Seat Number
// Operations:
// 1. bookAtFront()
// 2. bookAtRear()
// 3. cancelFromFront()/cancelFromRear()
// 4. displayAllReservations()
// This models how transportation systems dynamically prioritize customers without disrupting existing orders.
#include <iostream>
using namespace std;
string name[5];
string catogory[5];
int seatNum[5];
int s = 0, c = 5;
bool empty()
{
    return s == 0;
}

bool isFull()
{
    return s == c;
}
void bookAtfront(string nm, string c, int sz)
{
    if (isFull()) return;

    for (int i = s; i > 0; i--) {
        name[i] = name[i - 1];
        catogory[i] = catogory[i - 1];
        seatNum[i] = seatNum[i - 1];
    }

    name[0] = nm;
    catogory[0] = c;
    seatNum[0] = sz;
    s++;
}

void bookAtrear(string nm, string c, int sz)
{
    if (isFull())
    {
        cout << "No more bookings — list is full!\n";
        return;
    }

    name[s] = nm;
    catogory[s] = c;
    seatNum[s] = sz;

    s++;
}
void cancelFromFront()
{
    if (empty())
    {
        cout << "Empty Already" << endl;
        return;
    }
    for (int i = 0; i < s - 1; i++)
    {
        name[i] = name[i + 1];
        catogory[i] = catogory[i + 1];
        seatNum[i] = seatNum[i + 1];
    }
    s--;
    cout << "First booking is cancelled!" << endl;
}
void cancelFromRear()
{
    if (empty())
    {
        cout << "Empty Already" << endl;
        return;
    }
    s--;
    cout << "Last booking is cancelled!" << endl;
}
void displayAllReservations()
{
    if (empty())
    {
        cout << "Empty Already" << endl;
        return;
    }
    for (int i = 0; i < s; i++)
    {
        cout << name[i] << " ";
        cout << catogory[i] << " ";
        cout << seatNum[i] << " ";
        cout << endl;
    }
}

int main()
{
    int choice;
    string nm, c;
    int sz;

    do
    {
      
        cout << "1. Book at Front (VIP)\n";
        cout << "2. Book at Rear (Regular)\n";
        cout << "3. Cancel from Front\n";
        cout << "4. Cancel from Rear\n";
        cout << "5. Display All Reservations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Passenger Name: ";
            cin >> nm;
            cout << "Enter Category (VIP/Regular): ";
            cin >> c;
            cout << "Enter Seat Number: ";
            cin >> sz;
            bookAtfront(nm, c, sz);
            break;

        case 2:
            cout << "Enter Passenger Name: ";
            cin >> nm;
            cout << "Enter Category (VIP/Regular): ";
            cin >> c;
            cout << "Enter Seat Number: ";
            cin >> sz;
            bookAtrear(nm, c, sz);
            break;

        case 3:
            cancelFromFront();
            break;

        case 4:
            cancelFromRear();
            break;

        case 5:
            displayAllReservations();
            break;

        case 0:
            cout << "Exiting system..." << endl;
            break;

        default:
            cout << "Invalid option! Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}