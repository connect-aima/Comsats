// Major online retailers such as Daraz and Amazon process hundreds of product return requests every hour. The Return Management 
// Department handles these requests in reverse order of arrival to quickly resolve the most recent issues first. 
// Design and implement a static stack (array-based) system that stores customer return requests. 
// Each request includes: 
// • Order ID 
// • Customer Name 
// • Return Reason 
// • Date of Request 
// Operations: 
// 1. pushReturnRequest() – Add a new return request to the stack. 
// 2. popReturnRequest() – Process and remove the latest request. 
// 3. peekLatestRequest() – View the most recent request awaiting review. 
// 4. displayAllRequests() – Display all unprocessed requests. 
//stack implementation using array 
#include <iostream>
using namespace std;
#define MAX 100 // we can fix size in max and then use max in arrays 
class Stack {
public:
    int id[5];
    string name[5];
    string reason[5];
    string date[5];
    int top;      
public:
    Stack() {
        top = -1; 
    }

    void pushReturnRequest(int id,string name,string reason,string date) {
        if (top == 4) {  
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        this->id[top] = id;
        this->name[top]=name;
        this->reason[top]=reason;
        this->date[top]=date;
        cout << "Data pushed\n";
    }

    void popReturnRequest() {
       if (top == -1) {
            cout << "No requests to process.\n";
            return;
        }
        cout << "Deleting latest request:\n";
        cout << id[top] << " " << name[top] << " " << reason[top] << " " << date[top] << endl;
        top--;
    }

    void peekLatestRequest(){
        if (top == -1) {
            cout << "No pending requests.\n";
            return;
        }
        cout << "Latest request \n";
        cout << id[top] << " " << name[top] << " " << reason[top] << " " << date[top] << endl;
    }

    void displayAllRequest() {
        if (top == -1) {
            cout << "No pending requests.\n";
            return;
        }
        cout << "Submitted Requests: " << endl;
        for (int i = top; i >= 0; i--){
            cout << id[i] << " " ;
            cout << name[i] << " " ;
            cout << reason[i] << " " ;
            cout << date[i] << " " ;
        cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.pushReturnRequest(1,"Aima","didnt like product","24-09-2024");
    s.pushReturnRequest(2,"Aima","didnt like product","24-09-2024");
    s.pushReturnRequest(3,"Aima","didnt like product","24-09-2024");
    s.pushReturnRequest(4,"Aima","didnt like product","24-09-2024");
    s.pushReturnRequest(5,"Aima","didnt like product","24-09-2024");
    s.displayAllRequest();
    s.popReturnRequest();
    s.displayAllRequest();
    s.peekLatestRequest();
}
