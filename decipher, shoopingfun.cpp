#include <iostream>

using namespace std;

// 32
// 1 2 3 4 5
// 2 3 4 5 6 
// 3 4 5 6 7
// 4 5 6 7 8
// 5 6 7 8 
// 6 7 8 9 
// 7 8 9 10 
// given the number D(32 say) return the sum of the above numbers
int shoppingfun(int D)
{
    int n=D/7, r=D%7, res=0;
    res+=n*28;
    for(int i=1; i<n; i++)
    {
        res+=7*i;
    }
    int d=D-n*7;
    res+=d*(d+1)/2;
    res+=r*n;
    return res;
}

//smallest permutation of the given number, decipher
int decipher(int key)
{
    int arr[10]={0};
    while(key!=0)
    {
        int x=key%10;
        arr[x]++;
        key/=10;
    }
    int res=0;
    
    for(int i=0; i<10; i++)
    {
        while(arr[i]!=0)
        {
            res=res*10+i;
            arr[i]--;
        }
    }
    return res;
}

int main()
{
    cout<<decipher(103)<<endl;
    return 0;
}
