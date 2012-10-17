/*
ID: zltsang1
LANG: C
TASK: gift1
*/
#include <stdio.h>

int np;
char gp[10][15];
int ini[10];
int lef[10];
int gm[10][10];

int n2i(const char *s){
	int i;
	for(i=0;i<np;i++){
		if(!strcmp(gp[i],s))return i;
	}
	return -1;
}

main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    
	int i,t,c,a,b,j;
	char na[15];
	
	fscanf (fin, "%d", &np);
	for(i=0;i<np;i++){
		fscanf(fin, "%s", gp[i]);
	}
	
	for(i=0;i<np;i++){
		fscanf(fin, "%s", na);
		t=n2i(na);
		fscanf(fin, "%d %d", ini+t, &c);
		if(!c){
			lef[t]=ini[t];
			continue;
		}
		a=ini[t]/c;
		lef[t]=ini[t]%c;
		for(j=0;j<c;j++){
			fscanf(fin, "%s", na);
			b=n2i(na);
			gm[t][b]=a;
		}
	}
	
	for(i=0;i<np;i++){
		for(j=0;j<np;j++)
			lef[i]+=gm[j][i];
	}
	
	for(i=0;i<np;i++){
		fprintf (fout, "%s %d\n", gp[i], lef[i]-ini[i]);
	}
    exit (0);
}