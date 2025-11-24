#include <iostream>
using namespace std;

class Node {
public:
    int rollNo;
    Node* next;

    Node(int val) {
        rollNo = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    Node* tail;

    SinglyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void deleteEnd() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = nullptr;  
        tail = temp;           
        delete del;
    }

    Node* reverse(Node* head) {
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return head;
        }
        if (head->next == nullptr) {
            return head;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }

    void split() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Single Node" << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* head2 = slow->next;
        slow->next = nullptr;

        cout << "First Half: ";
        display(head);

        Node* reversedSecondHalf = reverse(head2);

        cout << "Second Half (Reversed): ";
        display(reversedSecondHalf);
    }

    void display(Node* head) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->rollNo << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtHead(0);
    sll.insertAtHead(1);
    sll.insertAtHead(2);
    sll.insertAtHead(3);
    sll.insertAtHead(4);
    sll.insertAtHead(5);
    sll.insertAtHead(6);
    sll.insertAtHead(7);

    sll.split();
    return 0;
}
