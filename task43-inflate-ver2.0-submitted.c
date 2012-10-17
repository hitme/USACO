/*
ID: zltsang1
LANG: C
TASK: inflate
*/
#include <stdio.h>

#define xn 10000
typedef struct probclass cls;
struct probclass{
	int pt,ct;
};
cls cat[xn];

#define eps 1e-9

int cmp(const void*l,const void*r){
	return ((cls*)l)->ct-((cls*)r)->ct;
}

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
		fscanf (fin, "%d %d", &cat[i].pt,&cat[i].ct);
	}
	
	qsort(cat,cp,sizeof(cls),cmp);//this is crucial,submitted
	
#if 1	//tle 85790000
	ret=0;
	while(cmt){
		md=0;
		for(i=0;i<cp;i++){
			if(cmt<cat[i].ct)break;
			t=cmt/cat[i].ct*cat[i].pt/(double)cmt;
			if((md<eps||md<t)){
				md=t;mi=i;
			}
		}
		if(md>eps){
			cmt-=cat[mi].ct;
			ret+=cat[mi].pt;
		}else break;
	}
#endif	
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}