/*
ID: zltsang1
LANG: C
TASK: nocows
*/
#include <stdio.h>

unsigned long long dp[110][210];//int does not work,unsigned either,

main () {
    FILE *fin  = fopen ("nocows.in", "r");
    FILE *fout = fopen ("nocows.out", "w");
    int an,ak,ret;
	int i,j,k,l;
	
    fscanf (fin, "%d %d", &an,&ak);
	//scanf ("%d %d", &an,&ak);
	
	dp[1][1]=1;
	for(i=1;i<ak;i++){
		for(j=1;j<an;j+=2){
			for(k=1;k<=an-1-j;k+=2){
				for(l=1;l<i;l++){
					dp[i+1][j+k+1]+=dp[i][j]*dp[l][k]*2%9901;//overflow caused by accumulation
					//dp[i+1][j+k+1]%=9901;//much better
				}
				dp[i+1][j+k+1]+=dp[i][j]*dp[i][k]%9901;
				//dp[i+1][j+k+1]%=9901;//much better
			}
		}
	}
	
	//printf ("%d\n",dp[ak][an]%9901);
    fprintf (fout, "%d\n",dp[ak][an]%9901);
    exit (0);
}