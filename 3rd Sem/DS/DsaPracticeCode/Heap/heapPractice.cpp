#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size = 0;

    // inserting values in heap
    void insert(int val)
    {
        // insert value at last and keep swapping from parent to maintain heap property
        size++;           // increase size first bcz 1 based indexing
        int index = size; // index is position where we are supposed to insert new value which is equal to size
        arr[index] = val; // store that value at that index

        while (index > 1)
        {
            // maintaining max heap
            int parent = index / 2;       // mark parent
            if (arr[parent] < arr[index]) // check if parent is less then swap it from its child
            {
                swap(arr[parent], arr[index]);
                index = parent; // move index to parent
            }
            else
            {
                return;
            }
        }
    }

    // deletion from heap
    // deletion from heap work as deletion in priority queue
    // top most value gets deleted and remaining values adjust
    // according to defined heap property
    void deleteFromHeap()
    {
        // checking if heap exists or not
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size]; // replacing first(root) index from last one
        size--;             // deleting last index (decreasing size)
        // code for propagating root to its correct condition maintain heap property
        int i = 1; // mark root as i
        while (true)
        {
            // mark left and right child
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i; // assume root is largest
            if (left < size && arr[i] < arr[left])
            {                   // check if left exists and element at i is smaller than element at left
                largest = left; // mark left as largest
            }
            if (right < size && arr[i] < arr[right])
            {                    // check if right exists and element at i is smaller than element at right
                largest = right; // mark right as largest
            }
            // if parent is already largest,means i is not shifted to left or right heap property is correct then break
            if (largest == i)
                break;
            // swap element at i from element at largest irrespective of left and right and move i in to that direction
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
    // printing values
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
// Heapify down is the process of taking a node and pushing it downward 
//in the heap until the heap property is fixed.
    void heapifyDown(int arr[], int n, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifyDown(arr,n,largest);
    }
}

//code for sorting an array acceending order in which max heap is already created
void heapSort(int arr[],int n) {
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]); //swap last elemen from first element
        size--; // decrease size
        heapifyDown(arr,size,1);
    }
}
};


int main()
{
    Heap h;
    h.insert(50);
    h.insert(60);
    h.insert(100);
    h.insert(10);
    h.insert(5);
    h.insert(12);
    h.print();
    h.deleteFromHeap();
    h.print();
    //Following code will make a max heap into a normal array {building heap using heapify algorithm}
    int arr[6]={0,11,2,3,23,55};
    int n=5;
    for (int i=n/2;i>0;i--){
        h.heapifyDown(arr,n,i);
    }
    cout << "Max heapified array is as follows:" << endl;
    //printing heapified array now
    for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    //sorting this array in accendin order in which max heap is already created.
    h.heapSort(arr,5);
    //printing accending sorted array now
    cout << "Sorted array is as follows (accending sort using max heapified array)" << endl;
    for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    return 0;
}