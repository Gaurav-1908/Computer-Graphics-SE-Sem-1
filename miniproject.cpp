#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDA(int x1,int y1,int x2,int y2){
        int step;
		int dx=(x2-x1);
		int dy=(y2-y1);
 
		if(abs(dx)>=abs(dy))
			step=dx;
		else
			step=dy;
 
		dx=dx/step;
		dy=dy/step;
 
		int x=x1;
		int y=y1;
 
		int i=1;
		while(i<=step)
		{
			putpixel(x,y,4);
			x=x+dx;
			y=y+dy;
			i=i+1;
		
		}
	}

void floodfill(int x,int y,int old,int newcol){  
		int current;  
		current=getpixel(x,y);  
		if(current==old){  			
			putpixel(x,y,newcol);  
			floodfill(x+1,y,old,newcol);  
			floodfill(x-1,y,old,newcol);  
			floodfill(x,y+1,old,newcol);  
			floodfill(x,y-1,old,newcol);    
			floodfill(x-1,y+1,old,newcol);    
		}  
	}  

void Reactangle(int x1, int y1, int x2, int y2, int i){
        DDA(x1,y1,x2,y1);
        DDA(x2,y1,x2,y2);
        DDA(x1,y2,x2,y2);
        DDA(x1,y1,x1,y2);
        floodfill(x1+1,y1+1,0,i);
}

int main()
{	
	int gd=DETECT, gm;
    initgraph(&gd, &gm,NULL);
	int r,i,a,b,x,y;
	float PI=3.14;
	
	Reactangle(100,100,450,150,4);
	Reactangle(100,150,450,200,15);
	Reactangle(100,200,450,250,2);

	a=275;	
	b=175;	
	r=25;
	setcolor(BLUE);
	circle(a,b,r);

	for(i=0;i<=360;i=i+15)
	{
		x=r*cos(i*PI/180);
		y=r*sin(i*PI/180);
		line(a,b,a+x,b-y);
	}
	Reactangle(92,100,100,getmaxy(),15);
	//floodfill(93,101,0,15);

	getch();
	closegraph();
	return 0;
}