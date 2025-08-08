// Problem Statement: Given two integers N1 and N2, find their greatest common divisor.

// Input: N1 = 9, N2 = 12
                    
// Output: 3

#include <iostream>

using namespace std;

int method_1(int x, int y)
{
    int n = min(x,y), result = 1;

    for(int i=1; i<=n; i++)
    {
        if((x%i == 0) && (y%i == 0))
        {
            result = i;
        }
    }

    return result;
}

int method_2(int x, int y)
{
    int n = min(x,y);

    for(int i=n; i>=1; i--)
    {
        if((x%i == 0) && (y%i == 0))
        {
            return i;
        }
    }

    return 1;
}

int method_3(int x, int y)
{
    if(x==0)
        return y;
    
    if(y==0)
        return x;
    
    if(x>y)
        return method_3(x-y, y);
    else
        return method_3(x, y-x);
}

int main(void)
{
    int x, y;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    cout<<"The gcd of "<<x<<" and "<<y<<" is: "<<method_1(x,y)<<endl; // O(min(x,y))
    cout<<"The gcd of "<<x<<" and "<<y<<" is: "<<method_2(x,y)<<endl; // O(min(x,y))
    cout<<"The gcd of "<<x<<" and "<<y<<" is: "<<method_3(x,y)<<endl; // O(min(x,y)) -> Most Optimal

    return 0;
}