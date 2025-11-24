//Q#4: Warehouse Inventory Stacking Simulator (Application of Stack)
// A logistics company uses robotic arms to stack and unstack boxes in a warehouse. To maintain safety, no heavier box may be placed
// on a lighter one. When a new box arrives:
// • If it’s lighter than the top box → push it.
// • If it’s heavier → repeatedly pop boxes until a heavier or equal box is found, then push it.
// Display the final stack configuration from top (lightest) to bottom (heaviest). This models warehouse stacking algorithms used in
// robotic sorting.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int length;
    int num;
    cout << "How many boxes you want to enter? " << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter weight of box " << i + 1 << ": " << endl;
        cin >> num;
        if (st.empty() || st.top() > num)
        {
            st.push(num);
        }
        else
        {
            while (!st.empty() && st.top() < num)
            {
                st.pop();
            }
            st.push(num);
        }
    }
    // displaying stack numbers
    cout << "\nFinal stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}