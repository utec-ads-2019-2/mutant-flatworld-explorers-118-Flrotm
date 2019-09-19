#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int pX=0,pY=0,x=0,y=0;
    int xcambios[4] = {0, 1, 0, -1};
    int ycambios[4] = {1, 0, -1, 0};
    char direc[4] = {'N', 'E', 'S', 'W'};
    char inicio;
    string movimientos;
    string resultado;
    cin >>pX>>pY;
    vector<vector<bool>> tablero(pY+1, vector<bool> (pX+1, false));



    while (cin>>x>>y>>inicio>>movimientos){
        int direccion=0;
        for (int i=1; i<5;i++){
            if (inicio==direc[i])
                direccion=i;}
                bool fuera = false;

        for (int i=0;i<movimientos.size();i++){
            if (movimientos[i]=='R')
                direccion=(direccion+1)%4;
            else if (movimientos[i] =='L')
                direccion=(direccion+3)%4;
            else {
                if (x+xcambios[direccion]==-1 or x+xcambios[direccion]==pX+1 
                or y+ycambios[direccion]==-1 or y+ycambios[direccion]==pY+1) {
                    if (!tablero[x][y]) {
                        tablero[x][y]=fuera=true;
                        break;
                    }
                } else {
                    x= x+xcambios[direccion];
                    y= y+ycambios[direccion];
                }
            }
        }

        if(fuera)
            resultado=" LOST";
        else resultado="";


        cout<<x<<' '<<y<<' '<<direc[direccion]<<resultado<<endl;
    }
}
