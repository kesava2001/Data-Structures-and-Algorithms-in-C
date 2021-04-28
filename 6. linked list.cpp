/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;

//creating a linked list
void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

//displaying a linked list
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

//counting numbeer of nodes
int count(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

//sum of the elements in a linked lists
int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//maximum element in a linked list
int max(struct node *p)
{
    int max=-32768;
    
    while(p!=NULL)
    {
        if(max<=p->data)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int main()
{
    int a[]={1,2,31,21,5};
    create(a, 5);
    display(first);
    
    cout<<count(first)<<endl;
    cout<<sum(first)<<endl;
    cout<<max(first)<<endl;
    return 0;
}
