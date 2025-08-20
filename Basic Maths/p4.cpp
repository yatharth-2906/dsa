// Problem Statement: Given an integer N, return all divisors of N.

// Input: N = 36

// Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void method_1(int n)
{
    vector<int> divisors;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            divisors.push_back(i);
    }

    cout << "The divisors of " << n << " are: [ ";
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i];
        if (i < divisors.size() - 1)
            cout << ", ";
    }
    cout << " ]" << endl;
}

void method_2(int n)
{
    int sqrt_n = sqrt(n);
    vector<int> divisors;

    for (int i = 1; i <= sqrt_n; i++)
    {
        if (n % i == 0)
            divisors.push_back(i);
    }

    int t = divisors.size();
    for (int i = t - 1; i >= 0; i--)
    {
        if (divisors[i] != n / divisors[i])
            divisors.push_back(n / divisors[i]);
    }

    cout << "The divisors of " << n << " are: [ ";
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i];
        if (i < divisors.size() - 1)
            cout << ", ";
    }
    cout << " ]" << endl;
}

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    method_1(n); // Time: O(n) Space: O(2*sqrt(n))
    method_2(n); // Time: O(sqrt(n)) Space: O(2*sqrt(n))

    return 0;
}