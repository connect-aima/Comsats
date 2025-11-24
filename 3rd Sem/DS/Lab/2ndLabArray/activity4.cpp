#include <iostream>
using namespace std;

int main()
{
    int array[6] = {1, 2, 3, 4, 5};
    int size = 5;
    int pos = 3;
    int mem = 99;
    for (int i = size-1; i >= pos; i--)
    {
        array[i + 1] = array[i];
    }
    array[pos] = mem;
    size++;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
