/*
ID: zltsang1
LANG: C
TASK: inflate
*/
#include <stdio.h>

#define xn 10000
int cat[xn][3];

#define eps 1e-9

main () {
    FILE *fin  = fopen ("inflate.in", "r");
    FILE *fout = fopen ("inflate.out", "w");
	//fout=stdout;
	//fin=stdin;
	
	int cmt,cp,ret;
    int i,mi;
	double md,t;
    fscanf (fin, "%d %d", &cmt,&cp);
	
	for(i=0;i<cp;i++){
		fscanf (fin, "%d %d", cat[i],cat[i]+1);
	}

	
#if 1	//tle 85790000
	ret=0;
	while(cmt){
		md=0;
		for(i=0;i<cp;i++){
			if(cmt<cat[i][1])continue;
			t=cmt/cat[i][1]*cat[i][0]/(double)cmt;
			if((md<eps||md<t)){
				md=t;mi=i;
			}
		}
		if(md>eps){
			cmt-=cat[mi][1];
			ret+=cat[mi][0];
		}else break;
	}
#endif	
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}