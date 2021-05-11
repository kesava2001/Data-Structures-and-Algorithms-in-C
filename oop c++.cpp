#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class student
{
    string school;
    public:
    string name;
    int age=20;
    bool gender;
    int grade;
    
    void display()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
        cout<<"Gender is "<<gender<<endl;
        cout<<"Grade is "<<grade<<endl;
    }
    
    void School(string s)
    {
        school = s;
    }
    
    int upgrade(int i)
    {
        grade = grade + i;
    }
};

class Car
{
    public:
    string brand;
    int weight;
    float mileage;
    
    //class constructor
    Car(string x, int y, float z)
    {
        brand = x;
        weight = y;
        mileage = z;
    }
};

class shape
{
    public:
    string ShapeType;
    int n_sides;
    
    shape(string x, int y)
    {
        ShapeType = x;
        n_sides = y;
    }
    
    void Area(int l_side)
    {
        int area = (0.5)*l_side*l_side;
        cout<<area<<endl;
    }
    
    void Perimeter(int l_side);
};
void shape::Perimeter(int l_side)
{
    float peri = n_sides*l_side;
    cout<<peri<<endl;
}

//constructors
class fruit
{
    public:
    string color;
    string shape;
    float weight;
    float width;
    
    fruit(string x, string y, float z, float q);
    
    void nothing();
};
fruit::fruit(string x, string y, float z, float q)
{
    color = x;
    shape = y;
    weight = z;
    width = q;
}
void fruit::nothing()
{
    cout<<"nothing"<<endl;
}

//encapsulation
//here salary attribute has no direct access but can be modified using public methods
class employee
{
    private:
    int salary;
    
    public:
    void setSalary(int s)
    {
        salary = s;
    }
    
    int getSalary()
    {
        return salary;
    }
};

//inheritance
class vehicle
{
    public:
    string brand;
    
    void honk()
    {
        cout<<"tuut, tuut!!!"<<endl;
    }
};

class truck: public vehicle
{
    public:
    string model;
    
    void display()
    {
        cout<<"the truck is of "<<model<<endl;
    }
};

class trailerTruck: public truck //multilevel inheritance
{
    
};

//multiple inheritance
class klass1
{
    public:
    
    void func()
    {
        cout<<"this is klass1 class object"<<endl;
    }
};

class klass2
{
    protected:
    int kkkk = 200;
    public:
    
    void func2()
    {
        cout<<"this is klass2 class object"<<endl;
    }
};

class klass3: public klass1, public klass2
{
    public:
    
    void get()
    {
        cout<<kkkk<<endl;
    }
};

int main()
{
    // student a;
    // a.name = "kesava";
    // a.age = 20;
    // a.gender = 1;
    // a.grade = 90;
    
    // a.display();
    // a.upgrade(-10);
    // a.School("NIT Hamirpur");
    // a.display();
    
    // Car myCar("Rolls Royce", 1, 25.7);
    // cout<<myCar.brand;
    
    // shape tri("tri", 3);
    // tri.Area(4);
    // tri.Perimeter(3);
    
    // fruit apple("red", "sphere", 200, 10);
    // apple.nothing();
    
    // employee tim;
    // tim.setSalary(100000);
    // cout<<tim.getSalary();
    
    // truck pullup;
    // pullup.model = "89xTgwe";
    // pullup.brand = "bmw";
    
    // pullup.honk();
    // pullup.display();
    
    // trailerTruck obj;
    // obj.honk();
    
    klass3 obj2;
    obj2.func();
    obj2.get();

    return 0;
}
