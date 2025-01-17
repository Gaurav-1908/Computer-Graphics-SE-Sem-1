#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
class trans{
    int no;
    int mat1[10][10], transMatrix[3][3], scalMatrix[3][3];
    float rotMatrix[3][3];
    int tx, ty, sx, sy,j;
    float theta;
    public:
    void accept(){
       
        cout << "\nEnter Number of points:";
        cin >> no;
        for (int i = 0; i < no; i++){
            cout << "\nEnter for Point " << i + 1 << ":";
            cout << "\nEnter (x,y) Co-ordinates : ";
            cin >> mat1[i][0]>>mat1[i][1];
            mat1[i][2] = 1;
        }
        
           

    }

    void showMatrix(){
        cout << "\nMAtrix:\n";
        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                cout << "\t" << mat1[i][j];
            }
            cout << "\n";
        }
    }

    void draw(){
         setbkcolor(WHITE);
        int i;
        delay(100);
        for (i = 0; i < no - 1; i++){
            line1(mat1[i][0] + 100, mat1[i][1] + 100, mat1[i + 1][0] + 100, mat1[i + 1][1] + 100);
        }
        line1(mat1[i][0] + 100, mat1[i][1] + 100, mat1[0][0] + 100, mat1[0][1] + 100);
    }

    void line1(int x1, int y1, int x2, int y2){
        float dx = x2 - x1;
        float dy = y2 - y1;
        int length;
        if (abs(dx) > abs(dy))
        length = abs(dx);
        else
        length = abs(dy);
        float xinc = dx / length;
        float yinc = dy / length;
        float x = x1;
        float y = y1;
        int i = 0;
        while (i <= length)
        {
        putpixel(x, y, BLACK);
        x = x + xinc;
        y = y + yinc;
        i++;
        }
    }

    void createTrans(){
        cout << "\nEnter Tx: and Ty:";
        cin >> tx >> ty;
        transMatrix[2][0] = tx;
        transMatrix[2][1] = ty;
        transMatrix[0][0] = transMatrix[1][1] = transMatrix[2][2] = 1;
        transMatrix[1][0] = transMatrix[0][1] = transMatrix[1][2] = 0;
        cout << "\nTrans Matrix:\n";
        //for (int i = 0; i < 3; i++){
            //for (int j = 0; j < 3; j++)
            //cout << "\t" << transMatrix[i][j];
        //cout << "\n";
        //}
    }

    trans operator*(trans b){
        trans c;
        c.no = no;
        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                c.mat1[i][j] = 0;
            }
        }
        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    c.mat1[i][j] = c.mat1[i][j] + mat1[i][k] * b.transMatrix[k][j];
                }
            }
        }
        return c;
    }

    void createScal(){
        cout << "\nEnter Sx and SY:";
        cin >> sx >> sy;
        scalMatrix[0][0] = sx;
        scalMatrix[1][1] = sy;
        scalMatrix[2][2] = 1;
        scalMatrix[0][1] = scalMatrix[0][2] = scalMatrix[1][0] = scalMatrix[1][2] = scalMatrix[2][0] =
        scalMatrix[2][1] = 0;
        cout << "\nScaling Matrix:\n";
        //for (int i = 0; i < 3; i++){
          //  for (int j = 0; j < 3; j++)
            //cout << "\t" << scalMatrix[i][j];
        //cout << "\n";
        //}
    }

    trans operator+(trans b){
        trans c;
        c.no = no;
        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                c.mat1[i][j] = 0;
                for (int k = 0; k < 3; k++){
                c.mat1[i][j] = c.mat1[i][j] + mat1[i][k] * b.scalMatrix[k][j];
                }
            }
        }
        return c;
    }

    void createRota(){
        cout << "\nEnter The angle by which to be rotated:";
        cin >> theta;
        int choice;
        cout << "\n1.Anticlockwise\n2.Clockwise\nEnter Choice:";
        cin >> choice;

        rotMatrix[0][2] = rotMatrix[1][2] = rotMatrix[2][0] = rotMatrix[2][1] = 0;
        rotMatrix[2][2] = 1;
        rotMatrix[0][0] = rotMatrix[1][1] = cos(theta * M_PI / 180);

        if (choice == 1){
            rotMatrix[0][1] = sin(theta * M_PI / 180);
            rotMatrix[1][0] = -sin(theta * M_PI / 180);
        }
        else{
            rotMatrix[0][1] = -sin(theta * M_PI / 180);
            rotMatrix[1][0] = sin(theta * M_PI / 180);
        }

        cout << "\nRota Matrix:\n";
        //for (int i = 0; i < 3; i++){
          //  for (int j = 0; j < 3; j++){
                //cout << "\t" << rotMatrix[i][j];
            //}
            //cout << "\n";
        //}
    }

    trans operator-(trans b){
        trans c;
        c.no = no;
        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                c.mat1[i][j] = 0;
            }
        }

        for (int i = 0; i < no; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    c.mat1[i][j] = c.mat1[i][j] + mat1[i][k] * b.rotMatrix[k][j];
                }
            }
        }
        return c;
    }
};

int main(){
    int gd = DETECT, gm;
    int choice = 0;

    initgraph(&gd,&gm,NULL);
    trans a, b, c;
    a.accept();
    //a.showMatrix();
    a.draw();

    while (choice != 4){
        cout << "\nMenu\n1.Translation\n2.Scaling\n3.Rotation\n4.Exit\nEnter Choice : ";
        cin >> choice;
        switch (choice){
            case 1:
                b.createTrans();
                c = a * b;
                //c.showMatrix();
                c.draw();
                break;
            case 2:
                b.createScal();
                c = a + b;
                //c.showMatrix();
                c.draw();
                break;
            case 3:
                b.createRota();
                c = a - b;
                //c.showMatrix();
                c.draw();
                break;
            case 4:
                break;
        }
    }
    closegraph();
    return 0;
}