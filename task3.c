#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Inf 9999

int D[20][20];

int max(int a, int b){
    if (a > b) {return a;}
    else {return b;}
}

int DLCSAlgo(char S[], int i, int j){
    // Value already exists
    if (D[i][j] != Inf)
    {
        return D[i][j];
    }
    // Substring <= 1
    if (i >= j)
    {
        D[i][j] = 0;
        return 0;
    }
    
    int val1 = 0;
    int val2 = 0;
    if (S[i] == '(' && S[j] == ')')
    {
        val1 = DLCSAlgo(S, i+1, j-1) + 2;
    }

    for (int k = i; k < j; k++)
    {
        val2 = max(val2, DLCSAlgo(S, i, k) + DLCSAlgo(S, k+1, j));
    }
    
    int res = max(val1, val2);

    D[i][j] = res;
    return res;
}

int calculate(char S[], int n){
    return DLCSAlgo(S, 0, n-1);
}

int main(){
    char S[20] = {"(()))()(())()()()())"};
    int n = strlen(S);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            D[i][j] = Inf;
        }
    }
    
    int res = calculate(S, n);
    printf("%d\n", res);
    printf("%d", n);

    return 0;
}