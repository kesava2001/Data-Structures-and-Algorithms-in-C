//implementing stack using array

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct stack
{
    int size;
    int top;
    int *S;
};

//creating a stack
void create(struct stack *st, int size)
{
    st->size=size;
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(st->size));
}

//display
void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}

//to add something to the stack
void push(struct stack *st, int x)
{
    if(st->top==st->size-1)
    {
        cout<<"stackoverflow cannot insert "<<x<<endl;
    }else{
        st->top++;
        st->S[st->top]=x;
    }
}

//to delete something from the stack
int pop(struct stack *st)
{
    int del=-1;
    if(st->top==-1)
    {
        cout<<"stackunderflow"<<endl;
    }else{
        del=st->S[st->top];
        st->top--;
    }
    return del;
}

//looking what element is at a position, here position is taken from top of a pointer
int peek(struct stack st, int pos)
{
    int x=-1;
    if(st.top-pos+1<0)
    {
        cout<<"position is invalid"<<endl;
    }else{
        x=st.S[st.top-pos+1];
    }
    return x;
}

//top element of a stack
int stackTop(struct stack st)
{
    if(st.top==-1)
    {
        return -1;
    }else{
        return st.S[st.top];
    }
}

//if stack is empty
int isEmpty(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }else{
        return 0;
    }
}

//if stack is full
int isFull(struct stack st)
{
    if(st.top==st.size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    struct stack st;
    create(&st, 5);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    //push(&st, 6);
    cout<<peek(st, 4)<<endl;
    cout<<stackTop(st)<<endl;
    display(st);
    return 0;
}
