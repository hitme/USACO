/*
ID: zltsang1
LANG: C
TASK: holstein
*/
#include <stdio.h>

#define mnv 25
#define mng 15

int av,ag;
int vit[mnv],fd[mng][mnv];
int tag[1<<mng],bit[mng];

int cmp(const void*l,const void*r){
	int a,b,c,d;
	a=*(int*)l;
	b=*(int*)r;
	c=0;
	while(a){c++;a=a&(a-1);}
	d=0;
	while(b){d++;b=b&(b-1);}
	if(c==d)return a-b;
	return c-d;
}

void sbit(int m){
	int i;
	for(i=0;i<ag;i++){
		bit[i]=m&1<<i;
	}
}

int ok(int mask){
	int i,j,t;
	for(i=0;i<av;i++){
		t=vit[i];
		for(j=0;j<ag;j++){
			if(bit[j])t-=fd[j][i];
		}
		if(t>0)return 0;
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("holstein.in", "r");
    FILE *fout = fopen ("holstein.out", "w");
	int i,j,c;
	
    fscanf (fin, "%d", &av);
	for(i=0;i<av;i++){
		fscanf (fin, "%d", vit+i);
	}
	fscanf (fin, "%d", &ag);
    for(i=0;i<ag;i++){
		for(j=0;j<av;j++)
			fscanf (fin, "%d", fd[i]+j);
	}
	
	for(i=0;i<1<<ag;i++){
		tag[i]=i;
	}
	qsort(tag,1<<ag,sizeof(int),cmp);
	
	for(i=0;i<1<<ag;i++){
		sbit(tag[i]);
		if(ok(tag[i]))break;
	}
	
	c=0;
	for(i=0;i<ag;i++){
		if(bit[i]){
			c++;bit[i]=i+1;
		}
	}
	
	fprintf (fout, "%d ",c);
	for(i=0;i<ag;i++){
		if(bit[i]){
			--c;
			if(!c){
				fprintf (fout, "%d\n",bit[i]);
			}
			else fprintf (fout, "%d ",bit[i]);
		}
	}
    exit (0);
}