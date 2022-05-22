#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
  int data;
  node *next;
};

class linked_list
{
  private :
  node *head,*tail;
  public:
  linked_list()
  {
      head = NULL;
      tail=NULL;
  }

  node* gethead()
  {
      cout<<"head value is: "<<head->data<<endl;
      cout<<"head address is: "<<head<<endl;
      return head;
  }

  node* getnode(int n)
  {
      node*ptr;
      ptr=head;
      while(ptr!=NULL)
      {
          if(ptr->data == n)
          {
              break;
          }
          else
          {
              ptr=ptr->next;
          }
      }
      return ptr;
  }

  static void display_rec(node *head)
    {
        if(head==NULL)
        {
            cout<<"NULL\n\n"<<endl;
        }
        else
        {
            cout<<head->data<<endl;
            display_rec(head->next);
        }
    }

  node* gettail()
  {
      cout<<"tail value is: "<<tail->data<<endl;
      cout<<"tail address is: "<<tail<<endl;
      return tail;
  }

  void last(int n)
  {
      node*tmp=new node;
      if(head == NULL)
      {
        tmp->data=n;
        tmp->next=NULL;
        head = tmp;
        tail = tmp;
      }
      else
      {
          tmp->data=n;
          tmp->next=NULL;
          tail->next=tmp;
          tail=tail->next;
      }
  }

  void after(node*a,int n)
  {
      node*tmp=new node;
      tmp->data=n;
      tmp->next=a->next;
      a->next=tmp;
  }

  void front(int n)
  {
      node*tmp=new node;
      if(head == NULL)
      {
        tmp->data=n;
        tmp->next=NULL;
        head = tmp;
        tail = tmp;
      }
      else
      {
          tmp->data=n;
          tmp->next=head;
          head = tmp;
      }
  }

  void display_list()
  {
      node*tmp;
      tmp=head;
      if(tmp == NULL && tail == NULL)
      {
          cout<<"NULL\n\n"<<endl;
      }
      else
      {
          cout<<"\n";
          while(tmp!=NULL)
          {
              cout<<tmp->data<<endl;
              tmp=tmp->next;
          }
          cout<<"NULL\n\n"<<endl;
      }
  }

  void delete_head()
  {
      node*ptr = head;
      if(ptr==NULL)
      {
          cout<<"NULL\n\n";
      }
      else
      {
      head = ptr->next;
      }
  }
  void delete_tail()
  {
      node* curr,*prev;
      prev=NULL;
      curr = head;
      if(curr == NULL)
      {
          cout<<"NULL\n\n";
      }
      else
      {
      while (curr!=tail)
      {
          prev=curr;
          curr=curr->next;
      }
      tail = prev;
      prev->next = NULL;
      delete curr;
      }
  }

  void delete_data(int n)
  {
      node *curr,*prev;
      prev = NULL;
      curr = head;

      if(curr == NULL)
      {
          cout<<"NULL"<<endl;
      }
      else
      {
          while(curr->data != n && curr != NULL )
          {
              prev=curr;
              curr=curr->next;
          }
          if (prev == NULL)
          {
              head = curr->next;
              delete(curr);
          }
          else if(curr == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete(curr);
        }
          else
          {
              prev->next = curr->next;
              curr->next = NULL;
          }
      }

  }

  void delete_node(int n)
  {
      node *curr,*prev;
      curr = head;
      prev = NULL;
      int i;
      if(curr==NULL)
      {
          cout<<"NULL"<<endl;
      }
      else
      {
        for(i=1;i<n;i++)
        {
              prev=curr;
              curr=curr->next;
        }
        if(prev == NULL)
        {
            head=curr->next;
            delete(curr);
        }
        else if(curr == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete(curr);
        }
        else
        {
            prev->next=curr->next;
            curr->next=NULL;
        }
      }
  }
  void search_data(int n)
  {
      node *ptr;
      ptr = head;
      int coun = 0;
      int node = 0;
      if(ptr == NULL)
      {
          cout<<"NULL";
      }
      else
      {
          do{

              node++;
              if(ptr->data == n)
              {
                  coun++;
                  cout<<node<<"\t"<<ptr->data<<endl;
              }
              ptr = ptr->next;
          }
          while(ptr != NULL);

          cout<<"total "<<coun<<endl;
      }
  }
    void reverse()
    {
        node * tmp = head;
        node *prevnode = head;
        node *current = head;
        node *nextnode = NULL;
        head = tail;
        while(prevnode != NULL)
            {
                prevnode = prevnode->next;
                current->next = nextnode;
                nextnode = current;
                current = prevnode;
            }
            tail = tmp;
    }
};
int main() {
    int a1,n;
    cout<<"welcome to c++"<<endl<<"are you want to create a link list??\n\n1. yes(enter 1)\n2.no(enter 2)\n\n"<<endl;
    cin>>a1;
    if(a1 ==2 )
    {
        cout<<"thank you\n\n";
        exit(0);
    }
    else
    {

        cout<<"created one link list:)\n\n\n";
        linked_list a;
        cout<<"enter first value\n\n";
        cin>>n;
        a.last(n);
    while(1)
    {
        cout<<"\nwhere you want to enter a value:\n1.last\n2.after any value\n3.see the list\n4.delete head\n5.delete tail\n6.delete node\n7.delete data\n8.detail of head\n9.detail of tail\n10.search\n11.reverse the list\n12.end\n\n";
        cin>>a1;
        switch(a1)
        {
            case 1:

                    cout<<"\n\nenter value\n";
                    cin>>n;
                    a.last(n);
                    break;
                    case 2:
                            cout<<"\n\nenter which value after you want to insert value\n";
                            int b;
                            cin>>b;
                            cout<<"\n\nenter value\n";
                            cin>>n;
                            a.after(a.getnode(b),n);
                            break;
                            case 3:
                                    a.display_list();
                                    break;
                                    case 12:
                                            cout<<"\n\nthank you:)";
                                            exit(0);
                                    case 4:
                                        a.delete_head();
                                        cout<<"\n\n";
                                        break;
                                    case 5:
                                        a.delete_tail();
                                        cout<<"\n\n";
                                        break;
                                    case 6:
                                        cout<<"\n\nwhich node you want to delete\nenter no.\n";
                                        cin>>n;
                                        a.delete_node(n);
                                        cout<<"\n";
                                        break;
                                    case 7:
                                        cout<<"\n\nwhich data(value) in list you want to delete\nenter no.\n";
                                        cin>>n;
                                        a.delete_data(n);
                                        cout<<"\n";
                                        break;
                                    case 8:
                                        a.gethead();
                                        break;
                                    case 9:
                                        a.gettail();
                                        break;
                                    case 10:
                                        cout<<"\n\nenter with data you want to search\nenter value\n\n";
                                        cin>>n;
                                        a.search_data(n);
                                        break;
                                    case 11:
                                        a.reverse();
                                        break;
                                    default:
                                        cout<<"\n\ninvalid input\ntry again\n";
                                    break;

        }

    }
    }
	return 0;
}
