#include<iostream>
#include<cctype>
#include<stdio.h>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;

// Author :-- Dhummil Mevada
// College ID : -- 201901128


//structure of hashing for manager
struct managernode{
  long long int productID;
  string productname;
  float rate;
  int quantity;
  struct managernode *next;
};

struct managernode *m[10] = {NULL};

//stucture for customer (hashing)
struct customernode{
    long long int customerID;
    float point;
    string name;
    struct customernode *next;
};

struct customernode *c[10] = {NULL};

//structure for biling coounter (hashing)
struct bilingnode
{
  long long int productID;
  int quantity,transectionID;
  float rate;
  string name;
  struct bilingnode *next;
};

struct bilingnode *b[10] = {NULL};

//Basee class of inventery stock
class stock
    {
        public:
            void inventery()
            {
                int i;
                long long int id;
                string n;
                float r;
                int q;

                long long int w[100]={111100000001,111100000002,111100000003,111100000004,111100000005,111100000006,111100000007,111100000008,111100000009,111100000010,111100000011,111100000012,111100000013,111100000014,111100000015,111100000016,111100000017,111100000018,111100000019,111100000020,111100000021,111100000022,111100000023,111100000024,111100000025,111100000026,111100000027,111100000028,111100000029,111100000030,111100000031,111100000032,111100000033,111100000034,111100000035,111100000036,111100000037,111100000038,111100000039,111100000040,111100000041,111100000042,111100000043,111100000044,111100000045,111100000046,111100000047,111100000048,111100000049,222200001111,222200001114,222200001117,222200001120,222200001123,222200001126,222200001129,222200001132,222200001135,222200001138,222200001141,22200001144,222200001147,222200001150,222200001153,222200001156,222200001159,222200001162,222200001165,222200001168,222200001171,222200001174,222200001177,222200001180,222200001183,222200001186,222200001189,222200001192,222200001195,222200001198,222200001201,222200001204,222200001207,222200001210,222200001213,222200001216,222200001219,222200001222,222200001225,222200001228,222200001231,222200001234,222200001237,222200001240,222200001243,222200001246,222200001249,222200001252,222200001255,222200001258,222200001261};
                string x[100]={"product1","product2","product3","product4","product5","product6","product7","product8","product9","product10","product12","product13","product14","product15","product16","product17","product18","product19","product20","product21","product22","product23","product24","product25","product26","product27","product28","product29","product30","product31","product32","product32","product33","product34","product35","product36","product37","product38","product39","product40","product41","product42","product43","product44","product45","product46","product47","product48","product49","product50","product51","product52","product53","product54","product55","product56","product57","product58","product59","product60","product61","product62","product63","product64","product65","product66","product67","product68","product69","product70","product71","product72","product73","product74","product75","product76","product77","product78","product79","product80","product81","product82","product83","product84","product85","product86","product87","product88","product89","product90","product91","product92","product93","product94","product95","product96","product97","product98","product99","product100"};
                float y[100]={100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,1000,1010,1020,1030,1040,1050,1060,1070,1080,1090};
                //int z[100]={20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};

                for(i=0;i<100;i++)
                {
                    id = w[i];
                    n = x[i];
                    r = y[i];
                    q = 20;//z[i];
                    hashing(id,n,r,q);
                }
            }


            void hashing(long long int id,string n,float r,int q)
            {
                int key;
                key = id%10;
                managernode *p = new managernode;
                //p = m[key];
                p->productID = id;
                p->productname = n;
                p->rate = r;
                p->quantity = q;
                p->next = NULL;

                if(m[key] == NULL)
                {
                    m[key] = p;
                }
                else
                {
                    managernode *tmp;
                    tmp = m[key];
                    while(tmp->next)
                    {
                        tmp = tmp->next;
                    }
                    tmp->next = p;
                }
            }

};

//derive class of manager
class manager : public stock
{
  private:
    long long int managerID;
    string managername;
    public:
        void change_manager(long long int a,string b)
        {
            managerID = a;
            managername = b;
        }

        void managerinfo()
        {
            cout<<"\nManager Name ---  "<<managername<<"     Manager ID ---  "<<managerID<<endl;
        }

        void add_stock()
        {
            inventery();
        }

