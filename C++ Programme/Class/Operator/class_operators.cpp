#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;

///template <class T>
class dummy
{
private:
    int value;
public:
    int getvalue();
    dummy()
    {
        value = 0;
    }
    dummy(int x)///constuctors
    {
        value = x;
    }
    int print(){return value;}
    dummy operator+(dummy a)///a is 2nd value
    {
        cout<<"Addition Occured!!!"<<endl;
        return(this->value + a.value);///this for 1st operator
    }
    dummy operator-(dummy a)
    {
        cout<<"subtraction occured!!"<<endl;
        return (this->value - a.value);
    }
    dummy operator*(dummy a)
    {
        cout<<"Multiplication occured!!"<<endl;
        return (this->value * a.value);
    }
    dummy operator/(dummy a)
    {
        cout<<"division occured!!"<<endl;
        return (this->value / a.value);
    }

};

int dummy::getvalue()
{
    return value;
}

int main()
{
    dummy a(5);
    cout<<"value: -  "<<a.print()<<endl;
    dummy b(10);
    cout<<"value: -  "<<b.print()<<endl;
    dummy c = a + b;
    cout<<"value: -  "<<c.print()<<endl;
    cout<<"value:- "<<a.getvalue()<<endl;
    system("pause");///screen pause
    return 0;
}
