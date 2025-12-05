#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
  string name;
  Node *left;
  Node *right;

 Node(string n){
    name=n;
    left=right=nullptr;
 }
};
Node *buildTree(vector<string> &preorder, vector<string> &postorder,
                int &preIndex, int postStart, int postEnd) {

  //1st consition  is for leftsubtree and second condition becomes true in case of right subtree post start and post end both are 7
  if (preIndex >= preorder.size() || postStart > postEnd)
    return nullptr;

  // Create current root using preorder
  Node *root = new Node(preorder[preIndex]);
  preIndex++; // Move to next element in preorder

  // If only one element exists in this postorder segment → leaf node
  if (postStart == postEnd)
    return root;

  // The next element in preorder is always root of left subtree
  string leftSubtreeRoot = preorder[preIndex];

  // Search for this element in postorder to determine left subtree boundary
  int index = -1;
  for (int i = postStart; i <= postEnd; i++) {
    if (postorder[i] == leftSubtreeRoot) {
      index = i;
      break;
    }
  }

  // Recursively build left subtree (from postStart to index)
  root->left = buildTree(preorder, postorder, preIndex, postStart, index);

  // Recursively build right subtree (index+1 to postEnd-1)
  root->right =
      buildTree(preorder, postorder, preIndex, index + 1, postEnd - 1);

  return root;
}

void printLevelOrder(Node *root) {
  if (!root)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();

   
    while (levelSize--) {
      Node *current = q.front();
      q.pop();

      cout << current->name << " ";

      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }
    cout << endl;
  }
}


int main() {

  
  vector<string> preorder = {"CEO",  "Manager1", "TeamLead1",
                             "Dev1", "Dev2",     "TeamLead2",
                             "Dev3", "Dev4",     "Manager2"};

  vector<string> postorder = {"Dev1",     "Dev2",     "TeamLead1",
                              "Dev3",     "Dev4",     "TeamLead2",
                              "Manager1", "Manager2", "CEO"};

  
  int preIndex = 0;

  
  Node *root =
      buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1);

  
  cout << "Company Hierarchy (Level Order):\n";
  printLevelOrder(root);

  return 0;
}