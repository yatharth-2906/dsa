// Problem Statement: Given an integer N, check whether it is prime or not. A prime number is a number that is only divisible by 1 and itself and the total number of divisors is 2.

// Input: N = 2

// Output: true

#include <iostream>
#include <cmath>

using namespace std;

void method_1(int n)
{
    if (n <= 1)
    {
        cout << "false" << endl;
        return;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
}

void method_2(int n)
{
    if (n <= 1)
    {
        cout << "false" << endl;
        return;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
}

int main()
{
    int n;
    cin >> n;

    method_1(n); // O( n )
    method_2(n); // O( sqrt(n) )

    return 0;
}
