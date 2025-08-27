// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

// Input: [100, 200, 1, 3, 3, 2, 4]

// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longest_consecutive_sequence(vector<int> &arr, int n)
{
    int res = 0;
    unordered_set<int> elements(arr.begin(), arr.end());

    for (auto it = elements.begin(); it != elements.end(); it++)
    {
        int num = *it;

        if (elements.find(num - 1) == elements.end())
        {
            int temp = 0;
            while (elements.find(num + temp) != elements.end())
                temp++;

            res = max(res, temp);
        }
    }

    return res;
}

int main(void)
{
    vector<int> arr = {100, 4, 200, 1, 3, 3, 2};
    int n = arr.size();

    cout << longest_consecutive_sequence(arr, n); // Time: O(n) Space: O(n)

    return 0;
}