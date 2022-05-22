#include <iostream>
using namespace std;
//create a structure of node for lin list
struct node
{
    int data;
    node *next;
};

//create a base class of linked list
class linked_list
{
    //in liked list head and tail pointer are private
private:
    node *head,*tail;
public:
    //create default constructor for head and tail are NULL
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    //create a function for add node(data)in link list
    void add_front(int n)
    {
        //create a tmp pointer to initilized node
        node *tmp;
        tmp = new node;
        tmp->data = n;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
            tmp->next = NULL;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }

    void add_last(int n)
    {
        node *tmp;
        tmp = new node;
        tmp->data = n;
        if(tail == NULL)
        {
            head = tmp;
            tail = tmp;
            tmp->next = NULL;
        }
        else
        {
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
        }
    }

    //create a display function to show a linked list
    void display()
    {
        node *tmp;
        tmp = head;
        if(tmp == NULL)
        {
            cout<<"\nempty linked list"<<endl;
        }
        else
        {
            while(tmp!=NULL)
            {
                cout<<endl<<tmp->data<<" ";
                tmp = tmp->next;
            }
        }
    }

    //create a function to return a head
    node * get_head()
    {
        return head;
    }

    //-----------delete functions
    void delete_first()
    {
        node *tmp;
        tmp = head;
        if(tmp == NULL)
        {
            cout<<"\nEMPTY STACK"<<endl;
        }
        head = tmp->next;
        delete(tmp);
    }

    void delete_last()
    {
        node *curr,*prev;
        prev = NULL;
        curr = head;
        if(curr == NULL)
        {
            cout<<"\nEMPTY QUEUE"<<endl;
        }
        else
        {
            while(curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete(curr);
        }
    }
    virtual void push(int)=0;
    virtual void pop() = 0;
    virtual void show() = 0;
};

//create a derive class whose base class is linked list
class link_stack : public linked_list
{
public:
    int count1 = 0;
    void push(int n)
    {
        count1++;
        this->add_front(n);
    }
    void pop()
    {
        this->delete_first();
        count1--;
    }
    void show()
    {
        cout<<"\ntotal number of data is "<<count1<<endl;
    }

};

class link_queue : public linked_list
{
public:
    int count2 = 0;
    void push(int n)
    {
        count2++;
        this->add_last(n);
    }
    void pop()
    {
        this->delete_last();
        count2--;
    }
    void show()
    {
        cout<<"\ntotal number of data is "<<count2<<endl;
    }

};
int main()
{
    int n,a,b;
    cout<<"\nenter 1 or 2 for create linked list\n1. stack\n2.queue\n";
    cin>>a;
        if(a == 1)
        {
           link_stack s;
            while(1)
            {
                cout<<"\n\n\nenter your choice\n1.push\n2.pop\n3.show\n4.exit\n5.display link list\n";
                cin>>b;
                if(b == 1)
                {
                    cout<<"\nenter data: \n";
                    cin>>n;
                    s.push(n);
                }
                else if(b == 2)
                {
                    s.pop();
                }
                else if(b == 3)
                {
                    s.show();
                }
                else if(b == 5)
                {
                    s.display();
                }
                else if(b == 4)
                {
                    break;
                }
                else
                {
                    cout<<"\ninvalide choice";
                }
            }
        }
            else if(a == 2)
            {
                link_queue q;
                while(1)
                {
                    cout<<"\n\n\nenter your choice\n1.push\n2.pop\n3.show\n4.exit\n5.display link list";
                    cin>>b;
                    if(b == 1)
                    {
                        cout<<"\nenter data: \n";
                        cin>>n;
                        q.push(n);
                    }
                    else if(b == 2)
                    {
                        q.pop();
                    }
                    else if(b == 3)
                    {
                        q.show();
                    }
                    else if(b == 4)
                    {
                        break;
                    }
                    else if(b == 5)
                    {
                        q.display();
                    }
                    else
                    {
                        cout<<"\ninvalide choice";
                    }
                }
            }
    return 0;
}
