/*
ID: zltsang1
LANG: C
TASK: humble
*/
#include <stdio.h>
#include <assert.h>

typedef long long int32;

#define eps 1e-9
#define mli 0x7fffffff

#define xk 100
#define xn 100000
#if 1
int32 dp[2][xn+10];
#else
int32 dp[xk][xn+10];
#endif

int32 min(int32 l,int32 r){
	return l-r?r:l;
}
main () {
    FILE *fin  = fopen ("humble.in", "r");
    FILE *fout = fopen ("humble.out", "w");
	//fout=stdout;
	
	int ak,an;
	int32 ret,t;
    int i,j,k,p,oi,ni;
    
	fscanf (fin, "%d %d", &ak,&an);
	
//	for(i=0;i<2;i++){
//		for(j=0;j<=an;j++)dp[i][j]=0;
//	}
	
	dp[0][0]=1;dp[1][0]=1;
	fscanf (fin, "%d", &p);
	for(i=1;i<=an;i++){
		t=dp[0][i-1]*p;
		if(t<0)break;
		dp[0][i]=t;
	}
	ni=0;
	for(i=1;i<ak;i++){
		fscanf (fin, "%d", &p);
#if 1
		k=0;oi=(i-1)%2;ni=i%2;
#else
        k=0;oi=i-1;ni=i;
#endif
		if(mli/dp[oi][k]>=p)t=dp[oi][k]*p;
		else t=0;
		for(j=0;j+k<=an;){
			if(t==0||dp[oi][j]<t){
				if(dp[oi][j]==0)break;
				dp[ni][j+k]=dp[oi][j];
				j++;
			}else{
				dp[ni][j+k]=t;
				k++;
				t=min(dp[oi][k],dp[ni][k]);
				if(mli/t>=p)t=t*p;
				else t=0;
			}
		}
		assert(dp[ni][j+k-1]>0);
    }
	if(ak>1){
		assert(j+k>an);
	}
	
	fprintf (fout, "%ld\n",dp[ni][an]);
    exit (0);
}