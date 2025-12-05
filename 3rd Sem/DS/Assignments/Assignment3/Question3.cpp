#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int id;
    string productName;
    int amount;
    string timeStamp;
    Node* left;
    Node* right;

    Node(int i, string pN, int a, string tS) {
        id = i;
        productName = pN;
        amount = a;
        timeStamp = tS;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert node using amount as key
    void insert(Node*& root, int i, string pN, int a, string tS) {
        if (root == nullptr) {
            root = new Node(i, pN, a, tS);
            return;
        }
        if (a < root->amount)
            insert(root->left, i, pN, a, tS);
        else
            insert(root->right, i, pN, a, tS);
    }

    // Inorder traversal
    void inOrder(Node* root) {
        if (!root) return;
        inOrder(root->left);
        cout << root->id << " " << root->productName << " " << root->amount << " " << root->timeStamp << endl;
        inOrder(root->right);
    }

    // Get inorder successor
    Node* getSuccessor(Node* root) {
        Node* temp = root;
        while (temp && temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    // Delete node by amount
    Node* deleteNode(Node* root, int amount) {
        if (root == nullptr) return nullptr;

        if (amount < root->amount) {
            root->left = deleteNode(root->left, amount);
        }
        else if (amount > root->amount) {
            root->right = deleteNode(root->right, amount);
        }
        else {
            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* succ = getSuccessor(root->right);
            root->amount = succ->amount;
            root->right = deleteNode(root->right, succ->amount);
        }
        return root;
    }

    // Extract amounts to array
    void extract(Node* root, vector<int>& arr) {
        if (!root) return;
        extract(root->left, arr);
        arr.push_back(root->amount);
        extract(root->right, arr);
    }

    // Heapify (Max)
    void heapifyDown(vector<int>& arr, int n, int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(arr, n, largest);
        }
    }

    // Build max heap
    void buildMaxHeap(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyDown(arr, n, i);
    }

    // Heap Sort (ascending)
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        buildMaxHeap(arr);

        for (int i = n - 1; i >= 1; i--) {
            swap(arr[0], arr[i]);
            heapifyDown(arr, i, 0);
        }
    }
};

int main() {
    BST tree;

    // Insert transactions
    tree.insert(tree.root, 1, "ProductA", 4500, "2025-11-30 10:00");
    tree.insert(tree.root, 2, "ProductB", 2200, "2025-11-30 10:05");
    tree.insert(tree.root, 3, "ProductC", 5000, "2025-11-30 10:10");
    tree.insert(tree.root, 4, "ProductD", 1800, "2025-11-30 10:15");
    tree.insert(tree.root, 5, "ProductE", 3000, "2025-11-30 10:20");
    tree.insert(tree.root, 6, "ProductF", 4700, "2025-11-30 10:25");
    tree.insert(tree.root, 7, "ProductG", 5100, "2025-11-30 10:30");
    tree.insert(tree.root, 8, "ProductH", 2600, "2025-11-30 10:35");
    tree.insert(tree.root, 9, "ProductI", 1900, "2025-11-30 10:40");

    cout << "\nBST Before Deletion:\n";
    tree.inOrder(tree.root);

    // Delete 3000 and 5000
    tree.root = tree.deleteNode(tree.root, 3000);
    tree.root = tree.deleteNode(tree.root, 5000);

    cout << "\nBST After Deletion:\n";
    tree.inOrder(tree.root);

    // Extract remaining amounts
    vector<int> arr;
    tree.extract(tree.root, arr);

    // Heap sort
    tree.heapSort(arr);

    cout << "\nTransaction Amounts in Descending Order:\n";
    for (int i = arr.size() - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
