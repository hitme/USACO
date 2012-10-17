/*
ID: zltsang1
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

#define maxn 5000

typedef struct farmer frm;
struct farmer{
	int pr;
	int am;
};

frm fm[maxn]={0};

int cmp(const void* l, const void* r){
	return ((frm*)l)->pr-((frm*)r)->pr;
}

main () {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
    int an,am,ret;
	int i,p,m;
	
    fscanf (fin, "%d %d", &an, &am);
	
	for(i=0;i<=am;i++){
		fscanf(fin, "%d %d", &(fm+i)->pr, &(fm+i)->am);
	}
	
	qsort(fm,am,sizeof(frm),cmp);
	
	ret=0;
	for(i=0;i<am;i++){
		p=(fm+i)->pr;
		m=(fm+i)->am;
		if(an<=m){
			ret+=p*an;
			break;
		}else{
			an-=m;
			ret+=p*m;
		}
	}
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}