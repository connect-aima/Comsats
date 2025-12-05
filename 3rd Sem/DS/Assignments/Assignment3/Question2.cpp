#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string location;
    int price;
    Node* left;
    Node* right;

    Node(int i, string l, int p) {
        id = i;
        location = l;
        price = p;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    Node* prev;    
    Node* head;     

    BST() {
        root = nullptr;
        prev = nullptr;    
        head = nullptr;    
    }

    void insert(Node* &root, int i, string l, int p) {
        if (root == nullptr) {
            root = new Node(i, l, p);
            return;
        }
        if (i < root->id) {
            insert(root->left, i, l, p);
        } else if (i == root->id) {
            cout << "Duplicates not allowed" << endl;
            return;
        } else {
            insert(root->right, i, l, p);
        }
    }

    void flatenInDll(Node* root) {
        if (root == nullptr) return;
        //performaing in order traversal to flatten B S tree in dll which naturally maintains sorted order
        flatenInDll(root->left);

        if (prev == nullptr) {
            head = root;          
        } else {
            root->left = prev;    
            prev->right = root;   
        }

        prev = root;             
        flatenInDll(root->right);
    }

    // forward traversal of DLL
    void forwardTraversal(Node* head) {
        Node* temp = head;        
        while (temp != nullptr) {
            cout << temp->id << " " << temp->location << " " << temp->price << endl;
            temp = temp->right;   
        }
    }

    // reverse traversal of DLL
    void reverseTraversal(Node* head) {
        if (head == nullptr) return;

        Node* temp = head;

        // move to last node of DLL
        while (temp->right != nullptr) {
            temp = temp->right;
        }

        // now go backwards
        while (temp != nullptr) {
            cout << temp->id << " " << temp->location << " " << temp->price << endl;
            temp = temp->left;
        }
    }
};

int main() {
    BST tree;

    // inserting nodes in BST
    tree.insert(tree.root, 4, "Lahore", 500);   
    tree.insert(tree.root, 2, "Karachi", 200);  
    tree.insert(tree.root, 6, "Islamabad", 600);
    tree.insert(tree.root, 1, "Multan", 100);   
    tree.insert(tree.root, 3, "Pindi", 300);    
    tree.insert(tree.root, 5, "Faisalabad", 450); 
    tree.insert(tree.root, 7, "Quetta", 700);   

    // flatten BST into DLL
    tree.flatenInDll(tree.root);                

    cout << "Forward DLL Traversal:" << endl;
    tree.forwardTraversal(tree.head);           

    cout << "\nReverse DLL Traversal:" << endl;
    tree.reverseTraversal(tree.head);           

    return 0;
}