        void delete_stock(long long int id)
        {
            int key;
            key = id%10;
            managernode *tmp ;
            tmp = m[key];

            if(tmp->productID == id && tmp->next == NULL)
            {
                m[key] = NULL;
            }
            if(tmp->productID == id && tmp->next != NULL)
            {
                tmp->productID = tmp->next->productID;
                tmp->productname = tmp->next->productname;
                tmp->rate = tmp->next->rate;
                tmp->quantity = tmp->next->quantity;

                managernode *p;
                p = tmp->next;

                tmp->next = p->next;
                delete p;
            }
            else if(tmp->productID != id)
            {
                while(tmp->next != NULL && tmp->next->productID != id )
                {
                    tmp = tmp->next;
                }
                if(tmp->next != NULL && tmp->next->productID == id)
                {
                    managernode *p ;
                    p = tmp->next;
                    tmp->next = p->next;
                    delete p;
                }
                else
                {
                    cout<<"\n PRODUCT DOESN'T EXISTS"<<endl;
                }
            }
        }

        void stock_detail(long long int id)
        {
            int key,flag = 0 ;
            key = id%10;
            managernode  *p = new managernode;
            p = m[key];
            while(p)
            {
                if(p->productID == id)
                {
                    cout<<"\nProductID -> "<<p->productID;
                    cout<<"\nProductNamne ->  "<<p->productname;
                    cout<<"\nProduct Rate -> "<<p->rate;
                    cout<<"\nProduct Quantity -> "<<p->quantity<<endl;
                    flag = 1;
                    break;
                }
                else
                {
                    p = p->next;
                }
            }
            if(flag == 0)
            {
                cout<<"\nProduct Doesn't Exists"<<endl;
            }

        }

        int update_stock(long long int id)
        {
            int key,flag = 0,choice,quan;
            float x;
            string n;
            key = id%10;
            managernode *p = new managernode;
            p = m[key];
            while(p)
            {
                if(p->productID == id)
                {
                    flag = 1;
                    //system("CLS");
                    cout<<"\n1.UPDATE PRIZE\n2.UPADTE NAME\n3.UPDATE QUANTITY\n4.EXIT"<<endl;
                    cin>>choice;
                    switch(choice)
                    {
                        case 1:
                            cout<<"\nENTER NEW PRIZE OF PRODUCT - ";
                            cin>>x;
                            p->rate = x;
                            break;
                        case 2:
                            cout<<"\nENTER NAME OF PRODUCT - ";
                            cin.ignore();
                            getline(cin,n);
                            p->productname = n;
                            break;
                        case 3:
                            cout<<"\nENTER NEW QUANTITY OF PRODUCT - ";
                            cin>>quan;
                            p->quantity = quan;
                            break;
                        case 4:
                            return 0;
                        default:
                            cout<<"\nINVALID CHOICE"<<endl;

                    }
                }
                else
                    p = p->next;
            }
            if(flag == 0)
            {
                cout<<"\nPRODUCT DOES'T EXIST"<<endl;
            }
            return 0;
        }
};

class customer : public stock
{
  public :

    void detail(long long int id)
    {
        int key,flag = 0;
        key = id%10;

        customernode *p = c[key];

        while(p)
        {
            if(p->customerID == id)
            {
                flag = 1;
                cout<<"\nCUSTOMER ID :- "<<p->customerID<<"\nCUSTOMER NAME :- "<<p->name<<"\nPOINTS :- "<<p->point<<endl;;
                break;
            }
            else
            {
                p=p->next;
            }
        }
        if(flag == 0)
        {
            cout<<"NOT EXISTS"<<endl;
        }
    }

};



