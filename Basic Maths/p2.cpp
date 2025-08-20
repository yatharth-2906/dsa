// Problem Statement: Given an integer N return the reverse of the given number.

// Input: N = 12345

// Output: 54321

#include <iostream>

using namespace std;

int method_1(int n)
{
    int reverse = 0;

    while (n != 0)
    {
        int rem = n % 10;

        if ((reverse > INT_MAX / 10) || (reverse < INT_MIN / 10))
            return 0;

        reverse = reverse * 10 + rem;
        n = n / 10;
    }

    return reverse;
}

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout<<"The reverse of "<<n<<" is: "<<method_1(n); // Time: O(log10(n) + 1) Space: O(1)

    return 0;
}