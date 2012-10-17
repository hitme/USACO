/*
ID: zltsang1
LANG: C
TASK: money
*/
#include <stdio.h>

int cng[25];
#define dp1 10000+1
#define dp2 25+1
long long dp[dp2][dp1];

main () {
    FILE *fin  = fopen ("money.in", "r");
    FILE *fout = fopen ("money.out", "w");
	long long ret;
	int av,an;
	int i,j,k,a;
	
    fscanf (fin, "%d %d", &av,&an);
	for(i=0;i<av;i++){
		fscanf (fin, "%d", cng+i);
	}
	
	for(i=0;i<=an;i+=cng[0])dp[0][i]=1;
	for(i=1;i<av;i++){
		for(j=0;j<=an;j++){
			for(k=j;k>=0;k-=cng[i])
				dp[i][j]+=dp[i-1][k];
		}
	}
	ret=dp[av-1][an];
    fprintf (fout, "%lld\n",ret);
    exit (0);
}