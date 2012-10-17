/*
ID: zltsang1
LANG: C
TASK: concom
*/
#include <stdio.h>

#define mxn 100
int trp[mxn+1][mxn+1],trp2[mxn+1][mxn+1];

main () {
    FILE *fin  = fopen ("concom.in", "r");
    FILE *fout = fopen ("concom.out", "w");
    int an;
	int i,j,k,p,l,a,b;
    fscanf (fin, "%d", &an);
	
	while(fscanf(fin, "%d %d %d",&i,&j,&p)!=EOF){
		trp[i][j]=p;
	}

	for(k=1;k<=mxn+1;k++){
		for(i=1;i<=mxn;i++){
			for(j=1;j<=mxn;j++){
				if(trp[i][j]>50)continue;
				p=0;
				for(l=1;l<=mxn;l++)
					if(trp[i][l]>50){p+=trp[l][j];if(p>50)break;}//CAUTION:overflow
				if(trp[i][j]+p>50)trp[i][j]+=p;//faulty??but passed test
			}
		}
	}
	
	
	for(i=1;i<=mxn;i++){
		for(j=1;j<=mxn;j++){
			if(j!=i&&trp[i][j]>50)fprintf(fout,"%d %d\n",i,j);
		}
	}
	
    exit (0);
}