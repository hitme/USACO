/*
ID: zltsang1
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <assert.h>

#define maxm 250
char bsq[2*maxm*maxm+10]={0};
int idx[22000]={0},cid,crs;
typedef struct couple cpl;
struct couple{
	int a,s;
};

cpl res[10000];

int cmp(const void*l,const void*r){
	if(((cpl*)l)->s==((cpl*)r)->s)return ((cpl*)l)->a-((cpl*)r)->a;
	return ((cpl*)l)->s-((cpl*)r)->s;
}

main () {
    FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");
    int an,am,mb;
    int i,j,a,b,c,s,tn;
	long long t;
	
	fscanf (fin, "%d %d", &an,&am);
	
	for(i=0;i<am+1;i++){
		for(j=0;j<am+1;j++){
			bsq[i*i+j*j]=1;
		}
	}
	
	cid=0;
	mb=2*am*am;
	for(i=0;i<mb+1;i++){
		if(bsq[i])idx[cid++]=i;
	}
	
	
	crs=0;
	for(i=0;i<cid;i++){
		a=idx[i];
		for(j=i+1;j<cid;j++){
			b=idx[j];
			c=2*b-a;
			if(c<=mb&&bsq[c]){//check this index 'c'
				s=b-a;
				if(((mb-a)/s)<an-1)continue; //DO check this
				t=a+s*(an-1);
				tn=an-2;
				while(tn){
					if(bsq[t]){t-=s;tn--;}
					else break;
				}
				if(!tn){
					res[crs].a=a;
					res[crs++].s=b-a;
				}
			}
		}
	}
	
	if(!crs){
		fprintf (fout, "NONE\n");
		exit (0);
	}
	
	qsort(res,crs,sizeof(cpl),cmp);
	
	for(i=0;i<crs;i++){
		fprintf (fout, "%d %d\n",res[i].a,res[i].s);
	}
    
    exit (0);
}