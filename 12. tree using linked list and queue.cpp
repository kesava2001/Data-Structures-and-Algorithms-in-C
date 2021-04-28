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
};

struct node *root;

struct Queue
{
    int size;
    int front;
    int rear;
    node **Q;
};

//creating a Queue
void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct node *));
}

void enqueue(struct Queue *q, node * x)
{
    if((q->rear+1)%q->size==q->front)
    {
        cout<<" Queue is full"<<endl;
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

node * dequeue(struct Queue *q)
{
    struct node *x=NULL;
    
    if(q->front==q->rear)
    {
        cout<<"Queue is empty"<<endl;
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

// void Display(struct Queue q)
// {
//     int i=q.front+1;
 
//     do
//     {
//         cout<<q.Q[i]<<" ";
//         i=(i+1)%q.size;
//     }while(i!=(q.rear+1)%q.size);
// }

void tree()
{
    struct node *p, *t;
    int x=0, y=0;
    struct Queue q;
    create(&q, 100);
    cout<<"enter a value for root"<<" ";
    cin >>x;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        
        cout<<"enter left child of "<<p->data<<" ";
        cin >>x;
        
        if(x!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);
        }
        
        cout<<"enter right child of "<<p->data<<" ";
        cin>>y;
        
        if(y!=-1)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=y;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);
        }
    }
}

//displaying a tree using preorder
void preorder(struct node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main()
{
    
    tree();
    preorder(root);
    inorder(root);
    postorder(root);
    // Display(Que);

    return 0;
}
