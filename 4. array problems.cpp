#include <stdio.h>
#include <iostream>
using namespace std;

//finding number of duplicates in a sorted array
void CountingDuplicates(int a[], int n){
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            int j=i+1;
            while(a[j]==a[i]){
                j++;
            }
            cout<<a[i]<<" has "<<j-i<<" duplicates"<<endl;
            i=j;
        }
    }
}

//finding duplicates in unsorted array
void DuplicateUnSorted(int a[], int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]&&a[j]!=-1){
                //cout<<a[j]<<endl;
                a[j]=-1;
                count=count +1;
            }
        }
        if(a[i]!=-1){
            cout<<a[i]<<" has "<<count<<" number of duplicates"<<endl;
        }
    }
}

//finding a pair of elements with sum k in an array
void SumK(int a[], int n, int Sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==Sum){
                cout<< a[i]<<" and "<<a[j]<<" gives the "<<Sum<<endl;
            }
        }
    }
}

//finding a pair of elements with sum k in an soted array
void SumKSorted(int a[], int n, int Sum){
    for(int i=0, j=n-1;i<n, j>0;i++, j--){
        if(a[j]>Sum){
            j--;
        }else if(a[i]<Sum && a[i]+a[j]>Sum){
            j--;
        }else if(a[j]<Sum && a[i]+a[j]>Sum){
            i++;
        }else{
            cout<<a[i]<<" + "<<a[j]<<" = "<<Sum<<endl;
            i++, j--;
        }
    }
}
int main()
{
    int a[10]={1,2,3,3,3,4,5,5,6,7};
    int b[10]={7,5,3,5,7,5,1,3,5,7};
    //DuplicateUnSorted(b, 10);
    SumKSorted(a, 10, 6);
    return 0;
}