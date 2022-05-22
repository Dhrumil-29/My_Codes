#include<stdio.h>
#include<conio.h>

//premative data type
//for read abelity
//enum month
//{
//    jan=1,feb,mar//jan=0,feb=1,...//jan=1,feb=2,...
//};
enum boolean
{
    false,true;
};
enum boolean isEven(int x)
{
    if(x%2==0)
        return(true);
    else
        return (false);
}
int main()
{
    enum boolean result;
    int n;
    n = 10;
    result = isEven(n);
    if(result == true)
        print even;
    else
        print odd;
    return 0;
}