class biling : public stock
{
  public :
    void buy_from_prodID(long long int id)
    {
        int key,flag = 0,n;
        key = id%10;
        bilingnode *p = new bilingnode;
        managernode *q;
        q = m[key];

        while(q)
        {
            if(q->productID == id)
            {
                flag = 1;
                if(b[key] == NULL)
                {
                    p->productID = id;
                    p->rate = q->rate;
                    p->name = q->productname;
                    p->next = NULL;
                    cout<<"\nENTER HOW MANY QUANTITY YOU WANT TO BUY :- ";
                    cin>>n;
                    if(n <= q->quantity)
                    {
                        p->quantity = n;
                    }
                    else
                    {
                        cout<<"\nSORRY WE DON'T HAVE MUCH STOCK\n\nWE HAVE "<<q->quantity<<" QUANTITYS"<<endl;
                    }
                    b[key] = p;
                }
                else
                {
                    bilingnode *tmp;
                    tmp = b[key];
                    p->productID = id;
                    p->rate = q->rate;
                    p->name = q->productname;
                    p->next = NULL;

                    while(tmp->next != NULL)
                    {
                        tmp = tmp->next;
                    }

                    tmp->next = p;

                    cout<<"\nENTER HOW MANY QUANTITY YOU WANT TO BUY :- ";
                    cin>>n;
                    if(n <= q->quantity)
                    {
                        p->quantity = n;
                    }
                    else
                    {
                        cout<<"\nSORRY WE DON'T HAVE MUCH STOCK\n\nWE HAVE "<<q->quantity<<" QUANTITYS"<<endl;
                    }

                }
            }
            q = q->next;
        }
        if(flag == 0)
        {
            cout<<"\nPRODUCT DOESN'T EXITS  "<<endl;
        }
    }

    void update_product(long long int id)
    {
        int key,choice,n;
        key = id%10;
        bilingnode *p;
        p = b[key];
        cout<<"\n1.CANCEL PRODUCT\n2.CHANGE QUANTITY"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                    if(p->productID == id && p->next == NULL)
                    {
                        p = NULL;
                    }
                    else if(p->productID == id && p->next != NULL)
                    {
                        p->productID = p->next->productID;
                        p->name = p->next->name;
                        p->quantity = p->next->quantity;
                        p->rate = p->next->rate;

                        bilingnode *tmp;
                        tmp = p->next;
                        p->next = tmp->next;
                        delete tmp;
                    }
                    else
                    {
                        while(p)
                        {
                            if(p->next->productID == id)
                            {
                                bilingnode *tmp;
                                tmp = p->next;
                                p->next = tmp->next;
                                delete tmp;
                                break;
                            }
                            else
                            {
                                p = p->next;
                            }
                        }
                    }
                break;
            case 2:
                cout<<"\nENTER HOW MANY QUANTITY YOU WANT TO CANCEL - ";
                cin>>n;
                if(p->productID == id)
                {
                        if(n < p->quantity)
                        {
                            p->quantity = p->quantity-n;
                        }
                        else if(n > p->quantity)
                        {
                            cout<<"\nSORRY\nYOUR PRODUCT QUATITY - "<<p->quantity;
                        }
                        else
                        {
                            if(p->next == NULL)
                            {
                                p = NULL;
                            }
                            else
                            {
                                p->productID = p->next->productID;
                                p->name = p->next->name;
                                p->quantity = p->next->quantity;
                                p->rate = p->next->rate;

                                bilingnode *tmp;
                                tmp = p->next;
                                p->next = tmp->next;
                                delete tmp;
                            }
                        }
                }
                else
                {
                    while(p->next)
                    {
                        if(p->next->productID == id)
                        {
                            if(n > p->next->quantity)
                            {
                                cout<<"\nSORRY\nYOUR PRODUCT QUATITY - "<<p->next->quantity<<endl;
                                break;
                            }
                            else if(p->next->quantity > n)
                            {
                                p->next->quantity = p->next->quantity - n;
                                break;
                            }
                            else
                            {
                                bilingnode *q;
                                q = p->next;
                                p->next = q->next;
                                delete q;
                                break;
                            }
                         }
                         else
                         {
                             p = p->next;
                         }
                     }
                 }
                 break;
            default:
                cout<<"\nINVALID CHOICE"<<endl;
            }
    }

    void make_payment()
    {
        int i,key,flag = 0;
        static int tr_id = 1;
        long long int id;
        string na;
        float total = 0;
        bilingnode *p = new bilingnode;
        managernode *check;


        cout<<"\nCUSTOMER ID - ";
        cin>>id;
        cout<<"\nCUSTOMER NAME :- ";
        cin.ignore();
        getline(cin,na);
        cout<<"\nTRANSECTION ID - "<<tr_id++;
        p->transectionID = tr_id;

        cout<<"\nPRODUCT ID\t\tPRODUCT NAME\t\tRATE\t\tQUANTITY\t\tTOTAL  ";
        for(i=0;i<10;i++)
        {
            p = b[i];
            check = m[i];
            while(p)
            {
                cout<<"\n"<<p->productID<<"\t\t"<<p->name<<"\t\t"<<p->rate<<"\t\t"<<p->quantity<<"\t\t"<<p->quantity*p->rate;
                total = total + p->quantity*p->rate;

                while(check)
                {
                    if(p->productID == check->productID)
                    {
                        check->quantity = check->quantity - p->quantity;
                    }
                    check = check->next;
                }

                p = p->next;
            }
        }

        cout<<"\n--------------------------------------------------------------";
        cout<<"\nTOTAL AMOUNT = "<<total<<"\n\n"<<endl;

        customernode *q;
        customernode *tmp;
        customernode *temp = new customernode;
        key = id%10;
        q = c[key];
        tmp = c[key];
        temp->name = na;
        temp->next = NULL;
        temp->customerID = id;

        while(q)
        {
            if(q->customerID == id && q->next == NULL)
            {
                flag = 1;
                q->point = q->point + total;
                temp->point = q->point;
                c[key] = temp;
                break;
            }
           else if(q->customerID == id)
            {
                flag = 1;
                q->point = q->point + total;
                temp->point = q->point;
                q = temp;
                break;
            }
            else
            {
                tmp = q;
                q = q->next;
            }
        }
        if(flag == 0)
        {
            temp->point = total;

            if(tmp == NULL)
            {
                c[key] = temp;
            }
            else
            {
                tmp->next = temp;
            }
        }
        else
        {
            delete tmp;
        }

        for(i=0;i<10;i++)
        {
            b[i] = NULL;
        }

}


};


