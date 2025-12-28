#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;  // not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};  // must be sorted
    int n = 5;
    int key = 7;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Found at index " << index;
    else
        cout << "Not found";

    return 0;
}
