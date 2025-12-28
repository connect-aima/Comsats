#include <iostream>
using namespace std;
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i]; // mark current element
        int prev = i - 1;  // mark previous index
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev]; // move prev element forward by 1 step
            prev--;
        }
        arr[prev + 1] = curr; // increment prev cuz it is right position of current
    }
    // printing sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swapBasedInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int prev = i - 1; // mark prev element for each iteration
        while (prev >= 0 && arr[prev] > arr[prev + 1])
        { // from prev, loop backwards and compare prev to next and swap if next is small
            swap(arr[prev + 1], arr[prev]);
            prev--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// helper function for binary search based insertion sort to give corret position
int findInsertPosition(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid + 1;      // insert after duplicates

        else if (arr[mid] < key)
            low = mid + 1;       // go right
        else
            high = mid - 1;      // go left
    }
    return low;                  // correct insertion index
}
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {

        int key = arr[i];

        // find correct position in sorted part arr[0 .. i-1]
        int pos = findInsertPosition(arr, 0, i - 1, key);

        // shift elements to make space
        int j = i - 1;
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[pos] = key;
    }
     for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 11, 5, 7, 12, 8, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    swapBasedInsertionSort(arr, n);
    binaryInsertionSort(arr,n);
    return 0;
}