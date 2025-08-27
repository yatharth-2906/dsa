// Problem Statement: Given an integer n, return the number of prime numbers that lie in the range [1,n].

// Input format: n = 11

// Output: 5

// Explanation: There are 5 prime numbers in the range [1,11]. They are 2, 3, 5, 7 and 11.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i; i * j <= n; j++)
            {
                isPrime[i * j] = false;
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (isPrime[i])
            res++;
    }

    return res;
}

int main(void)
{
    int n = 11;

    cout<<"The number of prime numbers from 1 to "<<n<<" are: "<<countPrimes(n)<<endl; // Time: O(n*log(log(n))) Space: O(n)

    return 0;
}