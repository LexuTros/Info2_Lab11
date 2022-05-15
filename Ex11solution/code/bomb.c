#include <stdio.h>

int max(int a, int b)
{
return a>b?a:b;
}
int calculate(char M[3][4],int x, int y ){	
int V_l[3][4] = {
    {0,0,0,0},
    {0,0,0,0},  
	{0,0,0,0}
};
int V_r[3][4] = {
    {0,0,0,0},
    {0,0,0,0},  
	{0,0,0,0}
};
int V_u[3][4] = {
    {0,0,0,0},
    {0,0,0,0},  
	{0,0,0,0}
};
int V_d[3][4] = {
    {0,0,0,0},
    {0,0,0,0},  
	{0,0,0,0}
};		
int res = 0;       
for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
        int t = (j == 0 || M[i][j] == 'W') ? 0 : V_l[i][j - 1];
        V_l[i][j] = M[i][j] == 'B' ? t + 1 : t;
    }
    for (int j = y - 1; j >= 0; --j) {
        int t = (j == y - 1 || M[i][j] == 'W') ? 0 : V_r[i][j + 1];
        V_r[i][j] = M[i][j] == 'B' ? t + 1 : t;
    }
}
for (int j = 0; j < y; ++j) {
    for (int i = 0; i < x; ++i) {
        int t = (i == 0 || M[i][j] == 'W') ? 0 : V_u[i - 1][j];
        V_u[i][j] = M[i][j] == 'B' ? t + 1 : t;
    }
    for (int i = x - 1; i >= 0; --i) {
        int t = (i == x - 1 || M[i][j] == 'W') ? 0 : V_d[i + 1][j];
        V_d[i][j] = M[i][j] == 'B' ? t + 1 : t;
    }
}
for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
        if (M[i][j] == '0') {
            res = max(res, V_l[i][j] + V_r[i][j] + V_u[i][j] + V_d[i][j]);
        }
    }
}
return res;}
int main() {
	char M[3][4] = {
    {'0','B','0','0'},
    {'B','0','W','B'},  
	{'0','B','0','0'} 
};

  int res = calculate(M,3,4);
  printf("%d ", res);
}
