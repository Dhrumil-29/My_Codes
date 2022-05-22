#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

template <class T>

class csum{
    T value;

public:
    csum(T first,T second)
    {
        value = first + second;
    }
    T Result()
    {
        return value;
    }

};
int main()
{
    csum<int> s(5,3);
    cout<<"answer:- "<<s.Result();
    csum<float> sa(5.5,3.9);
    cout<<"\nanswer:- "<<sa.Result();

    //getch();
    return 0;
}
