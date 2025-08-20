// Problem Statement: You are given an array of integers, your task is to move all the zeros in
// the array to the end of the array and move non-zero integers to the front by maintaining their order.

// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1

// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0

#include <iostream>
#include <vector>

using namespace std;

void move_zeroes_to_end(vector<int> &arr, int n)
{
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }

        else
            j++;
    }
}

int main(void)
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = arr.size();

    move_zeroes_to_end(arr, n); // Time: O(n) Space: O(1)

    cout << "Modified array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}