/*
ID: zltsang1
LANG: C
TASK: agrinet
*/
#include <stdio.h>

#define xn 100
int adj[xn][xn];
int tab[xn][4];

main () {
    FILE *fin  = fopen ("agrinet.in", "r");
    FILE *fout = fopen ("agrinet.out", "w");
	
	int an,ret;
    int i,j,k,md,pn;
	
    fscanf (fin, "%d", &an);
	for(i=0;i<an;i++){
		for(j=0;j<an;j++){
			fscanf (fin, "%d", adj[i]+j);
		}
	}
    
	ret=0;//auto init is missing on the grader
	tab[0][0]=1;tab[0][1]=1;pn=0;
	for(k=0;k<an-1;k++){
		for(i=0;i<an;i++){
			if(i!=pn&&adj[pn][i]&&(!tab[i][0]||tab[i][0]>adj[pn][i]+1))
				tab[i][0]=adj[pn][i]+1;
		}
		md=0;
		for(i=0;i<an;i++){
			if(!tab[i][1]&&tab[i][0]){
				if(!md||md>tab[i][0]){md=tab[i][0];pn=i;}
			}
		}
		if(md){
			tab[pn][1]=1;
			ret+=md-1;
		}else break;
	}
	
	fprintf (fout, "%d\n",ret);
    exit (0);
}