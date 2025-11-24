// Q#10: Food Delivery Dispatch System (Application of Queue)
// A food delivery service (like Foodpanda) must assign orders to riders in real time. Each order includes:
// • Order ID
// • Restaurant Name
// • Customer Address
// • Item List
// • Preparation Time
// • Order Time
// Operations:
// 1. addOrder() – Insert at front if quick items only, else at rear.
// 2. dispatchOrder()
// 3. viewNextOrder()
// 4. displayAllOrders()
// 5. cancelOrder(orderID)
// This models the dispatch logic of real delivery systems, balancing quick orders and high-priority deliveries using queue operations.

#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    string name;
    string address;
    string itemList;
    string prepTime;
    string orderTime;
    Node *next;
    Node *prev;

    Node(int id, string name, string address, string itemList, string prepTime, string orderTime)
    {
        this->id = id;
        this->name = name;
        this->address = address;
        this->itemList = itemList;
        this->prepTime = prepTime;
        this->orderTime = orderTime;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleEndedQueue
{

public:
    Node *head;
    Node *tail;

    DoubleEndedQueue()
    {
        head = tail = nullptr;
    }
    // insert at head if quick otherwise at tail
    void addOrder(int id, string name, string address, string itemList, string prepTime, string orderTime, string type)
    {
        Node *newNode = new Node(id, name, address, itemList, prepTime, orderTime);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else if (type == "quick" || type == "Quick")
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // deletion at head
    void dispatchOrder()
    {
        if (head == nullptr)
        {
            cout << "Empty" << endl;
            return;
        }
        Node *del = head;

        //Only one node
        if (head == tail)
        {
            head = tail = nullptr;
        }
        //More than one node
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        cout << "Dispatched Order ID: " << del->id << endl;
        delete del;
    }
    void viewNextOrder() {
    if (head == nullptr) {
        cout << "No orders in queue.\n";
        return;
    }
    cout << "Next order to dispatch:\n";
    cout << "ID: " << head->id
         << ", Restaurant: " << head->name
         << ", Address: " << head->address
         << ", Items: " << head->itemList
         << ", Prep Time: " << head->prepTime
         << ", Order Time: " << head->orderTime
         << endl;
}

    void displayAllOrders()
{
    if (head == nullptr) {
        cout << "No orders to display.\n";
        return;
    }

    cout << "\nAll Active Orders\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Order ID: " << temp->id << endl;
        cout << "Restaurant: " << temp->name << endl;
        cout << "Address: " << temp->address << endl;
        cout << "Items: " << temp->itemList << endl;
        cout << "Preparation Time: " << temp->prepTime << endl;
        cout << "Order Time: " << temp->orderTime << endl;
        temp = temp->next;
    }
}

    void cancelOrder(int orderID)
    //when we delete in doubly linked list there will be 5 cases 
    // 1. list is empty return 
    // 2.set temp that points to head if id is at head move head to the next, if newhead is null delete head and set head = tail = nullptr  or if head is not null set newhead ->prev= null 
    // traverse temp 
    // 3.if temp at null display id not found  
    // 4.if temp at tail assign tail = tail ->prev , tail->next=nullptr
    // 5.if temp at middle  do temp->prev->next = temp->next; temp->next->prev = temp->prev;

{
    //case 1 list is empty
    if (head == nullptr) {
        cout << "No orders to cancel.\n";
        return;
    }

    Node* temp = head;

    // Case 2: Order at head
    if (temp->id == orderID) {
        head = head->next;
        //if new head is not null
        if (head != nullptr)
            head->prev = nullptr;
        //if new head is null means list is empty
        else
            tail = nullptr;
        delete temp;
        cout << "Order ID " << orderID << " cancelled (was at front).\n";
        return;
    }

    // Traverse to find order
    while (temp != nullptr && temp->id != orderID)
        temp = temp->next;

    // Case 3: Not found
    if (temp == nullptr) {
        cout << "Order ID " << orderID << " not found.\n";
        return;
    }

    // Case 4: Found at tail
    if (temp == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        cout << "Order ID " << orderID << " cancelled (was at rear).\n";
        return;
    }

    // Case 5: Found in middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    cout << "Order ID " << orderID << " cancelled (was in middle).\n";
}

};

int main()
{
    DoubleEndedQueue dq;
    int choice;

    do {
        cout << "\nFood Delivery Dispatch System\n";
        cout << "1. Add Order\n";
        cout << "2. Dispatch Order\n";
        cout << "3. View Next Order\n";
        cout << "4. Display All Orders\n";
        cout << "5. Cancel Order\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to clear newline after integer input

        if (choice == 1) {
            int id;
            string name, address, itemList, prepTime, orderTime, type;

            cout << "\nEnter Order ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Restaurant Name: ";
            getline(cin, name);
            cout << "Enter Customer Address: ";
            getline(cin, address);
            cout << "Enter Item List: ";
            getline(cin, itemList);
            cout << "Enter Preparation Time: ";
            getline(cin, prepTime);
            cout << "Enter Order Time: ";
            getline(cin, orderTime);
            cout << "Enter Type (quick / regular): ";
            cin >> type;

            dq.addOrder(id, name, address, itemList, prepTime, orderTime, type);
            cout << "Order Added Successfully!\n";
        }

        else if (choice == 2) {
            dq.dispatchOrder();
        }

        else if (choice == 3) {
            dq.viewNextOrder();
        }

        else if (choice == 4) {
            dq.displayAllOrders();
        }

        else if (choice == 5) {
            int id;
            cout << "Enter Order ID to cancel: ";
            cin >> id;
            dq.cancelOrder(id);
        }

        else if (choice == 0) {
            cout << "Exiting system...\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);
    return 0;
}
