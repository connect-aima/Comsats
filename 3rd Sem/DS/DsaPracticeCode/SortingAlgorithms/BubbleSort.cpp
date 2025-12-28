#include <iostream>
using namespace std;
void bubbleSort1(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    // printing sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// BubbleSort2 works just like the normal bubble sort, but it has two smart improvements that make 
// it faster. First, it uses a **flag** to check whether any swap happened during a pass. At the start
// of each pass, the flag is set to false. While scanning the array, if two elements are out of order,
// they are swapped and the flag becomes true. If the whole pass finishes with **no swaps**, it 
// means the array is already sorted, so the algorithm immediately stops instead of doing unnecessary
// extra passes. The second improvement is the **count** variable, which keeps track of how much of
// the array still needs to be checked. After every full pass, the largest remaining element has 
// already moved to its correct position at the end, so we reduce the range (`count--`) and avoid 
// checking that sorted part again. Together, these two changes make BubbleSort2 more efficient 
// than the basic version: it stops early when the array becomes sorted and it gradually shortens
// the checking range, reducing extra comparisons. This means it is much faster on already sorted
// or nearly sorted lists, while still working correctly on any input.

void BubbleSort2(int arr[], int n) {
    bool flag = true;         // 1
    int count = n;            // 2

    while (flag && count > 1) { // 3
        flag = false;           // 4
        for (int i = 0; i < count - 1; i++) { // 5
            if (arr[i] > arr[i + 1]) {       // 6
                swap(arr[i], arr[i + 1]);    // 7
                flag = true;                 // 8
            }
        }
        count--;  // reduce effective range       // 9
    }
}
// BubbleSort3, also called Cocktail Sort, is an improved version of the normal Bubble Sort.
//  The normal Bubble Sort moves through the list only in one direction—from left to right—so
//   in each pass it pushes the largest number to the end. Cocktail Sort improves this by moving 
//   in both directions during each full cycle. This means it first moves from right to left, pushing 
//   the smallest number to the beginning, and then moves from left to right, pushing the largest 
//   number to the end. Because it “shakes” the list in both directions like a cocktail shaker, small
//    numbers reach the front faster and big numbers reach the end faster. As a result, the algorithm 
//    becomes more efficient when the list is partially sorted or when small and large elements are
//     scattered far away from their correct positions. The algorithm keeps adjusting the left and 
//     right boundaries as elements settle into their correct places, reducing the area it needs to
//      check. The process continues until no more swaps are needed, which means the list is fully 
//      sorted.
void BubbleSort3(int arr[], int n) {
    int L = 1;
    int R = n - 1;
    int K = n - 1;

    while (L <= R) {

        // Pass 1: Right to Left
        for (int j = R; j >= L; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                K = j;
            }
        }
        L = K + 1;

        // Pass 2: Left to Right
        for (int j = L; j <= R; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                K = j;
            }
        }
        R = K - 1;
    }
}


int main() {
     int arr[] = {3, 11, 5, 7, 12, 8, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort1(arr,n);
    return 0;
}