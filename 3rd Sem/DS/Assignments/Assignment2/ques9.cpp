// Q#9: Emergency Room Patient Management (Priority Queue Application)
// In a hospital Emergency Room (ER), patients are triaged based on urgency levels (1=Critical, 4=Low). Implement a priority queue
// that maintains patients according to priority.
// Each record includes:
// • Patient ID
// • Name
// • Condition Description
// • Priority Level
// Simulate arrivals in order 4,1,3,2 and ensure they are treated in the order 1→2→3→4. This demonstrates how hospital triage systems
// manage patient queues for optimal treatment sequencing.

// min priority queue
#include <iostream>
using namespace std;
int id[4], priority[4];
string name[4], description[4];
int s = 0, n = 4;

bool empty()
{
    return s == 0;
}

bool isFull()
{
    return s == n;
}

void insert(int iD, string n, string d, int p)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    int i = s - 1;
    while (i >= 0 && priority[i] > p)
    {
        id[i + 1] = id[i];
        name[i + 1] = name[i];
        description[i + 1] = description[i];
        priority[i + 1] = priority[i];
        i--;
    }
    id[i + 1] = iD;
    name[i + 1] = n;
    description[i + 1] = d;
    priority[i + 1] = p;

    s++;
}

void deleteVal()
{
    if (empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Critical patient " << id[0] << " " << name[0] << " " << description[0] << " " << " is now attended." << endl;
    for (int i = 0; i < s; i++)
    {
        id[i] = id[i + 1];
        name[i] = name[i + 1];
        description[i] = description[i + 1];
        priority[i] = priority[i + 1];
    }
    s--;
}

void peek()
{
    if (empty())
        return;
    cout << "Critical patient is " << id[0] << " " << name[0] << " " << description[0] << " " << "." << endl;
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " ";
        cout << name[i] << " ";
        cout << description[i] << " ";
        cout << priority[i] << " ";
        cout << endl;
    }
    
}

int main()
{
    // insert value of id name description and priority respectively in  min priority queue 4,1,2,3
    insert(41, "Aima", "Kidding", 4);
    insert(42, "Amna", "oho", 1);
    insert(43, "Eman", "ops", 2);
    insert(44, "Asma", "yaar", 3);
    display();
    deleteVal();
    display();
    peek();
    return 0;
}