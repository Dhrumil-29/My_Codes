#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void display(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void placeAtBottom(stack<int> &s,int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    int top = s.top();
    s.pop();
    placeAtBottom(s,ele);
    s.push(top);
    return;
}

void reverse_stack(stack<int> &s)
{
    if(s.empty())
        return;
    int top = s.top();
    s.pop();
    reverse_stack(s);
    placeAtBottom(s,top);
    return;
}

int main()
{
    stack<int> s;
    for(int i = 1;i<6;i++)
    {
        s.push(i);
    }
    display(s);
    reverse_stack(s);
    display(s);
    return 0;
}
