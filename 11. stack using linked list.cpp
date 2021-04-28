/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*top=NULL;

//push element to a empty stack
void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    {
        cout<<"stack is full or heap is full"<<endl;
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

//pop the top element out of a stack
int pop()
{
    struct node *t;
    int x=-1;
    
    if(top==NULL)
    {
        cout<<"stack is empty"<<endl;
    }else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

//display 
void display()
{
    struct node *t;
    t=top;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(5);
    pop();
    display();

    return 0;
}
