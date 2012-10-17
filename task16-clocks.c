/*
ID: zltsang1
LANG: C
TASK: clocks
*/
#include <stdio.h>

#define pn 9
typedef struct clocks pnl;
struct clocks{
	int c[pn];
};

#if 1 //ver5.0
int ok(const pnl a){
	int i;
	for(i=0;i<pn;i++){
		if(a.c[i]!=12)return 0;
	}
	return 1;
}

pnl ops(pnl ob,char *a){
	while(*a){
		ob.c[*a-'A']=(ob.c[*a-'A']+3)%12;
		if(!ob.c[*a-'A'])ob.c[*a-'A']=12;
		a++;
	}
	return ob;
}

char opt[9][10]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
pnl opn(pnl ob,int a){
	ob=ops(ob,opt[a]);
	return ob;
}
#endif

#define val(x,i) ((x)>>((i)<<1)&3)

int better(int l,int r){//lack proof of correctness, iff the answer is unique
	return 1;
}

main () {
    FILE *fin  = fopen ("clocks.in", "r");
    FILE *fout = fopen ("clocks.out", "w");
    int i,j,k,best=0x3ffff,sz,a;
	long long seq;
	pnl ap,tp;
	
	for(i=0;i<3;i++){
		fscanf(fin, "%d %d %d\n", ap.c+i*3,ap.c+1+i*3,ap.c+2+i*3);
	}

	for(i=0;i<0x3ffff;i++){
		tp=ap;
		for(j=0;j<9;j++){
			for(k=0;k<val(i,j);k++){
				tp=opn(tp,j);
			}
		}
		if(ok(tp)){
			if(better(i,best))best=i;
		}
	}
	
	sz=0;
	for(j=0;j<9;j++){
		sz+=val(best,j);
	}
	
	a=0;
	for(j=0;j<9;j++){
		for(k=0;k<val(best,j);k++){
			if(a<sz-1){fprintf(fout, "%d ",j+1);a++;}
			else fprintf(fout, "%d\n",j+1);
		}
	}
	
    exit (0);
}