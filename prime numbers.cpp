#include <stdio.h>
#include <iostream>
using namespace std;

void PrimeBetween(int n, int m)
{
    int i=0,j=0;
    for(j=n;j<=m;j++)
    {
        for(i=2;i<j;i++)
        {
            if(j%i==0)
            {
                break;
            }
        }
        if(i==j)
        {
            cout<<i<<" ";
        }
    }
}

void isPrime(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<"Number is not prime"<<endl;
            break;
        }
    }
    if(i==n)
    {
        cout<<"Number is prime"<<endl;
    }
}

int main()
{
    // isPrime(20);
    PrimeBetween(10, 20);

    return 0;
}
