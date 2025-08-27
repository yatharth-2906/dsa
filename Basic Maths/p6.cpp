// Problem Statement: Implement pow(x, n), which calculates x raised to the power n.

// Input format: x = 2.10000, n = 3

// Output: 9.26100

#include <iostream>
#include <vector>

using namespace std;

double powerFunction(double x, int n)
{
    double res = 1;
    long long exp = n;

    if (exp < 0)
    {
        x = 1.0 / x;
        exp = abs(exp);
    }

    while (exp > 0)
    {
        if (exp % 2 != 0)
        {
            res = res * x;
            exp--;
        }

        else
        {
            x = x * x;
            exp = exp / 2;
        }
    }

    return res;
}

int main(void)
{
    double x = 2.1;
    int n = 3;

    cout << "The value of " << x << "^" << n << " is: " << powerFunction(x, n) << endl; // Time: O(log n) Space: O(1)

    return 0;
}