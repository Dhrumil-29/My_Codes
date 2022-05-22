#include <HeaderFiles.h>

using namespace std;
int compare(const void* a,const void* b)
{
    int A = *((int*)a);
    int B = *((int*)b);
    return A - B;
}
/*
///callback func should compar 2 integer,should return 1 if first element
///has higher rank,0 if elements are equal and -1 if second element has higher rank
int compare(int a,int b)
{
    if(a > b) return 1;
    else return -1;
}
int abosulte_compare(int a,int b)
{
    if(abs(a) > abs(b)) return 1;
    else return -1;
}
void BubbleSort(int *A,int n,int (*compare)(int,int))
{
    int i,j,temp;
    for(i = 0 ; i < n;i++ )
    {
        for(j=0;j<n-1;j++)
        {
            if(compare(A[j],A[j+1]) > 0)///For decreasing order we do A[j] < A[j+1]
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
}
*/
/*
void change_value(int *a,int *b)
{
    int ptr = *a;
    *a = *b;
    *b = ptr;
}
void mul_with_two(int *a,int n)
{
    for(int i = 0; i < n ; i++)
    {
        a[i] = 2 + *(a + i);///*(a + i)
    }
}
*/
/*
int *Add(int *a,int *b)///this function return the address of return variable
{
    int c = (*a) + (*b);
    return &c;
}
*/
/*
int Add(int a,int b)
{
    return a+b;
}
void PrintHello(char* name)
{
    cout<<"Hello "<<name<<endl;
}

void A()
{
    cout<<"Hello "<<endl;
}
void B(void (*ptr)())///function pointer as argument
{
    ptr();///call-back function that "ptr" points to
}
*/
int main()
{
    ///For simple pointer variable;
    /*
    int x = 5,y = 10;
    int *ptr;
    ptr = &x;
    ///*ptr = 10;
    cout<<"Address of variable x = "<<&x<<endl;
    cout<<"Address of pointer variable ptr = "<<&ptr<<endl;
    cout<<"value of x = "<<x<<endl;
    cout<<"value of y = "<<y<<endl;
    ///cout<<"value of ptr = "<<ptr<<endl;
    change_value(&x,&y);
    cout<<"value of x = "<<x<<endl;
    cout<<"value of y = "<<y<<endl;
    free x;
    */
    ///For array
    /*
    ///int x[5] = {1,2,3,4,5};
    int *x = (int *)calloc(5,sizeof(int));///new int(5);///(int *)malloc(20);
    int n = sizeof(x)/sizeof(x[0]);
    int i;

    for(i = 0; i < 5 ; i++)
    {
        x[i] = i+1;
    }

    for(i = 0; i < 5 ; i++)
    {
        cout<<i<<"  "<<x[i]<<endl;
    }
    cout<<endl;
    mul_with_two(x,5);
    cout<<"Address of pointer x = "<<&x<<"\tBase Address of x = "<<x<<endl;
    for(i = 0; i < 5 ; i++)
    {
        cout<<i<<"  "<<x[i]<<"\t Address:- "<<&x[i]<<endl;
    }
    cout<<endl;
    delete[] x;
    */
    /*
    ///For char variable with dynamic memory allocation;
    ///print Hello World ,First write Hell then in real time concatinate World;

    char x[12] = "Hello World";
    cout<<"By normal assign:- \t"<<x<<endl;
    ///Now by dynamic memory allocation
    char *ptr = new char(6);///(char*)malloc(6*sizeof(char));
    strcpy(ptr,"Hello");///ptr = "hello" we can't do that
    cout<<ptr<<endl;
    cout<<"sizeof char:- "<<sizeof(char)<<endl;
    cout<<"sizeof char ptr:- "<<sizeof(ptr)<<endl;
    ptr = (char *)realloc(ptr,12);///we cannt do realloc with new char[12];
    strcat(ptr," World");
    cout<<ptr<<endl;
    delete ptr;
    */
    /*
    ///For pointer as function returns
    int a = 2,b = 4;
    int* ptr = Add(&a,&b);///address of returning variable address store in ptr;
    cout<<"Sum = "<<*ptr<<endl;///return Sum = 6;
    */
/*
    ///Function Pointers
    ///pointer to function that should take
    ///(int,int)as argument/parameter and return int
    int (*p)(int,int);
    int a = 2,b = 6;
    p = &Add;///also write p = Add also return function address
    int c = p(a,b);///(*p)(a,b);///de - referencing and executing the function
    cout<<"c = "<<c <<endl;
    void (*ptr)(char*);
    ptr = PrintHello;
    ptr("Tom");

    ///Function Pointer and Call Back
    void (*pnt)() = A;
    B(A);///A is a callback func.
    */
    /*
    ///Example
    int A[] = {-31,22,-1,50,-6,4};///sort in increase numbers
    BubbleSort(A,6,abosulte_compare);
    for(int i=0;i<6;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    */
    ///Above example by a one by default function qsort
    int i,A[] = {-31,22,-1,50,-6,4};
    qsort(A,6,sizeof(int),compare);
    for(int i=0;i<6;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
