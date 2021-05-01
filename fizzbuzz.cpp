/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void fizzBuzz(int n) 
{
    if(n>0 && n<200000)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
            {
                cout<<"FizzBuzz"<<endl;
            }else if(i%3==0 && i%5!=0)
            {
                cout<<"Fizz"<<endl;
            }else if(i%5==0 && i%3!=0){
                cout<<"Buzz"<<endl;
            }else if(i%3!=0 || i%5!=0 ||(i%3!=0 && i%5!=0)){
                cout<<i<<endl;
            }
        }
    }

}

int main()
{
    fizzBuzz(65);

    return 0;
}
