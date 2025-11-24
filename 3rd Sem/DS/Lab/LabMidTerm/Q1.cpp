// A theme park operates a shuttle service that continuously picks up and drops off visitors at multiple stops arranged in a loop. Each stop is identified by its name (for example, Main Gate, Water Park, Food Court) and the distance (in meters) to the next stop.
// After analyzing the route data, the park management noticed that some stops are located very far apart, resulting in longer travel times for visitors. To improve the shuttle experience, they have decided to add a new shuttle stop between the two existing stops that have the largest distance between them, ensuring that the route remains continuous without disruption.
// Task
// Write a C++ program to model this scenario and perform the following operations:
// 1.	Create an initial shuttle route with a few predefined stops and their distances to the next stop.
// 2.	Find the two consecutive stops that have the largest distance between them.
// 3.	Insert a new stop between those two stops to reduce the gap.
// 4.	Ensure that the route remains connected and continuous after the insertion.
// 5.	Display the complete updated route.
// Example
// Input:
// Initial Route:
// Main Gate (to Water Park = 100m)
// Water Park (to Food Court = 250m)
// Food Court (to Zoo = 150m)
// Zoo (to Main Gate = 200m)

// New Stop: "Rest Area"

// Output:
// New stop added between Water Park and Food Court.
// Updated Route:
// Main Gate → Water Park → Rest Area → Food Court → Zoo → Main Gate

#include <iostream>
using namespace std;
class Node{
public:
    string name;
    int distance;
    Node* next;

    Node(string n , int d){
        name=n;
        distance=d;
        next=nullptr;
    }
};

class ThemePark{
public:
    Node* head;
    Node* tail;

    ThemePark(){
        head=tail=nullptr;
    }

    void insertStop(string n , int d){
        Node* newNode = new Node(n,d);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    void getMaxDistanceOfTwoConseqtiveNode(){
        if(head==nullptr){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next==nullptr){
            cout << "List has only one stop"  << endl;
            return;
        }
        Node* temp=head;
        Node* maxNode=head;
        int MaxDistance=head->distance;
        while(temp->next!=nullptr){
            if(temp->distance > MaxDistance){
                MaxDistance=temp->distance;
                maxNode=temp;
            }
            temp=temp->next;
        }
        cout << "Maximum distance is " << MaxDistance << " between " << maxNode->name << " and " << maxNode->next->name << endl;
    }

    void insertAtPosition(int pos , string name , int distance){
        Node* newNode=new Node(name,distance);
        if(pos==1){
            newNode->next=head;
            head=newNode;
            return;
        }
        Node* temp=head;
        for(int i=1;i<pos-1 && temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr) return;
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void display(){
        if(head==nullptr){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout << temp->name << " " << temp->distance << "m -> ";
            temp=temp->next;
        }
        cout << "Null" << endl;
    }
};
int main() {
    ThemePark tp;
    tp.insertStop("Main Gate",100);
    tp.insertStop("Water Park",250);
    tp.insertStop("Food Court",150);
    tp.insertStop("Zoo",200);
    tp.display();
    tp.getMaxDistanceOfTwoConseqtiveNode();
    tp.insertAtPosition(2,"Silikon Valley",2000);
    tp.display();
    tp.getMaxDistanceOfTwoConseqtiveNode();
    return 0;
}
