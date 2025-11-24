// Q#6: Hospital Appointment Scheduling System (Dynamic Queue Implementation)
// Hospitals often need to dynamically manage patient appointments as new cases arrive. Develop a dynamic queue (linked-list-based)
// for scheduling patient consultations.
// Each record stores:
// • Patient Name
// • Patient ID
// • Doctor’s Name
// • Appointment Time
// Operations:
// 1. addPatient()
// 2. callNextPatient()
// 3. displayAllAppointments()
// This simulation reflects real-time queuing logic used in hospital management systems to improve patient flow.
#include <iostream>
using namespace std;

class Node
{
public:
    string patientName;
    int patientId;
    string docName;
    string time;
    Node *next;

    Node(string n, int id, string dn, string t)
    {
        patientName = n;
        patientId = id;
        docName = dn;
        time = t;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Node *next;

    Queue()
    {
        front = rear = next = nullptr;
    }

    void addPatient(string n, int id, string dn, string t)
    {
        Node *newNode = new Node(n, id, dn, t);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient added successfully.\n";
    }

    void callNextPatient()
    {
        if (front == nullptr)
        {
            cout << " No patients in the queue.\n";
            return;
        }

        cout << "\n Calling next patient:\n";
        cout << front->patientName << " " << front->patientId << " "
             << front->docName << " " << front->time << endl;

        Node *del = front;
        front = front->next;
        delete del;

        if (front == nullptr)
            rear = nullptr;
    }
    void displayAllAppointments()
    {
        if (front == nullptr)
        {
            cout << "Nooo appointments available.\n";
            return;
        }
        Node *temp = front;
        cout << "Available Appointments are given below : " << endl;
        while (temp != nullptr)
        {
            cout << temp->patientName << " " << temp->patientId << " " << temp->docName << " " << temp->time << " " << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queue q;
    q.addPatient("Ali", 101, "Dr. Ahmed", "10:00 AM");
    q.addPatient("Sara", 102, "Dr. Hamid", "10:30 AM");
    q.addPatient("Zain", 103, "Dr. Fatima", "11:00 AM");

    cout << endl;
    q.displayAllAppointments();

    cout << endl;
    q.callNextPatient();

    cout << endl;
    q.displayAllAppointments();
    return 0;
}
