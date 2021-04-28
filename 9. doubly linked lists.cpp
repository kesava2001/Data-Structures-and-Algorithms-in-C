/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

//creating a doubly linked list
void create(int a[], int n)
{
    struct node *t, *last;
    int i=0;
    
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

//displaying the doubly linnked list
void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

//length of a DLL
int length(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

//inserting in a DLL
//here the new element will be added at the position(pos) specified
int insert(struct node *p, int element, int pos)
{
    struct node *t=NULL, *q=first;
    
    if(pos<1 || pos>length(p))
    {
        cout<<"enter valid position"<<endl;\
    }else{
        t=(struct node *)malloc(sizeof(struct node));
        t->data=element;
        t->prev=t->next=NULL;
    
        if(pos==1)
        {
            first->prev=t;
            t->next=first;
            first=t;
        }else if(pos==length(p))
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            p->next=t;
            t->prev=p;
        }else{
            for(int i=0;i<pos-1;i++)
            {
                q=p;
                p=p->next;
            }
            p->prev=t;
            t->next=p;
            t->prev=q;
            q->next=t;
        }
    }
}

//deleting from a DLL
void Delete(struct node *p, int pos)
{
    struct node *q=NULL, *r=NULL;
    int element=0;
    if(pos<1 || pos>length(p))
    {
        cout<<"enter valid position"<<endl;
    }else{
        if(pos==1){
            for(int i=0;i<pos;i++){
                q=p;
                p=p->next;
            }
            element=q->data;
            first->next=NULL;
            p->prev=NULL;
            first=p;
            free(q);
        }else if(pos==length(p)){
            
            for(int i=0;i<pos-1;i++)
            {
                q=p;
                p=p->next;
            }
            element=p->data;
            p->prev=NULL;
            q->next=NULL;
            free(p);
        }else{
            
            for(int i=0;i<pos-1;i++)
            {
                r=q;
                q=p;
                p=p->next;
                q=q->next;
            }
            element=q->data;
            p->prev=q->prev;
            q->prev=NULL;
            r->next=q->next;
            q->next=NULL;
            free(q);
        }
    }
}

//reversing a DLL
void Reverse(struct node *p)
{
    struct node *temp=NULL;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
    }
}

int main()
{
    int a[]={1,2,3,4,5,6};
    create(a, 6);
    //insert(first, 99, 6);
    //Delete(first, 1);
    Reverse(first);
    display(first);

    return 0;
}
