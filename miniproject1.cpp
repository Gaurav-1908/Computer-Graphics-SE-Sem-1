#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class vehicle{
    public:
    float dx,dy,step,x,y;
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,x10,y10,x11,y11,x12,y12,x13,y13,x14,y14,dp,x_1,y_1;

    void line1(int x1,int y1,int x2,int y2){
        step;
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
			putpixel(x,y,4);
			x=x+dx;
			y=y+dy;
			i=i+1;
		
		}
	}

    void line2(int x1, int y1, int x2, int y2, int n){
        int i=0;
        for(i=0; i<n; i++){
            setcolor(15);
            line(x1,y1+i,x2,y2+i);
        }
    }

    void line3(int x1,int y1,int x2,int y2){
        step;
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
			putpixel(x,y,15);
			x=x+dx;
			y=y+dy;
			i=i+1;
		
		}
	}

    void circle1(int x,int y,int rad){
		
		x_1=0;
		y_1=rad;
		dp=3-2*rad;
		while(x_1<=y_1){
			if(dp<=0)
				dp+=(4*x_1)+6;
			else{
				dp+=4*(x_1-y_1)+10;
				y_1--;
			}
			x_1++;
			display(x_1,y_1,x,y);
		}
	}

    void display(int x1,int y1,int x,int y)
			{
				putpixel(x1+x,y1+y,WHITE);
				putpixel(x1+x,y-y1,WHITE);
				putpixel(x-x1,y1+y,WHITE);
				putpixel(x-x1,y-y1,WHITE);
				putpixel(x+y1,y+x1,WHITE);
				putpixel(x+y1,y-x1,WHITE);
				putpixel(x-y1,y+x1,WHITE);
				putpixel(x-y1,y-x1,WHITE);
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
			//floodfill(x+1,y+1,old,newcol);  
			floodfill(x-1,y+1,old,newcol);  
			//floodfill(x+1,y-1,old,newcol);  
			//floodfill(x-1,y-1,old,newcol);  
		}  
	}  
   
    void rect(int x1, int y1, int x2, int y2){
        line3(x1,y1,x2,y1);
        line3(x2,y1,x2,y2);
        line3(x1,y2,x2,y2);
        line3(x1,y1,x1,y2);
        floodfill(x1+1,y1+1,0,15);
    }

    void calculate_y(int y){
        y1 = y;
        y2 = y1;
        y3 = y2-26;
        y4 = y3;
        y5 = y2;
        y6 = y4+40;
        y7 = y1+40;
        y8 = y7;
        y9 = y8;
        y10 = y9;
    }

    void calculate_x(int x){
        x1=x;
        x2 = x1+70;
		x3 = x2;
		x4 = x3+30;
		x5 = x4+10;
		x6 = x1+150;
		x7 = x6;
		x8 = x1;
		x9 = x1+30;
		x10 = x1+110;
    }

    void draw(){
        y=300;
        calculate_y(y);
        x=20;

        for(x=20; x<getmaxx(); x+=5){
            calculate_x(x);

            rect(0,350,getmaxx(),360);
            setcolor(14);
            pieslice(160,100,0,360,40);

            line1(x1,y1,x2,y2);
            line1(x3,y3,x2,y2);
            line1(x3,y3,x4,y4);
            line1(x4,y4,x5,y5);
            line1(x5,y5,x6,y6);
            line1(x6,y6,x7,y7);
            line1(x8,y8,x7,y7);
            line1(x1,y1,x8,y8);

            line2(x1,y1+10,x2,y2+10,10);
            floodfill(x3+1,y3+1,0,4);

            setcolor(0);
            pieslice(x9,y9,180,360,15);
            pieslice(x10,y10,180,360,15);

            setcolor(15);
            
            pieslice(x9,y9,00,180,10);
            pieslice(x10,y10,0,180,10);
            pieslice(x9,y9,180,360,10);
            pieslice(x10,y10,180,360,10);
            
            delay(100);
            cleardevice();
        }
    }
};

int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm,NULL);

    vehicle l;
    l.draw();

    getch();
    closegraph();

    return 0;
}
