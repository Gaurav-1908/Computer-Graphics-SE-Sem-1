#include <iostream>
#include <graphics.h>
using namespace std;

class point
{
    public:
    int x,y;
};

class poly
{
    private:
        int p[20];
        int inter[20],x,y;
        int v,xmin,ymin,xmax,ymax;
    public:
        int c;
        void read();
        void calcs();
        void display();
        void ints(float);
        void sort(int);
};


void poly::read()
{
    int i;
    
    cout<<"Enter the no of vertices of polygon:"<<endl;
    cin>>v;
    if(v>2)
    {
        for(i=0;i<v; i++) 
        {
            cout<<"Enter the co-ordinate no."<<i+1<<": ";
            cout<<"x"<<(i+1)<<" , y"<<(i+1)<<"=";
            cin>>p[i]>>p[i];
            
        }
        p[i]=p[0];
        p[i]=p[0];
        xmin=xmax=p[0];
        ymin=ymax=p[0];
    }
    else
        cout<<" Enter valid no. of vertices : "<<endl;
}

void poly::calcs(){ 
    for(int i=0;i<v;i++){
        if(xmin>p[i])
        xmin=p[i];
        if(xmax<p[i])
        xmax=p[i];
        if(ymin>p[i])
        ymin=p[i];
        if(ymax<p[i])
        ymax=p[i];
    }
}

void poly::display(){
    int ch1;
    char ch='y';
    float s,s2;
   
        
                s=ymin+0.01;
                delay(100);
                cleardevice();
                while(s<=ymax){
                    ints(s);
                    sort(s);
                    s++;
                }
              
}

void poly::ints(float z){

    int x1,x2,y1,y2,temp;
    c=0;
    for(int i=0;i<v;i++){
    
        x1=p[i];
        y1=p[i];
        x2=p[i+1];
        y2=p[i+1];
        if(y2<y1){
        
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1){
        
            if((y1-y2)==0)
            x=x1;
            else{
            
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
            }
            if(x<=xmax && x>=xmin)
                inter[c++]=x;
        }
    }
}

void poly::sort(int z){

    int temp,j,i;

        for(i=0;i<v;i++){
        
            line(p[i],p[i],p[i+1],p[i+1]); 
        }
        delay(100);
        for(i=0; i<c;i+=2){
        
            delay(100);
            line(inter[i],z,inter[i+1],z);  
        }
}

int main(){

    int cl;
    int gd=DETECT, gm;
    initgraph(&gd, &gm,NULL);
    
    poly x;
    x.read();
    x.calcs();
    cleardevice();
    cout<<"Enter the colour u want:(0-15) : "; 
    cin>>cl;
    
    setcolor(cl);
    x.display();
    
    delay(1000);
    closegraph(); 
    getch();
    return 0;
}
