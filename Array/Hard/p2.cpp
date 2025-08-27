// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Input Format: array[] = {1,2,1,2,2,3,3,1}

// Result: [1,2]

// Explanation: Here we can see that the Count(1) = 3 and Count(2) = 3.
// Therefore, the count of both 1 and 2 is greater than N/3 times. Hence, [1,2] is the answer.

#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();

    // Since there can be only 2 elements with count more than floor(n/3).
    int first_element = INT_MIN, second_element = INT_MIN;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first_element)
            count1++;
        else if (arr[i] == second_element)
            count2++;
        else if (count1 == 0)
        {
            count1 = 1;
            first_element = arr[i];
        }
        else if (count2 == 0)
        {
            count2 = 1;
            second_element = arr[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first_element)
            count1++;

        if (arr[i] == second_element)
            count2++;
    }

    vector<int> res;
    if (count1 > n / 3)
        res.push_back(first_element);
    if (count2 > n / 3)
        res.push_back(second_element);

    return res;
}

void print_array(vector<int> result)
{
    int n = result.size();

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << result[i];

        if(i!=n-1)
            cout<<",";
    }
    cout << "]" << endl;
}

int main(void)
{
    vector<int> arr = {1,2,1,2,2,3,3,1};

    vector<int> result = majorityElement(arr); // Time: O(n) Space: O(1)

    cout<<"The Majority Elements are: ";
    print_array(result);

    return 0;
}