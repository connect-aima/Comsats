#include <iostream>
using namespace std;
#define MAX 10
class Stack
{
public:
    int data[MAX];
    int top;
    Stack()
    {
        top = -1;
    }
    void insert(int val)
    {
        if (top == MAX - 1)
        {
            cout << "OverFlow";
            return;
        }
        data[++top] = val;
    }
    void insertAtPosition(int pos, int val) {
    if (top == MAX - 1) {
        cout << "Overflow\n";
        return;
    }
    if (pos < 0 || pos > top + 1) {
        cout << "Invalid position\n";
        return;
    }

    //right shift elements 
    for (int i = top + 1; i > pos; i--) {
        data[i] = data[i - 1];
    }

    data[pos] = val;
    top++;  // ✅ Increase top since new element added

    cout << "Value inserted at position " << pos << endl;
}

    void del()
    {
        if (top == -1)
        {
            cout << "UnderFlow";
            return;
        }
        cout << "Deleting last inserted value : " << data[top] << endl ;
        top--;
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Empty";
            return;
        }
        for (int i = top ; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.display();
    s.insertAtPosition(1,11);
    s.display();

    return 0;
}