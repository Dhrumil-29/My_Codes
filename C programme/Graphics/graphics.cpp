#include<graphics.h>
#include<iostream>

using namespace std;
void draw()
{
    initwindow(400,400);
    line(100,100,200,100);
}

main()
{
    draw();
    getch();
}
