// Problem Statement: Given an array of integers arr[] and an integer target.
// Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14

// Result: [1, 3] (for 2nd variant)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int> arr, int n, int target)
{
    unordered_map<int, int> element_indices;

    for(int i=0; i<n; i++){
        int k = target - arr[i];

        if(element_indices.find(k) != element_indices.end())
            return {element_indices[k], i};
        
        element_indices[arr[i]] = i;    
    }

    return {-1, -1};
}

int main(void)
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int n = arr.size();

    vector<int> result = two_sum(arr, n, 14); // Time: O(n) Space: O(n)
    cout<<result[0]<<" "<<result[1]<<endl;

    return 0;
}