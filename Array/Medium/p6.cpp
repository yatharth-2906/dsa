// Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Input: arr = [3,1,-2,-5,2,-4]

// Output: [3,-2,1,-5,2,-4]

#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int> arr, int n)
{
    vector<int> res(n);
    int pos_index = 0, neg_index = 1, i = 0;

    while (i < n)
    {
        if (arr[i] > 0)
        {
            res[pos_index] = arr[i];
            pos_index = pos_index + 2;
        }

        else
        {
            res[neg_index] = arr[i];
            neg_index = neg_index + 2;
        }

        i++;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    int n = arr.size();

    vector<int> res = rearrangeArray(arr, n); // Time: O(n) Space: O(1)

    cout << "Modified Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";

    return 0;
}