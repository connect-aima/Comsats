#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = nullptr;
    }
};

class BST
{
    Node *root;

    BST()
    {
        root == nullptr;
    }

    Node *insert(Node* root)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node(val);
            root = newNode;
            return root;
        }else if(root->data < val){
            insert(root->left);
        }else{
            insert(root->right);
        }
        return root;
    }
};
int main()
{

    return 0;
}