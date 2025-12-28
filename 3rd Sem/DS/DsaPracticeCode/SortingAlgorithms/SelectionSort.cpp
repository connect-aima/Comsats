#include <iostream>
using namespace std;
void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallest=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                smallest=j;
            }
            swap(arr[i],arr[smallest]);
        }
    }
    //printing sorted array
     for (int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}
int main() {
    int arr[]={3,11,5,7,12,8,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,n);
    
// Double-ended selection sort works by sorting an array from both ends
// at the same time. We start by setting two pointers: one at the beginning
// of the array (`i = 0`) and one at the end (`j = n - 1`). These pointers
// will move inward as we sort. In each round, we assume that the smallest 
// and largest elements in the current range are at the left pointer (`i`).
// Then, we scan the part of the array between k=`i + 1` and k<`j` to find the
// actual smallest and largest elements. Once we find them, we first swap
// the smallest element with the one at the left pointer. If the largest
// element was originally at the left pointer, we adjust its index to 
// where it moved after the swap. Then, we swap the largest element with 
// the one at the right pointer (`j`). After placing the smallest and largest
// elements in their correct positions, we move the left pointer one step right
// and the right pointer one step left, shrinking the unsorted portion of the array.
// We repeat this process until the two pointers cross each other, which means the array
// is fully sorted. In short, each round puts the smallest element at the beginning and
// the largest element at the end, gradually sorting the array from both sides toward 
// the middle.

    //folowing code is for double ended selection sort
    int A[] = {5, 2, 9, 1, 7, 3};
    int n = 6;
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int minIndex = i;
        int maxIndex = i;

        for (int k = i + 1; k <= j; k++)
        {
            if (A[k] < A[minIndex])
                minIndex = k;
            if (A[k] > A[maxIndex])
                maxIndex = k;
        }

        // swap min into A[i]
        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;

        // fix if max was at i
        if (maxIndex == i)
            maxIndex = minIndex;

        // swap max into A[j]
        temp = A[j];
        A[j] = A[maxIndex];
        A[maxIndex] = temp;

        i++;
        j--;
    }
    //printing sorted array
     for (int i=0;i<n;i++){
        cout << A[i] << " " ;
    }
    cout << endl;
    return 0;
}