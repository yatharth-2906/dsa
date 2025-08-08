// Problem Statement: Given an integer N, return the number of digits in N.

// Input: N = 68921

// Output: 5

#include <iostream>
#include <cmath>

using namespace std;

void method_1(int n)
{
    int a = n;
    int len = 0;

    while (n > 0)
    {
        n = n / 10;
        len++;
    }

    cout << "Number of digits in " << a << " is: " << len << endl;

    // Time Comeplexity Explaination:
    // In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations
    // and then we go for an extra iterarion while checking for N>0 so + 1.
}

void method_2(int n)
{
    int a = n;
    int len = log10(n) + 1;

    cout << "Number of digits in " << a << " is: " << len << endl;
}

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    method_1(n); // O(log10(n) + 1)
    method_2(n); // O(1)

    return 0;
}