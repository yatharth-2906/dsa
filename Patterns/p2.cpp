// Input Format: N = 3

// Result:
// ******
// **  **
// *    *
// *    *
// **  **
// ******

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int stars = n, space = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= stars; j++)
            cout << "*";

        for (int k = 1; k <= space; k++)
            cout << " ";

        for (int l = 1; l <= stars; l++)
            cout << "*";
        
        cout<<endl;
        stars = stars - 1;
        space = space + 2;
    }

    stars = 1, space = 2*n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= stars; j++)
            cout << "*";

        for (int k = 1; k <= space; k++)
            cout << " ";

        for (int l = 1; l <= stars; l++)
            cout << "*";
        
        cout<<endl;
        stars = stars + 1;
        space = space - 2;
    }
}