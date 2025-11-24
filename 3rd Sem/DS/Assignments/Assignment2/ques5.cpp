//Q#5: Airport Shuttle Ticketing Queue (Static Queue Implementation)
// At large airports, a shuttle service transports passengers between terminals. Passengers queue up to buy tickets following the first
// come, first-served rule. 
// Design a static queue (array-based) that manages ticket sales. Each passenger record includes: 
// • Name 
// • Destination Terminal 
// • Ticket Type (VIP/Regular) 
// Operations: 
// 1. enqueuePassenger() 
// 2. dequeuePassenger() 
// 3. displayQueue() 
// 4. isFull()/isEmpty() 
// This queue system mirrors real airport automation software used for passenger flow management.
#include <iostream>
using namespace std;

class Queue {
public:
    static const int size = 5;
    string name[size];
    string destination[size];
    string ticketType[size];
    int front;
    int rear;      
public:
    Queue() {
        front = rear = -1; 
    }
    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
    void enqueuePassenger(string name,string des,string Tt) {
        if (isFull()) {  
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        if (front == -1) 
        front = 0;
        this->name[rear]=name;
        this->destination[rear]=des;
        this->ticketType[rear]=Tt;
        cout << "Data pushed\n";
    }

    void dequeuePassenger() {
       if (isEmpty()|| front > rear ) {
            cout << "No data present.\n";
            return;
        }
        cout << "Dequeing 1st Passengers details:\n";
        cout << name[front] << " " << destination[front] << " " << ticketType[front] << endl;
        front++;
    }

    void displayQueue() {
        if (front ==  -1) {
            cout << "No Data stored.\n";
            return;
        }
        cout << "Data is given below : " << endl;
        for (int i = front; i <= rear; i++){
            cout << name[i] << " " ;
            cout << destination[i] << " " ;
            cout << ticketType[i] << " " ;
        cout << endl;
        }
    }

};

int main() {
   Queue q;
    q.enqueuePassenger("Ali", "Lahore", "VIP");
    q.enqueuePassenger("Sara", "Karachi", "Economy");
    q.enqueuePassenger("Aima", "Karachi", "Economy");
    q.enqueuePassenger("Abdullah", "Karachi", "Economy");
    q.enqueuePassenger("kiran", "Karachi", "Economy");
    q.enqueuePassenger("Eman", "Karachi", "Economy");
    q.displayQueue();
    q.dequeuePassenger();
    q.displayQueue();
    q.dequeuePassenger();
    q.dequeuePassenger();
    q.dequeuePassenger();
    q.displayQueue();
    q.dequeuePassenger();
    q.dequeuePassenger(); 
}
