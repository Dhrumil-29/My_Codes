#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class base
{
private:
    int varPrivate;
protected:
    int varPro;
    void setPro(int a){ varPro = a;}
    void printPro()
    {
       cout<<"value of base class (protected):- "<<varPro<<endl;
    }
public:
    int varPublic;
    void printPublic();
    void printPrivate()
    {
        cout<<"value of base class (private):- "<<varPrivate<<endl;
    }
    base()
    {
        varPrivate = 5;
        varPublic = 10;
    }
};

void base::printPublic()
{
    cout<<"value of base class (public):- "<<varPublic<<endl;
}

class child:public base///Inheritance base class copied in child class
///For class child : private base :=  private of base can not access but other 2 of base are private of child;
///For class child : protected base :=  private of base can not access but other 2 of base are protected of child;
///For class child : public base :=  private of base can not access but other 2 of base are public of child;
{
public:
    void setPublic(int a)
    {
        varPublic = a; setPro(a); printPro();
    }
};
int main()
{
    base b;
    b.printPublic();
    child c;
    c.printPublic();
    c.setPublic(30);
    b.printPublic();
    c.printPublic();
    return 0;
}
