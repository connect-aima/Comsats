#include <iostream>
using namespace std;
class Node{
    public:
    int data; 
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

class BST{
    Node* root;
    public:
    Node* insert(Node* &root,int val){
        if(root==nullptr){
            root = new Node(val);
            return root;
        }
        if(val<root->data){
            insert(root->left,val);
        }else if(val==root->data){
            cout << "Duplicates not allowed" << endl;
            return root;
        }else{
            insert(root->right,val);
        }
        return root;
    }

    //building bst through array
    Node* buildBST(int arr[],int n){
        Node* root=nullptr;//if any old values are there we will delete them and start fresh from array elements
        for(int i=0;i<n;i++){
           insert(root,arr[i]);
        }
        return root;
    }
    void search(Node* &root,int key){
        if(root==nullptr){
            cout << "Not Found" <<endl;
            return;
        }
        if(root->data==key){
            cout << "Data Found" <<endl;
            return;
        }else if(root->data<key){
            search(root->right,key);
        }else if(root->data>key){
            search(root->left,key);
        }else{
            cout << "Data Not Found" <<endl;
            return;
        }
       
    }
    //helper function to get in order successor for deletion of node that has two child
    Node* getInOrderSuccesor(Node* &root){
        while(root!=nullptr&&root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    //function to delete a node
    Node* delNode(Node* &root,int key){
        if(root==nullptr){
            return nullptr;
        }
        if(key<root->data){
            root->left=delNode(root->left,key);
        }else if(key>root->data){
            root->right=delNode(root->right,key);
        }else{
            //actual deletion logic that covers both 0 and 1 child conditions
            //key==root
            if(root->left==nullptr){
                Node* temp=root->right;
                delete root;
                return temp;
            }else if(root->right==nullptr){
                Node* temp=root->left;
                delete root;
                return temp;
            }else{
                //root to be deleted has two childdren
                //we get inorder succesor of root (left most node in right subtree) with helper function
                Node* IS=getInOrderSuccesor(root->right);
                //replacing data of root with data of that successor
                root->data=IS->data;
                //deleting that 
                root->right=delNode(root->right,IS->data);
            }
        }
        return root;
    }
    //print data in sorted order {left,right,root}
    void inorder(Node* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    //pre orderder traversal {root,left,right}
     void preorder(Node* root){
        if(root==nullptr){
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    //post order traversal {left,right,root}
     void postorder(Node* root){
        if(root==nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

};
int main() {
    BST tree;
    int arr[]={5,1,3,4,2,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root=tree.buildBST(arr,n);
    cout << "In order traversal of given array" << endl;
    tree.inorder(root);
    cout <<endl;
    cout << "Pre order traversal of given array" << endl;
    tree.preorder(root);
    cout <<endl;
    cout << "Post order traversal of given array" << endl;
    tree.postorder(root);
    cout <<endl;
    cout << "Testing searching algorithm" << endl;
    tree.search(root,4);
    tree.search(root,44);
    //checking deltion logic
    cout << "In order traversal of given array before deletion" << endl;
    tree.inorder(root);
    cout <<endl;
    tree.delNode(root,4);
     cout << "In order traversal of given array after deletion" << endl;
    tree.inorder(root);
    cout <<endl;
    return 0;
}
//we also have avl roations in this topic 