#include <stdio.h>
#include <string.h>

int D[20][20];
int inf = 999;
int max(int a, int b)
{
return a>b?a:b;
}

int DAlgo(char S[20],int i, int j) {
	if (D[i][j] != inf){return D[i][j];
	}else{
	
	int res;
	if (i >= j){
		D[i][j]=0;
		return 0;
	}
  if (S[i] == 40 && S[j] == 41) {
   int item1 = DAlgo(S,i+1,j-1) + 2;
   int item2 = DAlgo(S,i,i) + DAlgo(S,i+1,j);
    for (int k = i+1; k < j; k++) {
    	item2 = max(item2,DAlgo(S,i,k) + DAlgo(S,k+1,j));
    }
   res = max(item1,item2);
   
   }
  else {
   int item2 = DAlgo(S,i,i) + DAlgo(S,i+1,j);
    for (int k = i+1; k < j; k++) {
    	item2 = max(item2,DAlgo(S,i,k) + DAlgo(S,k+1,j));
    }
	res = item2;
  }
  D[i][j] = res;
  return res;}
}
int calculate(char S[20], int n){
return DAlgo(S,0,n-1);
}

int main() {
  char S[20] = "((()))";	
  int n = strlen(S);
  for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) {D[i][j]=inf;}}
  int res = calculate(S,n);
  printf("%d ", res);
}