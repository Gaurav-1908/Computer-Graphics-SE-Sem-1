#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
class pixel
{
public:
float dp;
int x1,y1,rad;
void circle(int x,int y,int rad)
{
x1=0;
y1=rad;
dp=3-2*rad;
while(x1<=y1)
{
if(dp<=0)
dp+=(4*x1)+6;
else
{
dp+=4*(x1-y1)+10;
y1--;
}
x1++;
display(x1,y1,x,y);
}
}
void display(int x1,int y1,int x,int y)
{
putpixel(x1+x,y1+y,5);
putpixel(x1+x,y-y1,5);
putpixel(x-x1,y1+y,5);
putpixel(x-x1,y-y1,5);
putpixel(x+y1,y+x1,5);
putpixel(x+y1,y-x1,5);
putpixel(x-y1,y+x1,5);
putpixel(x-y1,y-x1,5);
}
};
class derive:public pixel
{

public:
void get()
{
cout<<"Enter x coordinate";
cin>>x1;
cout<<"Enter y coordinate";
cin>>y1;
cout<<"Enter radius";
cin>>rad;

}
};
int main()
{
int gd=DETECT,gm;
derive d;
d.get();
initgraph(&gd,&gm,0);
d.circle(d.x1,d.y1,d.rad);
getch();
closegraph();
return 0;
}
