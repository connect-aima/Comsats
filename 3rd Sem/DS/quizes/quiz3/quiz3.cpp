#include <iostream>
using namespace std;
//question is write a program that will receive an input array and checks if contains max , min heap or niether also your program should be able to receive an element x find it in array and print all lesser values .Check my solution , correct it according to requirments and fill main for all cases..

void checkHeapProperty(int arr[], int n)
{
    bool isMaxHeap = true;  
    bool isMinHeap = true;  

    for (int i = 1; i <= n / 2; ++i)          
    {
        int left  = 2 * i;
        int right = 2 * i + 1;

       
        if ((left <= n && arr[i] < arr[left]) ||
            (right <= n && arr[i] < arr[right]))
        {
            isMaxHeap = false;
        }

        
        if ((left <= n && arr[i] > arr[left]) ||
            (right <= n && arr[i] > arr[right]))
        {
            isMinHeap = false;
        }

      
        if (!isMaxHeap && !isMinHeap) break;
    }

    if (isMaxHeap)
        cout << "Max heap is maintained in given array\n";
    else if (isMinHeap)
        cout << "Min heap is maintained in given array\n";
    else
        cout << "Neither heap is maintained\n";
}

//print lesser values if min heap is maintained 
void lesserValuesInMinHeap(int arr[],int n,int x){
    for (int i=1;i<=n;i++){
        if(arr[i]==x){
            int node=i;
            for (int j=node;j>=1;j--){
                int parent=node/2;
                cout << parent << endl;
            }
        }
    }
}
void lesserValuesInMaxHeap(int arr[],int n,int x){
     for (int i=1;i<=n;i++){
        if(arr[i]==x){
            int node=i;
            for (int j=node;j<=n;j++){
                int left=j*2;
                cout << left << " "  ;
                int right=j*2+1;
                cout << right << " "  ;              
            }
        }
    }
}
int main() {
    int arr[]={1,2,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    //i have passed a accending  array so it should print min
    checkHeapProperty(arr,n);
    lesserValuesInMinHeap(arr,n,4);
    return 0;
}