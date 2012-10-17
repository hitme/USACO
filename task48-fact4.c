/*
ID: zltsang1
LANG: C
TASK: fact4
*/
#include <stdio.h>

typedef long long int64;
typedef long int32;

#define xn 1500
char ftl[xn+2];

main () {
    FILE *fin  = fopen ("fact4.in", "r");
    FILE *fout = fopen ("fact4.out", "w");
	//fout=stdout;
	//fin=stdin;
	
	int an,ret;
    int i,j,c2,c5;
    fscanf (fin, "%d", &an);
	
	c2=c5=0;
	ret=1;
	for(j=2;j<=an;j++){
		i=j;
		while(i%2==0){
			i/=2;c2++;
		}
		while(i%5==0){
			i/=5;c5++;
		}
		ret*=i;
		ret%=10;
	}
	
	while(c2>c5){
		ret*=2;
		ret%=10;
		c2--;
	}
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}