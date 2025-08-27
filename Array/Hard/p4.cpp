// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. 
// Each integer appears exactly once except A which appears twice and B which is missing. 
// The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Input:  array[] = {3,1,2,5,3}

// Result: {3,4}

#include <iostream>
#include <vector>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> arr){
    int n = arr.size();

    long long sum1 = 0, sum2 = 0;
    long long expected_sum1 = 1LL*n*(n+1)/2LL, expected_sum2 = (1LL*n*(n+1)*(2*n+1))/6LL;

    for(int i=0; i<n; i++){
        sum1 = sum1 + 1LL*arr[i];

        sum2 = sum2 + (1LL*arr[i])*(1LL*arr[i]);
    }

    long long repeated = ( (sum2 - expected_sum2)/(sum1 - expected_sum1) + (sum1 - expected_sum1) )/2LL;
    long long missing = repeated - (sum1 - expected_sum1);

    return {(int)repeated, (int)missing};
}

int main(void)
{
    vector<int> arr = {3,1,2,5,3};

    vector<int> result = findMissingRepeatingNumbers(arr); // Time: O(n) Space: O(1)

    cout<<"The missing number is: "<<result[1]<<endl;
    cout<<"The repeated number is: "<<result[0]<<endl;

    return 0;
}