// Q#7: Smart Parking Lot Management System (Circular Queue Application)
// A smart parking lot with fixed slots uses a circular queue to track parked cars and efficiently reuse empty slots.
// Each car record includes:
// • Car Number
// • Arrival Time
// • Slot Number
// Operations:
// 1. parkCar()
// 2. removeCar()
// 3. displayParkingStatus()
// This case study represents how smart parking systems optimize limited parking spaces using circular data structures.
#include <iostream>
using namespace std;
class CircularQueue
{
    int *carNumber;
    string *arrivalTime;
    string *slotNum;
    int currSize, cap;
    int f;
    int r;

public:
    CircularQueue(int size)
    {
        cap = size;
        carNumber = new int[cap];
        arrivalTime = new string[cap];
        slotNum = new string[cap];
        f = 0;
        r = -1;
        currSize = 0;
    }
    void parkCar(int cn, string aT, string sN)
    {
        if (currSize == cap)
        {
            cout << "Parking is Full" << endl;
            return;
        }
        r = (r + 1) % cap;
        carNumber[r] = cn;
        arrivalTime[r] = aT;
        slotNum[r] = sN;
        currSize++;
    }
    void removeCar()
    {
        if (empty())
        {
            cout << "Parking is empty." << endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
        if (currSize == 0)
        {
            f = 0;
            r = -1;
        }
    }
    bool empty()
    {
        return currSize == 0;
    }

    void displayParkingStatus()
    {
        if (empty())
        {
            cout << "Parking is empty." << endl;
            return;
        }
        cout << "In parking we have  : " << endl;
        for (int i = 0; i < currSize; i++)
        {
            int index = (f + i) % cap;
            cout << "Car: " << carNumber[index]
                 << ", Arrival: " << arrivalTime[index]
                 << ", Slot#: " << slotNum[index] << endl;
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue pq(3);
    pq.parkCar(101, "09:00 AM", "A1");
    pq.parkCar(102, "09:15 AM", "A2");
    pq.displayParkingStatus();

    pq.removeCar();
    pq.parkCar(103, "09:30 AM", "A3");
    pq.displayParkingStatus();

    pq.parkCar(104, "09:45 AM", "A4");
    pq.removeCar();
    pq.displayParkingStatus();

    return 0;
}