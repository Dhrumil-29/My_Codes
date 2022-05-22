#include<stdio.h>
#include<conio.h>

void input(int *p)
{
    for(int i = 0;i<5;i++)
    {
        scanf("%d",p+i);
    }
    for(int i=0;i<5;i++)
    {
        printf("a[%d] = %d\n",i,*(p+i));
    }
}
int main()
{
    int a[5],*p;

    input(a);
    return 0;
}
