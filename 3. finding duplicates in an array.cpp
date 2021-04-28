/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

//finding duplicate in a sorted array

void DuplicateSorted(int a[], int n){
    int i=0;
    while(i<n){
        if(a[i]==a[i+1]){
            cout<<a[i+1]<<endl;
        }
        i++;
    }
}

//finding duplicates in unsorted array
//only works when there is only one duplicate
void DuplicateUnSorted(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                cout<<a[j]<<endl;
            }
        }
    }
}

int main()
{
    int arr[10]={2,3,3,4,5,5,5,6,7,8};
    int b[10]={3,1,2,4,1,5,3,7,4,2};
    //DuplicateSorted(arr, 10);
    DuplicateUnSorted(b,10);

    return 0;
}
