/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
class diagonal
{
private:
    int n;
    int *A;
public:
    diagonal()
    {
        n=2;
        A=new int[2];
    }
    diagonal(int n)
    {
        this->n=n;
        A=new int[n];
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~diagonal()
        {
            delete []A;
        };
    }
};

void diagonal::set(int i, int j, int x)
{
    if(i==j){
        A[i-1]=x;
    }
}

int diagonal::get(int i, int j)
{
    if(i==j){
        return A[i-1];
    }else{
        return 0;
    }
}

void diagonal::display(){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                cout<<A[i]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    diagonal d(5);
    d.set(1,1,-1); d.set(2,2,-2); d.set(3,3,-3); d.set(4,4,-4); d.set(5,5,-5);
    d.display();
    return 0;
}
