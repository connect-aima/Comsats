#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
// insertion at begining with time complexity O(1)
void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head; // new node will store address of old head
    head = newNode;       // now new node is head
}
//task1
Node* reverseLinkedListIteratively(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    Node* newHead = prev;
    return newHead;
}
Node* reverseRecursively(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* newHead=reverseRecursively(curr->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
//task2
Node* merged(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* temp= head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}
//task3
void occurrence(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        int count = 1;  
        while (temp->next != NULL && temp->data == temp->next->data) {
            count++;
            temp = temp->next;
        }
        cout << temp->data << " occurs " << count << " times " << endl;
        temp = temp->next;
    }
}
void splitList(Node* &head){
    Node* slow = head;
    Node* fast=head->next;
    Node*temp=head;
    while(temp=NULL){
        slow=temp->next;
        fast=temp->next->next;
    }
    Node* head2=slow->next;
    slow->next=NULL;
    display(head);
    display(head2);
}

void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->" ;
        temp=temp->next;
    }
    cout << "NULL" << endl;
}



int main() {
    Node* head1=NULL;
    insertAtHead(head1,29);
    insertAtHead(head1,38);
    insertAtHead(head1,45);
    insertAtHead(head1,24);
    insertAtHead(head1,11);
    insertAtHead(head1,2);
    insertAtHead(head1,56);
    insertAtHead(head1,12);
       
    display(head1);
    splitList(head1);
    // Node* reversedList= reverseLinkedListIteratively(head1);
    // display(reversedList);
    // Node* reversedListt= reverseRecursively(head1);
    // display(reversedList);
    // Node* head2=NULL;
    // insertAtHead(head2,15);
    // insertAtHead(head2,14);
    // insertAtHead(head2,13);
    // insertAtHead(head2,12);
    // insertAtHead(head2,11);
    // display(head2);
    // Node* mergedlist= merged(head1,head2);
    // display(mergedlist);
    // occurrence(head1);
    


    
    return 0;
}
