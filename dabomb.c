#include <stdio.h>
#include <stdlib.h>

#define W -1
#define B 1


int x = 4;
int y = 4;

int M[4][4] = { 
    {0, B, W, 0},
    {B, 0, B, 0},
    {W, 0, W, B},
    {0, B, 0, 0}
};

int calcVleft(int M[4][4], int Vl[4][4], int i, int j){
    if (j < 0 || M[i][j] == W) {return 0;}
    if (j == 0) {return M[i][j];}
    return Vl[i][j-1] + M[i][j];
}

int calcVright(int M[4][4], int Vr[4][4], int i, int j){
    if (j >= y || M[i][j] == W) {return 0;}
    if (j == y-1) {return M[i][j];}
    return Vr[i][j+1] + M[i][j];
}

int calcVup(int M[4][4], int Vu[4][4], int i, int j){
    if (i < 0 || M[i][j] == W) {return 0;}
    if (i == 0) {return M[i][j];}
    return Vu[i-1][j] + M[i][j];
}

int calcVdown(int M[4][4], int Vd[4][4], int i, int j){
    if (i >= x || M[i][j] == W) {return 0;}
    if (i == x-1) {return M[i][j];}
    return Vd[i+1][j] + M[i][j];
}

int calculate(int M[4][4], int x, int y){
    int Vl[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    int Vr[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    int Vu[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    int Vd[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {Vl[i][j] = calcVleft(M, Vl, i, j);}
        
        for (int j = y-1; j >= 0; j--)
        {Vr[i][j] = calcVright(M, Vr, i, j);} 
    }
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {Vu[i][j] = calcVup(M, Vu, i, j);}
        
        for (int i = x-1; i >= 0; i--)
        {Vd[i][j] = calcVdown(M, Vd, i, j);} 
    }
    
    int res = 0;
    int temp = 0;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {   
            if (M[i][j] == 0){
                temp = Vl[i][j] + Vr[i][j] + Vu[i][j] + Vd[i][j];
                if (temp > res) {res = temp;}
            }
        }
    }
    return res;
}

int main(){
    int res = 0;

    res = calculate(M, x, y);
    printf("%d", res);

    return 0;
}