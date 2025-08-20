// Problem Statement: Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// Input: N = 3, nums[] = {3,2,3}

// Output: 3

#include <iostream>
#include <vector>

using namespace std;

int majority_element(vector<int> &arr, int n)
{
    int element = arr[0], count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            count++;
        else
        {
            if (count > 0)
                count--;
            else
            {
                element = arr[i];
                count = 1;
            }
        }
    }

    return element;
}

int main(void)
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int n = arr.size();

    cout << majority_element(arr, n) << endl; // Time: O(n) Space: O(1)

    return 0;
}