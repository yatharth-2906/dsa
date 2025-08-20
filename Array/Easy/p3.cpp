// Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

// Example 1:
// Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
// Output: 6 7 1 2 3 4 5

// Example 2:
// Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left
// Output: 9 10 11 3 7 8

#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void left_rotate_array(vector<int> &arr, int n, int k)
{
    reverse_array(arr, 0, k - 1);
    reverse_array(arr, k, n - 1);
    reverse_array(arr, 0, n - 1);
}

void right_rotate_array(vector<int> &arr, int n, int k)
{
    int d = n - k;
    reverse_array(arr, 0, d - 1);
    reverse_array(arr, d, n - 1);
    reverse_array(arr, 0, n - 1);
}

int main(void)
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int n1 = arr1.size();

    vector<int> arr2 = {3, 7, 8, 9, 10, 11};
    int n2 = arr2.size();

    left_rotate_array(arr2, n2, 3);  // Time: O(n) Space: O(1)
    right_rotate_array(arr1, n1, 2); // Time: O(n) Space: O(1)

    cout << "Rotated array: \n";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout<<endl<<endl;

    cout << "Rotated array: \n";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout<<endl;

    return 0;
}