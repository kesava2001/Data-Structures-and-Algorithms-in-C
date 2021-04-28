/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int Sum(int final){
    int sum =  final*(final+1)/2;
    return sum;
}

int MissingUsingSum(int a[], int final, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }
    int diff=Sum(final)-sum;
    return diff;
}

void missing(int a[], int initial, int n){
    int diff=initial-0;
    for(int i=0;i<n;i++){
        if(a[i]-i!=diff){
            cout<<"missing element is "<<diff+i<<endl;
            break;
        }
    }
}

void MultipleMissing(int a[], int initial, int n){
    int diff=initial-0;
    for(int i=0;i<n;i++){
        if(a[i]-i!=diff){
            while(diff<a[i]-i){
                cout<<"missing element is "<<diff+i<<endl;
                diff++;
            }
        }
    }
}

int main()
{
    int b[10]={1,2,3,5,6,7,8,10,11,12};
    int a[10]={1,2,3,4,5,7,8,9,10,11};
    
    missing(a, 1, 10);
    MultipleMissing(b, 1, 10);
    cout<<MissingUsingSum(a, 11, 10)<<endl;
    
    return 0;
}
