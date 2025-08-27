// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Input Format: [1,0,-1,0,-2,2], target = 0

// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target)
                {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }

                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return res;
}

void print_result(vector<vector<int>> result)
{
    int n = result.size(), m = result[0].size();

    cout<<"[ ";
    for (auto i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j];

            if(j!=m-1)
                cout<<",";
        }
        
        if(i!=n-1)
            cout<<"], ";
        else
            cout<<"]";
    }

    cout<<" ]"<<endl;
}

int main(void)
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(arr, target); // Time: O(n) Space: O(1)

    cout << "The Quads of 4 Sum are: ";
    print_result(result);

    return 0;
}