#include<iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void display(int x1,int y1,int x,int y)
			{
				putpixel(x1+x,y1+y,RED);
				putpixel(x1+x,y-y1,RED);
				putpixel(x-x1,y1+y,RED);
				putpixel(x-x1,y-y1,RED);
				putpixel(x+y1,y+x1,WHITE);
				putpixel(x+y1,y-x1,WHITE);
				putpixel(x-y1,y+x1,WHITE);
				putpixel(x-y1,y-x1,WHITE);
			}

class pattern{
	public:
	float x,y,x1,y1,x2,y2,dx,dy,step,l,x3,y3,xl,yl,xr,yr,r1,r2,dp,x4,y4,x5,y5;
	
	void line1(int x1,int y1,int x2,int y2){
		dx=(x2-x1);
		dy=(y2-y1);
 
		if(abs(dx)>=abs(dy))
			step=dx;
		else
			step=dy;
 
		dx=dx/step;
		dy=dy/step;
 
		x=x1;
		y=y1;
 
		int i=1;
		while(i<=step)
		{
			putpixel(x,y,RED);
			x=x+dx;
			y=y+dy;
			i=i+1;
		
		}
	}
	
	void circle1(int x,int y,int rad){
		
		x1=0;
		y1=rad;
		dp=3-2*rad;
		while(x1<=y1){
			if(dp<=0)
				dp+=(4*x1)+6;
			else{
				dp+=4*(x1-y1)+10;
				y1--;
			}
			x1++;
			display(x1,y1,x,y);
		}
	}
		
	pattern(){
		cout<<"\nEnert the vertex Coordinate : ";
		cin>>x1>>y1;
		cout<<"\nEnter the length of side of Trianglr : ";
		cin>>l;
	
	}
	void cal(){
		
		
		x2=x1+l/2;
		y2=y1+sqrt(3)*l/2;
		line1(x1,y1,x2,y2);
		
		x3=x1-l/2;
		y3=y2;
		line1(x3,y3,x2,y2);
		line1(x1,y1,x3,y3);
		
		xl=(x2+x3)/2;
		yl=y3;
	
		xr=(2*xl+x1)/3;
		yr=(2*yl+y1)/3;
		
		r1=sqrt(((xl-xr)*(xl-xr))+((yl-yr)*(yl-yr)));
		circle1(xr,yr,r1);
		circle1(xr,yr,2*r1);
		
		
	}	
		
	
};

	




int main(){
	int gd=DETECT,gm;
	pattern p;
	
	initgraph(&gd,&gm,NULL);
	//p.getdata();
	p.cal();
	
	
	getch();
	closegraph();
	return 0;
}





































					
			
			
			
