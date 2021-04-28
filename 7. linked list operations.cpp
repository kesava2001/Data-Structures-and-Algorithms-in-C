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
}*first=NULL, *second=NULL, *third=NULL;

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

void create2(int a[], int n)
{
    int i;
    struct node *t, *last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    
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

//linear search
struct node * linearSearch(struct node *p, int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }else{
            p=p->next;
        }
    }
    return NULL;
}

//moving the searched element to head of the linked list
struct node * linearSearchBetter(struct node *p, int key)
{
    struct node *q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }else{
            q=p;
            p=p->next;
        }
    }
    return NULL;
}

//inserting element after a particular element
struct node * Insert(struct node *p, int key, int element)
{
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    q->data=element;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=q;
            break;
        }
        p=p->next;
    }
}

//inserting a element at a index
void insert2(struct node *p, int index, int element)
{
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    q->data=element;
    
    if(index==0){
        q->next=first;
        first=q;
        
    }else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
    }
}

//inserting element  in a sorted linked list
void InsertSorted(struct node *p, int element)
{
    struct node *q=NULL, *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=element;
    t->next=NULL;
    while(p!=NULL && p->data<element)
    {
        q=p;
        p=p->next;
    }
    t->next=q->next;
    q->next=p;
}

//deleting the desired element
void Delete(struct node *p, int element)
{
    struct node *q=NULL;
    while(p)
    {
        if(p->data==element)
        {
            q->next=p->next;
            int x = p->data;
            p=p->next;
            cout<<"deleted value is "<<x<<endl;
        }
        q=p;
        p=p->next;
    }
}

//removing duplicates from a sorted list
//reversing a linked list using an additional array
//reversing a linked list using recursion

//merging linked list 
void Merge(struct node *p, struct node *q)
{
    struct node *last=NULL;
    if(p->data<q->data)
    {
        third=p;
        last=p;
        p=p->next;
        last->next=NULL;
    }else{
        third=q;
        last=q;
        q=q->next;
        last->next=NULL;
    }
    
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL){
        last->next=p;
    }else{
        last->next=q;
    }
}

//concatination of two linked list
void concat(struct node *p, struct node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}

int main()
{
    int a[]={1,3,5,7,9};
    int b[]={2,4,6,8,10};
    create2(a, 5);
    create(b, 5);
    Merge(first, second);
    display(third);
    return 0;
}

