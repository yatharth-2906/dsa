// Input Format: N = 3

// Result:
//   *
//  ***
// *****
// *****
//  ***
//   *

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int stars = 1, space = n - stars;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= space; j++)
            cout << " ";

        for (int k = 1; k <= stars; k++)
            cout << "*";

        cout << endl;

        stars = stars + 2;
        space = space - 1;
    }

    stars = stars - 2;
    space = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= space; j++)
            cout << " ";

        for (int k = 1; k <= stars; k++)
            cout << "*";

        cout << endl;

        stars = stars - 2;
        space = space + 1;
    }
}