#include<iostream>
#include<stdio.h>
using namespace std;

class Complex{
int a,b;
public:
    Complex()
    {
        a = 0;
        b = 0;
    }
    void setdata()
    {
        cout<<"a = ";
        cin>>a;
        cout<<"b = ";
        cin>>b;
    }
    void show()
    {
        cout<<endl<<a<<" + "<<b<<"i"<<endl;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.a = a+c.a;
        temp.b = b+c.b;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.a = (a*c.a) - (b*c.b);
        temp.b = (b*c.a) + (a*c.b);
        return temp;
    }
};
int main()
{
    Complex c1,c2,c3;
    c1.setdata();
    c1.show();
    c2.setdata();
    c2.show();
    c3 = c1 + c2;
    c3.show();
    c3 = c1*c2;
    c3.show();
    return 0;
}
