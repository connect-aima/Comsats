// Modern browsers (e.g., Google Chrome, Mozilla Firefox) maintain a navigation history that allows users to go back and forth between 
// visited websites. This navigation history internally functions as a stack. 
// Implement a dynamic stack (linked-list-based) to simulate a simplified browser history system. Each node represents a webpage 
// containing: 
// • Page Title 
// • URL 
// • Time Visited 
// Operations: 
// 1. visitPage(url) 
// 2. goBack() 
// 3. viewCurrentPage() 
// 4. displayHistory()
#include <iostream>
using namespace std;
class Node{
public:
    string url;
    string time;
    string title;
    Node* next;

    Node(string url,string time,string title){
        this->title=title;
        this->url=url;
        this->time=time;
        next=nullptr;
    }
};

class Stack {
public:
    Node* head;
    Node* curr;

    Stack(){
        curr=head=nullptr;
    }
//insert At head logic is used
    void visitPage(string url,string time,string title){
        Node* newNode = new Node(url,time,title);
        if(head==nullptr){
            curr=head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
            curr=newNode;
        }
        cout << "Visited: " << title << " (" << url << ") at " << time << endl;
    }

    void goBack(){
        if(head==nullptr){
            cout << "Empty";
            return;
        }
        if(head->next==nullptr){
            cout << "Going back from \n";
            cout << head->url << " " << head->title << " " << head->time << " " << endl;
            delete head;
            curr=head=nullptr;
            return;
        }
        Node* del=head;
        cout << "Going back from \n";
        cout << head->url << " " << head->title << " " << head->time << " " << endl;
        head=head->next;
        delete del;
        curr=head;
    }

    void viewCurrentPage(){
        if(curr==nullptr){
            cout << "Empty";
            return;
        }
        cout << "Current Page is:  \n";
        cout << curr->url << " " << curr->title << " " << curr->time << " " << endl;
    }

    void displayHistory(){
         if(head==nullptr){
            cout << "Empty";
            return;
        }
        Node* temp=head;
        cout << "History is" << endl;
        while(temp!=nullptr){
            cout << temp->url << " " << temp->title << " " << temp->time << " " << endl;
            temp=temp->next;
        }
    }


};
int main() {
    Stack browser;
    browser.visitPage("https://www.google.com", "10:00 AM", "Google");
    browser.visitPage("https://www.github.com", "10:10 AM", "GitHub");
    browser.visitPage("https://www.youtube.com", "10:20 AM", "YouTube");

    cout << endl;
    browser.viewCurrentPage();

    cout << endl;
    browser.displayHistory();

    cout << endl;
    browser.goBack();   
    cout << endl;
    browser.viewCurrentPage();

    cout << endl;
    browser.displayHistory();
    return 0;
}