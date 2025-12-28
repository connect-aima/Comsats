#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st;      // starting index of left haft
    int j = mid + 1; // starting index of  right half
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    // copy temp in original array
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + st] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // left half
        merge(arr, st, mid, end);
    }
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr, 0, arr.size() - 1);
    // printing sorted array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}



void mergeBU(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid;

    while (i < mid && j < r) {
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i < mid) temp.push_back(arr[i++]);
    while (j < r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size, n);
            int right = min(left + 2 * size, n);
            mergeBU(arr, left, mid, right);
        }
    }
}



void merge3(vector<int>& arr, int p, int q1, int q2, int r) {
    vector<int> temp;

    int i = p, j = q1 + 1, k = q2 + 1;

    while (i <= q1 || j <= q2 || k <= r) {
        int a = (i <= q1 ? arr[i] : INT_MAX);
        int b = (j <= q2 ? arr[j] : INT_MAX);
        int c = (k <= r ? arr[k] : INT_MAX);

        if (a <= b && a <= c) temp.push_back(arr[i++]);
        else if (b <= a && b <= c) temp.push_back(arr[j++]);
        else temp.push_back(arr[k++]);
    }

    for (int t = 0; t < temp.size(); t++)
        arr[p + t] = temp[t];
}

void mergeSort3(vector<int>& arr, int p, int r) {
    if (p < r) {
        int n = r - p + 1;
        int q1 = p + (n / 3) - 1;
        int q2 = p + 2 * (n / 3) - 1;

        mergeSort3(arr, p, q1);
        mergeSort3(arr, q1 + 1, q2);
        mergeSort3(arr, q2 + 1, r);

        merge3(arr, p, q1, q2, r);
    }
}
