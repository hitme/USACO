/*
ID: zltsang1
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

#define maxn 200

int cmp(const void* l, const void* r){
	return *(int*)l-*(int*)r;
}

main () {
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");
    int am,as,ac,ret;
	int st,ed,i;
	int stl[maxn],gap[maxn];
	
    fscanf (fin, "%d %d %d", &am,&as,&ac);
	
	for(i=0;i<ac;i++){
		fscanf(fin, "%d", stl+i);
	}
	
	qsort(stl,ac,sizeof(int),cmp);
	
	for(i=0;i<ac-1;i++){
		gap[i]=stl[i+1]-stl[i]-1;
	}
	
	qsort(gap,ac-1,sizeof(int),cmp);
	
	ret=stl[ac-1]-stl[0]+1;
	
	for(i=0;i<am-1&&i<ac-1;i++){
		ret-=gap[ac-2-i];
	}
	
    fprintf (fout, "%d\n", ret);
    exit (0);
}