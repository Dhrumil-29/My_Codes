#include<stdio.h>
#include<conio.h>

int swap_function(int *a , int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return 0;

}
int main()
{
    int x,y;
    x = 5;
    y = 10;

    printf("x = %d\n",x);
    printf("y = %d\n",y);

    swap_function(&x,&y);
    printf("x = %d\n",x);
    printf("y = %d\n",y);
    return 0;
}
