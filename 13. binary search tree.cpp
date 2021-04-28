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
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;

node * Rinsert(struct node *t, int key)
{
    struct node *p=NULL, *q=NULL;
    
    if(t==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    
    if(key<t->data)
    {
        t->lchild=Rinsert(t->lchild, key);
    }else if(key>t->data)
    {
        t->rchild=Rinsert(t->rchild, key);
    }else{
        return NULL;
    }
    return t;
}

node * insert(struct node *root, int key)
{
    struct node *p=root, *q=NULL, *r=NULL;
    
    r=(struct node *)malloc(sizeof(struct node));
    r->data=key;
    r->lchild=r->rchild=NULL;
    
    if(root==NULL)
    {
        root=r;
        return root;
    }else{
        
        while(p!=NULL)
        {
            q=p;
            if(key<p->data)
            {
                p=p->lchild;
            }else if(key>p->data)
            {
                p=p->rchild;
            }else{
                return NULL;
            }
        }
    
        if(key<q->data)
        {
            q->lchild=r;
        }else{
            q->rchild=r;
        }
    }
}

void preorder(struct node *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

int main()
{
    root=insert(root, 60);
    insert(root, 50);
    insert(root, 40);
    insert(root, 70);
    insert(root, 80);
    
    preorder(root);
    return 0;
}
