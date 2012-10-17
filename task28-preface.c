/*
ID: zltsang1
LANG: C
TASK: preface
*/
#include <stdio.h>

int rac[10][3]={{},{1,},{3,},{6,},{7,1,},{7,2,},{8,3,},{10,4,},{13,5,},{14,5,1}};
int rdc[10][3]={{},{1,},{2,},{3,},{1,1,},{0,1,},{1,1,},{2,1,},{3,1,},{1,0,1}};

int cnt[7];
char ra[8]="IVXLCDM";

typedef struct digit dgt;
struct digit{
	int v,p,wgt,tail;
};

int idx;
dgt dts[5];

void cal(int v){
	int i,j,hi,lo,f,t;
	dgt dt;
	
	f=1;lo=0;idx=0;
	for(i=0;v;i++){
		t=v%10;
		if(t){
			dt.v=t;
			dt.p=i;
			dt.wgt=f;
			dt.tail=lo;
			dts[idx++]=dt;
		}
		lo+=t*f;
		f*=10;
		v/=10;
	}
	
	for(i=0;i<idx;i++){
		cnt[ dts[i].p<<1   ]+=rac[dts[i].v-1][0]*dts[i].wgt;
		cnt[(dts[i].p<<1)+1]+=rac[dts[i].v-1][1]*dts[i].wgt;
		cnt[(dts[i].p<<1)+2]+=rac[dts[i].v-1][2]*dts[i].wgt;
		cnt[ dts[i].p<<1   ]+=rdc[dts[i].v][0]*(dts[i].tail+1);
		cnt[(dts[i].p<<1)+1]+=rdc[dts[i].v][1]*(dts[i].tail+1);
		cnt[(dts[i].p<<1)+2]+=rdc[dts[i].v][2]*(dts[i].tail+1);
		for(j=0;j<dts[i].p;j++){
			cnt[ j<<1   ]+=dts[i].v*rac[9][0]*dts[i].wgt/10;
			cnt[(j<<1)+1]+=dts[i].v*rac[9][1]*dts[i].wgt/10;
			cnt[(j<<1)+2]+=dts[i].v*rac[9][2]*dts[i].wgt/10;
		}
	}
}

main () {
    FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");
    int an;
	int i;
    fscanf (fin, "%d", &an);
	
	cal(an);
		
	for(i=0;i<7;i++){
		if(cnt[i]){
			fprintf (fout, "%c %d\n",ra[i],cnt[i]);
		}
	}
	
    exit (0);
}