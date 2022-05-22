#include<stdio.h>
#include<conio.h>

int main()
{
    int x = 5;
    int *y,**z;//pointer variable consumes 2 bytes in memory

    y = &x;
    *y = 10;//change the value of variable x
    z = &y;

    printf("x = %d\n",x);//normal
    printf("x = %d\n",&x);//reference address
    printf("x = %d\n",*&x);//dereference of x
    printf("y = %d\n",y);
    printf("y = %d\n",&y);
    printf("y = %d\n",*y);
    printf("z = %d\n",z);//normal
    printf("z = %d\n",&z);//reference address
    printf("z = %d\n",**z);
    return 0;
}
