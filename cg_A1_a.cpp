#include <iostream>
using namespace std;
#include <graphics.h>
#include <math.h>

class algorithm{
	public:
	float x,y,x1,y1,x2,y2,dx,dy,step,xin,yin,x3,x4,y3,y4;
	
	
	void line(int x1,int y1,int x2,int y2){
		dx=(x2-x1);
		dy=(y2-y1);
 
		if(abs(dx)>=abs(dy))
			step=dx;
		else{
			step=dy;
 		    }
 		    
		xin=dx/step;
		yin=dy/step;
 
		x=x1;
		y=y1;
 
		int i=1;
		while(i<=step)
		{
			putpixel(x,y,5);
			x=x+xin;
			y=y+yin;
			i=i+1;
		
		}
	}
};

class getdata:public algorithm{
	public:
	void display(){
		cout<<"\nEnert the Starting Coordinate : ";
		cin>>x3>>y3;
		cout<<"\nEnter Ending Coordinates : ";
		cin>>x4>>y4;
		line(x3,y3,x4,y4);
	}
};

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm,NULL);
	getdata l;
	l.display();
	
	getch();
	closegraph();
	return 0;

}
















