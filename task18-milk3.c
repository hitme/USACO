/*
ID: zltsang1
LANG: C
TASK: milk3
*/
#include <stdio.h>

typedef struct states stt;
struct states{
	int b[3];
};

int C[3];

stt pour(const stt *ob,int a,int b){
	stt t;
	t=*ob;
	if(t.b[a]+t.b[b]<=C[b]){
		t.b[b]+=t.b[a];t.b[a]=0;
	}else{
		t.b[a]=t.b[a]+t.b[b]-C[b];
		t.b[b]=C[b];
	}
	return t;
}

int vst[21][21][21]={0};

int isvst(const stt *ob){
	return vst[ob->b[0]][ob->b[1]][ob->b[2]];
}

stt que[21*21*21+10];

main () {
    FILE *fin  = fopen ("milk3.in", "r");
    FILE *fout = fopen ("milk3.out", "w");
    int i,j,cst;
	stt cur={0},t;
	int typ[6][2]={{0,1},{0,2},{1,2},{2,0},{2,1},{1,0}};
	int msk[21]={0},mx;
	
    fscanf (fin, "%d %d %d", C,C+1,C+2);
	
	cur.b[2]=C[2];
	que[0]=cur;
	cst=0;
	
	i=0;
	do{
		cur=que[i];
		vst[cur.b[0]][cur.b[1]][cur.b[2]]=1;
		if(!cur.b[0])
			msk[cur.b[2]]=1;
		for(j=0;j<6;j++){
			if(cur.b[typ[j][0]]){
				t=pour(&cur,typ[j][0],typ[j][1]);
				if(!isvst(&t)){
					que[++cst]=t;//++x x++ differ here,++cst makes cst point to valid var
				}
			}
		}
	}while(i++<cst);
	
	mx=0;
	for(i=0;i<=C[2];i++){
		if(msk[i])mx=i;
	}
	
	for(i=0;i<=C[2];i++){
		if(msk[i]&&i<mx)
			fprintf(fout, "%d ",i);
	}	
	
    fprintf (fout, "%d\n",mx);
    exit (0);
}