#include<stdio.h>
#include<conio.h>

int main()
{
    //create one block by malloc
    float *ptr;
    ptr = (float *)malloc(4)//4 byte; float premative type
    //calloc(x,y):-x=numbers of blocks,y=bytes,array type.
    //realloc(x,y):-for change the size of dynamic memory.x=pointer variable,y=size of bytes
    //free:- for free to pointing pointer variable only for dynamic variable
    return 0;
}
