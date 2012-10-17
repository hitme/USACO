/*
ID: zltsang1
LANG: C
TASK: stamps
*/
#include <stdio.h>

typedef long long int64;
typedef long int32;

#define xn 50
int stm[xn];
#define xk 200
#define xs 10000
int dp[xk*xs];

main () {
    FILE *fin  = fopen ("stamps.in", "r");
    FILE *fout = fopen ("stamps.out", "w");
	//fout=stdout;
	
	int ak,an,ret;
    int i,j;
    fscanf (fin, "%d %d", &ak,&an);
	
	for(i=0;i<an;i++){
		fscanf (fin, "%d", stm+i);
		dp[stm[i]-1]=1;
	}
	
	ret=0;
	while(1){
		++ret;
		if(!dp[ret-1]||dp[ret-1]>ak)break;
		if(dp[ret-1]==ak)continue;
		for(i=0;i<an;i++){
			if(!dp[ret+stm[i]-1]||dp[ret+stm[i]-1]>dp[ret-1]+1)
				dp[ret+stm[i]-1]=dp[ret-1]+1;
		}
	}
	
    fprintf (fout, "%d\n",ret-1);
    exit (0);
}