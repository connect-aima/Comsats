#include <iostream>
using namespace std;


void display(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[5] = {1,2,3,4,5};
    int size = 5;

    display(array, size);   
    return 0;
}
