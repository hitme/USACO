/*
ID: zltsang1
LANG: C
TASK: inflate
*/
#include <stdio.h>

#define xn 10000
long dp[xn+1];

main () {
    FILE *fin  = fopen ("inflate.in", "r");
    FILE *fout = fopen ("inflate.out", "w");
	//fout=stdout;
	//fin=stdin;
	
	int cmt,cp,ret;
    int i,j,p,t;
	
	fscanf (fin, "%d %d", &cmt,&cp);
	
	for(i=0;i<cp;i++){
		fscanf (fin, "%d %d", &p,&t);
		for(j=0;j<=cmt;j++){
			if(j<t)continue;
			if(dp[j-t]+p>dp[j])
				dp[j]=dp[j-t]+p;
		}
	}
	
	fprintf (fout, "%ld\n",dp[cmt]);
    exit (0);
}