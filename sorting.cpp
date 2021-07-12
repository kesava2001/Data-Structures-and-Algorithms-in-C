/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void Display(int a[], int n)
{
    for(int x=0; x<n; x++) cout<<a[x]<<" ";
    cout<<endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int a[], int n)
{
    int swap_count=0;
    for(int i=0; i<n-1; i++)
    {
        int flag=0;
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1]) swap(a[j], a[j+1]), flag=1, swap_count++;
            break;
        }
        if(!flag) break;
    }
    //cout<<swap_count<<endl;
}

void InsertionSort(int a[], int n)
{
    int j, v;
    for(int i=1; i<n; i++)
    {
        v=a[i];
        j=i;
        while(a[j-1]>v && j>=1)
        {
            a[j]=a[j-1], j--;
        }
        a[j]=v;
    }
}

void SelectionSort(int a[], int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min]) min=j;
        }
        swap(a[i], a[min]);
    }
}



int main()
{
    int a[5] = {5,4,3,2,1};
    int b[5] = {5,4,3,2,1};
    int c[5] = {10,5,9,7,6};
    //BubbleSort(a, 5);
    //Display(a, 5);
    InsertionSort(c, 5);
    //SelectionSort(b, 5);
    Display(c, 5);
    //Display(b, 5);

    return 0;
}
