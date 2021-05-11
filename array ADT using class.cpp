# include <stdio.h>
# include <stdlib.h>
# include <iostream>
using namespace std;

class array
{
private:
    int *A;
    int length;
    int size;
public:
    
    array(int size)
    {
        this->size = size; // 'this' pointer retrives the object's 'size' value hidden by the local variable size
        A = new int [size];
    }
    
    void create()
    {
        cout<<" enter number of elements "<< flush;
        cin>>length;
        cout<<" start entering elements"<<endl;
        for(int i=0; i<length; i++)
        {
            cout<<" element no. "<<i<<" = "<< flush;
            cin>>A[i];
        }
    }
    
    void display()
    {
        for(int i=0; i<length; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    
    ~array()
    {
        delete [] A;
        cout<<"array destroyed!!!"<<endl;
    }
};

class Array
{
private:
    int *A;
    int size;
    int length;
    
public:
    
    Array(int size)
    {
        this->size=size;
        A = new int [size];
    }
    
    void Create()
    {
        cout<<"enter number of elements ";
        cin>>length;
        cout<<"start entering elements "<<endl;
        for(int i=0; i<length; i++)
        {
            cout<<"element "<<i+1<<" = ";
            cin>>A[i];
        }
    }
    
    void Insert(int element, int index)
    {
        for(int i=length-1; i>=index; i--)
        {
            A[i+1] = A[i];
        }
        A[index] = element;
        length++;
    }
    
    int Delete(int index)
    {
        int del = A[index];
        for(int i=index; i<length; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return del;
    }
    
    void Swap(int index1, int index2)
    {
        int temp;
        temp = A[index1];
        A[index1] = A[index2];
        A[index2] = temp;
    }
    
    void Display()
    {
        for( int i=0; i<length; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    
    ~Array()
    {
        delete[] A;
        cout<<"array destroyed!!!"<<endl;
    }
    
};

int main()
{
    Array arr(10);
    //arr.Create();
    arr.Insert(1, 0);
    arr.Insert(10, 0);
    arr.Insert(100, 0);
    arr.Insert(1000, 0);
    arr.Insert(10000, 0);
    arr.Swap(0,3);
    //cout<<arr.Delete(2)<<" is deleted"<<endl;
    arr.Display();

    return 0;
}
