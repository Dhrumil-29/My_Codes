#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
int val;
node* next;
node *prev;

node()
{
    this->val = 0;
    next = NULL;
    prev = NULL;
}
node(int n)
{
    this->val = n;
    next = NULL;
    prev = NULL;
}
};

class Queue{
private:
    node *head,*tail;
    int sz,cap;
public:
    Queue(int n)
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        cap = n;
    }
    bool isEmpty()
    {
        if(sz == 0)
            return true;
        return false;
    }
    bool isFull()
    {

        return sz == cap?true:false;
    }
    void push(int n)
    {
        if(isFull())
        {
            cout<<"Queue is Full...\n";
            return;
        }
        if(head == NULL)
        {
            node *p = new node(n);
            head = p;
            tail = head;
            sz++;
        }
        else{
            node *p = new node(n);
            p->prev = tail;
            tail->next = p;
            tail = tail->next;
            sz++;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty...\n";
        }
        else{
            if(head->next == NULL)
            {
                delete head;
                head = NULL;
                sz--;
                return ;
            }
            node *d = head;
            head = head->next;
            head->prev = NULL;
            sz--;
            delete d;
        }
    }
    int DisplaySize()
    {
        return sz;
    }
    void display()
    {
        node* temp = head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    Queue q(5);
    for(int i = 1;i<6;i++)
    {
        q.push(i);
    }
    q.display();
    //q.push(1);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    cout<<q.DisplaySize()<<endl;
    q.pop();
    return 0;
}
