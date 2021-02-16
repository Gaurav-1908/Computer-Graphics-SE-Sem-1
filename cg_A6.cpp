#include<iostream>
#include<graphics.h>
using namespace std;

class lineclip{
    public:
    int Wx1,Wy1,Wx2,Wy2,x1,y1,x2,y2,code1,code2,temp,m,x,y;

    lineclip(){
        cout<<"Enter Upper left and Lower Right :";
        cin>>Wx1>>Wy1>>Wx2>>Wy2;
        rectangle(Wx1,Wy1,Wx2,Wy2);

        cout<<"Enter Starting and Ending points of line :";
        cin>>x1>>y1>>x2>>y2;
        line(x1,y1,x2,y2);
        delay(2000);

        displayline();
       
    }

    int getcode(int x, int y){
        int code=0000;
        if(x<Wx1){
            code |= 0001;
        }   
        else if(x>Wx2){
            code |= 0010;
        }
        else if (y<Wy1){
            code |= 0011;
        }
        else  if (y>Wy2){
            code |= 0400;
        }
        return code; 
    }

    void displayline(){

        m=(y2-y1)/(x2-x1);
        
        code1=getcode(x1,y1);
        code2=getcode(x2,y2);

        cleardevice();
        rectangle(Wx1,Wy1,Wx2,Wy2);

        if(code1 == 0000 && code2==0000){
            line(x1,y1,x2,y2);
        }

        else if(code1 !=0000 && code2 !=0000 ){
        }

        else{
            if (code1==0000)
                temp=code2;
            else
                temp=code1;

            if(temp & 0100 != 0000){
                x = x1 + (Wy1-y1)/m;
			    y = Wy1;
            }

            else if(temp & 0011 != 0000){
                x=x1+(Wy2-y1)/m;
                y=Wy2;
            }

            else if(temp & 0010 != 0000){
                y=y1+(Wx1-x1)*m;
                x=Wx2;
            }

            else if(temp & 0001 != 0000){
                y=y1+(Wx2-x1)*m;
                x=Wx1;
            }

            if(temp == code1){
                x1=x;
                y1=y;
            }

            else{
                x2=x;
                y2=y;
            }
            line(x1,y1,x2,y2);
        }

    }
};

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    lineclip l;

    getch();
    return 0;
}



