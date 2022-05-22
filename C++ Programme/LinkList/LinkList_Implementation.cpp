#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//singly Link List
struct node{
int data;
struct node *next;

//default constructor
node()
{
    this->data = 0;
    this->next = NULL;
}

//parameterize constructor
node(int n)
{
    this->data = n;
    this->next = NULL;
}
};

class singlyLinkList{
private:
    node *head;
    int sz;
public:

singlyLinkList()
{
    head = NULL;
    sz = 0;
}
void Display()
{
    node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

void push(int n)
{
    if(head == NULL)
    {
        node *tmp = new node(n);
        head = tmp;
        sz++;
    }
    else
    {
        node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        node *p = new node(n);
        temp->next = p;
        sz++;
    }
}

void pushfront(int n)
{
    if(head == NULL)
    {
        node *temp = new node(n);
        head = temp;
        sz++;
    }
    else
    {
        node *p = new node(n);
        p->next = head;
        head = p;
        sz++;
    }
}

void pop_add(node *n)
{
    if(head == NULL)
    {
        cout<<"Link List is Empty...\n";
    }
    else
    {
        if(head == n)
        {
            if(head->next)
            {
                head = head->next;
                delete n;
                sz--;
            }
            else
            {
                head = NULL;
                sz--;
                delete n;
            }
        }
        else
        {
            node* temp = head;
            while(temp and temp->next != n)
            {
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout<<" Node was not there...\n";
            }
            else{
            temp->next = temp->next->next;
            sz--;
            delete n;
            }
        }
    }
}

void pop_value(int n)
{
    if(head == NULL)
    {
        cout<<"Link List is Empty...\n";
    }
    else
    {
        if(head->data == n)
        {
            if(head->next)
            {
                node *temp = head;
                head = head->next;
                delete temp;
                sz--;
            }
            else
            {
                head = NULL;
                sz--;
                delete head;
            }
        }
        else
        {
            node* temp = head;
            node* prev = NULL;
            while(temp and temp->data != n)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout<<"element was not there...\n";
            }
            else{
            prev->next = temp->next;
            sz--;
            delete temp;
            }
        }
    }
}

void DisplaySize()
{
    cout<< "size = "<<this->sz<<endl;
}

};

int main()
{
    singlyLinkList s;
    for(int i = 1;i <11;i++)
    {
        s.pushfront(i);
    }
    s.Display();
    s.pop_value(1);
    s.pop_value(2);
    s.pop_value(3);
    s.pop_value(4);
    s.pop_value(5);
    s.DisplaySize();
    s.Display();
    return 0;
}
