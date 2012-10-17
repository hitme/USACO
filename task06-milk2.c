/*
ID: zltsang1
LANG: C
TASK: milk2
*/
#include <stdio.h>

#define MAXT 1000000

main () {
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
    
	int itv[MAXT+10]={0};
	int nf,i,a,b,j,l,h;
	int rx,ry,mx,my;
	
	fscanf(fin, "%d", &nf);
	
	l=MAXT,h=0;
	for(i=0;i<nf;i++){
		fscanf (fin, "%d %d", &a, &b);	
		if(a<l)l=a;
		if(b>h)h=b;
		for(j=a;j<b;j++)itv[j]|=1;
    }
	
	rx=ry=mx=my=0;
	for(i=l;i<h;){
		if(itv[i]){
			my=0;
			while(itv[i]){mx++;i++;}//'while(itv[i++])' combine cond with inc, bad habit, wrong ans.
			if(mx>rx)rx=mx;
		}else{
			mx=0;
			while(!itv[i]){my++;i++;}
			if(my>ry)ry=my;
		}
	}
	
    fprintf (fout, "%d %d\n", rx,ry);
    exit (0);
}