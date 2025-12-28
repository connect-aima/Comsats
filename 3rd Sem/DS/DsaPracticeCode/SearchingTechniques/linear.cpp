#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // found
        }
    }
    return -1;  // not found
}

int main() {
    int arr[] = {4, 7, 1, 9, 3};
    int n = 5;
    int key = 9;

    int index = linearSearch(arr, n, key);

    if (index != -1)
        cout << "Found at index " << index;
    else
        cout << "Not found";

    return 0;
}
