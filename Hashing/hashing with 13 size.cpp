#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    long int sid;
    string name;
    struct node *next;
};

struct node *s[13] = {NULL};

class hashing
{
    public:
        void hashtable(long int id,string a)
        {
            int key;
            key = id%13;

            node *tmp = new node;
            tmp->sid = id;
            tmp->name = a;
            tmp->next = NULL;

            if(s[key] == NULL)
            {
                s[key] = tmp;
            }
            else
            {
                node *temp = new node;
                temp = s[key];
                while(temp->next)
                {
                    temp = temp->next;
                }
                temp->next = tmp;
            }
        }

        void hash_print()
        {
            node *tmp = new node;
            int i;
            for(i=0;i<13;i++)
            {
                tmp = s[i];
                while(tmp)
                {
                    cout<<"\n STUDENT ID -> "<<tmp->sid<<"   STUDENT NAME-> "<<tmp->name;
                    tmp = tmp->next;
                }
                cout<<"\n-------------------------------";
            }
        }

        void hash_search(long int id)
        {
            node *tmp = new node;
            int key,flag = 0;
            key = id%13;
            tmp = s[key];
            while(tmp)
            {
                if(tmp->sid == id)
                {
                    cout<<"\nSTUDENT NAME -> "<<tmp->name;
                    flag = 1;
                    break;
                }
                else
                {
                    tmp = tmp->next;
                }
            }
            if(flag == 0)
            {
                cout<<"\nNOT FOUND"<<endl;
            }
        }

    void hash_sort()
    {
        node *tmp = new node;
        node *curr = new node;
        int i;
        long int x;
        string y;
        for(i=0;i<13;i++)
        {
            tmp = s[i];
            while(tmp)
            {
                curr = tmp;
                while(curr)
                {
                    if(curr->sid < tmp->sid)
                    {
                        x = curr->sid;
                        curr->sid = tmp->sid;
                        tmp->sid = x;

                        y = curr->name;
                        curr->name = tmp->name;
                        tmp->name = y;
                    }

                    curr = curr->next;
                }
                tmp = tmp->next;
            }
        }
    }


};

int main() {
    int n,i;
    long int id;
    string a;
    int choice;
    hashing h;
    cout<<"ENTER HOW MANY STUDENTID YOU WANT TO ENTER : --";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\nENTER STUDENT ID :-- ";
        cin>>id;
        cout<<"\nENTER STUDENT NAME :-- ";
        cin>>a;
        h.hashtable(id,a);
    }
    while(1)
    {
        cout<<"\n1.SEARCH STUDENT NAME?\n2. PRINT HASHTABLE\n3.SORT HASH TABLE BY ROW WISE\n4.EXIT";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\n ENTER STUDENT ID --- ";
                cin>>id;
                h.hash_search(id);
                break;
            case 2:
                h.hash_print();
                break;
            case 3:
                h.hash_sort();

            case 4:
                return 0;
            default:
                cout<<"\nINVAILID CHOICE";
        }
    }
        return 0;
}