//function for manager manu
int manager_menu()
{
    int choice1;
    string n;
    long long int id;
    manager m;

    while(1)
    {
        //system("CLS");
        cout<<"\n1.Manager Info.\n2.Update Manager Detail\n3.Add Stock\n4.Delete Stock\n5.Stock Detail\n6.Update Stock\n7.Exit"<<endl;
        cin>>choice1;
        switch(choice1)
        {
            case 1:
                m.managerinfo();
                break;
            case 2:
                cout<<"\nEnter Manager Name: -- ";
                cin.ignore();
                getline(cin,n);
                cout<<"\nEnter Manager ID: -- ";
                cin>>id;
                m.change_manager(id,n);
                break;
            case 3:
                m.add_stock();
                break;
            case 4:
                cout<<"\nEnter Product ID : -  ";
                cin>>id;
                m.delete_stock(id);
                break;;
            case 5:
                cout<<"\nEnter Product ID : -  ";
                cin>>id;
                m.stock_detail(id);
                break;
            case 6:
                cout<<"\nEnter Product ID : -  ";
                cin>>id;
                m.update_stock(id);
                break;
            case 7:
                return 0;
            default:
                cout<<"\nINVALID CHOICE"<<endl;
            }
    }
}

//function for customer menu
int customer_menu()
{
    int choice;
    long long int id;
    customer c;
    while(1)
    {
        //system("CLS");
        cout<<"\n1.CUSTOMER DETAIL\n2.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nENTER CUSTOMER ID :- ";
                cin>>id;
                c.detail(id);
                break;
            case 2:
                return 0;
                break;
            default:
                cout<<"\nINVALID CHOICE"<<endl;
        }
    }
    return 0;
}

//function for biling counter menu
int bilingcounter_menu()
{
    int choice;
    long long int id;
    biling bill;
    while(1)
    {
        //system("CLS");
        cout<<"\n1.BUY PRODUCT\n2.UPDATE PRODUCT THAT  YOU BUY\n3.MAKE PAYMENT\n4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nENTER PRODUCT ID - ";
                cin>>id;
                bill.buy_from_prodID(id);
                break;
            case 2:
                cout<<"\nENTER PRODUCT ID - ";
                bill.update_product(id);
                break;
            case 3:
                bill.make_payment();
                return 0;
                break;
            case 4:
                return 0;
            default:
                cout<<"\nINVALID CHOICE"<<endl;
        }
    }
    return 0;
}


int main() {
    int i,j,k,l,choice;
    while(1)
    {
        //system("CLS");
        cout<<"---------------    SUPER MARKET    ---------------\n1.Customer\n2.Manager\n3.Biling Counter\n4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                customer_menu();
                break;
            case 2:
                manager_menu();
                break;
            case 3:
                bilingcounter_menu();
                break;
            case 4:
                return 0;
            default:
                cout<<"\nINVALID CHOICE"<<endl;

        }
    }
    return 0;
}

