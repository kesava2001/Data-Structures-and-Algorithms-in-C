/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

void MergeUnion(int a[], int lenA, int b[], int lenB, int *c){
    int i=0,j=0,k=0;
    while(i<lenA&&j<lenB){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++, k++;
        }else if(a[i]==b[j]){
            c[k]=a[i];
            i++, j++, k++;
        }else{
            c[k]=b[j];
            j++, k++;
            
        }
    }
}

void MergeIntersection(int a[], int lenA, int b[], int lenB, int *c){
    int i=0, j=0, k=0;
    while(i<lenA && j<lenB){
        if(a[i]<b[j]){
            i++;
        }else if(a[i]==b[j]){
            c[k]=a[i];
            i++, j++, k++;
        }else{
            j++;
        }
    }
}

int main()
{
    int a[5]={3,4,5,6,10};
    int b[5]={2,4,5,7,12};
    int c[10]={};
    int d[10]={};
    int *p=c, *q=d;
    //MergeUnion(a, 5, b, 5, p);
    MergeIntersection(a, 5, b, 5, q);
    for(int i=0;i<10;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
