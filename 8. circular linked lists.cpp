/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using  namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

//creating a circular linked list
void CreateCircular(int a[], int n)
{
    int i;
    struct node *t, *last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;
    
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        t=last;
    }
}

//displaying linked list
void display(struct node *p)
{
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

//length of a circular linked list
int length(struct node *p)
{
    int len=0;
    do{
        p=p->next;
        len=len+1;
    }while(p!=head);
    
    return len;
}

//inserting in a circular linked list
void insert(struct node *p, int element, int pos)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=element;
    
    if(pos==0)
    {
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }else{
            do{
                p=p->next;
            }while(p->next!=head);
            p->next=t;
            t->next=head;
            head=t;
        }
    }else{
        
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

//delete an element in a circular linked list
int Delete(struct node *p, int pos)
{
    struct node *q=NULL;
    int x=0;
    if(pos<0 || pos>length(p))
    {
        return -1;
    }
    p=head;
    if(pos==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(p==head)
        {
            free(head);
            head=NULL;
        }else{
            p->next=head->next;
            free(head);
            head=head->next;
        }
    }else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}



int main()
{
    int a[]={5,1,2,3,4};
    CreateCircular(a, 5);
    // insert(head, 6, 3);
    //cout<<length(head)<<endl;
    cout<<Delete(head, 4)<<endl;
    display(head);
    return 0;
}
