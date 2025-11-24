#include <iostream>
using namespace std;

void swap(int array[],int size,int num1,int num2){
        for (int i=0;i<size;i++){
        int temp = array[num1];
        array[num1]=array[num2];
        array[num2]=temp;
    }
}

int main() {
    int array[5] = {1,2,3,4,5};
    int size = 5;
    int num1;
    cout<< "Enter index of element 1 you want to exchange";
    cin >> num1;
    int num2;
    cout<< "Enter index of element 2 you want to exchange";
    cin >> num2;
    swap(array,5,num1,num2);
    //code for displaying array 
    for (int i=0 ;i<size;i++){
        cout << array[i] << " ";
    }   
    return 0;
}