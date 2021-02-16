#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

int main(){
    int gd=DETECT,gm;
    int rhx,rhy,j,i;
    initgraph(&gd,&gm,NULL);
    for(i=0;i<500;i+=5){
        line(20,380,580,380);
        if(i%2==0){
            line(25+i,380,35+i,340);
            line(45+i,380,35+i,340);
            line(35+i,310,25+i,330);
            delay(20);
        }
        else{
            line(35+i,380,35+i,340);
            line(35+i,310,40+i,330);
            delay(20);
        }
        line(35+i,340,35+i,310);
        circle(35+i,300,10);
        line(35+i,310,50+i,330);
        line(50+i,330,50+i,280);
        line(15+i,280,85+i,280);

        arc(50+i,280,180,0,35);
        arc(55+i,330,360,180,5);
        rhx=getmaxx();
        rhy=getmaxy();

        for(j=0;j<100;j++){
            outtextxy(rand()%rhx,rand()%(rhy-50),"|");
            setcolor(WHITE);
        }
        delay(150);
        cleardevice();
    }
    return 0;
}