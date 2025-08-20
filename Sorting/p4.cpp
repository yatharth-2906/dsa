// Problem:  Given an array of size n, sort the array using Merge Sort.

// Input: N=7,arr[]={3,2,8,5,1,4,23}

// Output: 1,2,3,4,5,8,23

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> result;

    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            result.push_back(arr[i++]);
        else
            result.push_back(arr[j++]);
    }

    while (i <= mid)
        result.push_back(arr[i++]);

    while (j <= end)
        result.push_back(arr[j++]);

    for (int k = start; k <= end; k++)
        arr[k] = result[k - start];
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (end <= start)
        return;

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main(void)
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    merge_sort(arr, 0, n-1); // Time: O(log n) Space: O(n)

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}