/*
ID: zltsang1
LANG: C
TASK: subset
*/
#include <stdio.h>

#define set(x,i) x|=1<<(i)
#define ust(x,i) x&=~(1<<(i))
#define iss(x,i) (x&(1<<(i)))

int dp[50][50][400];
int vst[50];


main () {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");
    int an,ss,ret;
	int i,j,k,t;
    fscanf (fin, "%d", &an);
	
	if(an*(an+1)%4){
		fprintf (fout, "0\n");
		exit(0);
	}

	for(j=1;j<=an;j++){
		dp[j][j][j]=1;
	}
	ss=an*(an+1)/4;
	for(i=1;i<an;i++){
		for(j=1;j<=an-i;j++){
			for(k=1;k<=ss;k++){
				if(dp[j][j+i-1][k]){
					dp[j][j+i][k+j+i]+=dp[j][j+i-1][k];
					dp[j][j+i][k]+=dp[j][j+i-1][k];
				}
			}
		}
	}
	
    fprintf (fout, "%d\n",dp[1][an][ss]);
    exit (0);
}