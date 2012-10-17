/*
ID: zltsang1
LANG: C
TASK: castle
*/
#include <stdio.h>

#define mxn 50
FILE *fout;
typedef struct vert vert;
struct vert{
	int x,y;
};

int an,am;
int csl[mxn][mxn]={0};
int cpt[mxn][mxn]={0};

vert vst[mxn*mxn];//queue for bfs
int lvt,hvt;//idx for vst
int cpts;//# of components
int csize[mxn*mxn];//size of components
int msize;

#define xcpt(t) cpt[(t).x][(t).y]
#define xcsl(t) csl[(t).x][(t).y]

void vnbr(vert at){//this is tricky
	int i,j;
	vert t;
	t=at;
	if(!(xcsl(t)&1)&&t.y){
		t.y--;
		if(!xcpt(t)){vst[hvt++]=t;xcpt(t)=-1;}
	}
	t=at;
	if(!(xcsl(t)&2)&&t.x){
		t.x--;
		if(!xcpt(t)){vst[hvt++]=t;xcpt(t)=-1;}
	}
	t=at;
	if(!(xcsl(t)&4)&&t.y<am-1){
		t.y++;
		if(!xcpt(t)){vst[hvt++]=t;xcpt(t)=-1;}
	}
	t=at;
	if(!(xcsl(t)&8)&&t.x<an-1){
		t.x++;
		if(!xcpt(t)){vst[hvt++]=t;xcpt(t)=-1;}
	}	
}

void fldf(){
	int c;
	int i,first,sz;
	first=hvt;
	do{
		c=0;
		for(;lvt<hvt;lvt++){
			c++;
			xcpt(vst[lvt])=cpts;
			vnbr(vst[lvt]);
		}
	}while(c);
	sz=hvt-first+1;
	csize[cpts]=sz;
	if(sz>msize)msize=sz;
}

void cmpnt(){
	int i,j;
	vert t;
	
	lvt=hvt=0;
	cpts=0;
	msize=0;
	for(i=0;i<an;i++){
		for(j=0;j<am;j++){
			if(!cpt[i][j]){
				cpts++;
				vst[hvt].x=i;
				vst[hvt].y=j;
				hvt++;
				fldf();
			}
		}
	}
	fprintf (fout,"%d\n",cpts);
	fprintf (fout,"%d\n",msize);
}

int brkw(){
	int i,j;
	int st,drt,msz;
	vert a,b,t;
	msz=0;
	for(j=0;j<am;j++){
		for(i=an;i;){//for(..;..;--i) does not work
			--i;
			a.x=i;a.y=j;	
			if(i){
				b=a;
				b.x--;
				if(xcpt(a)!=xcpt(b)){
					st=csize[xcpt(a)]+csize[xcpt(b)];
					if(st>msz){msz=st;t=a;drt=2;}
				}
			}
			if(j<am-1){
				b=a;
				b.y++;
				if(xcpt(a)!=xcpt(b)){
					st=csize[xcpt(a)]+csize[xcpt(b)];
					if(st>msz){msz=st;t=a;drt=4;}
				}
			}
		}
	}
	
    fprintf (fout,"%d\n",msz);
	fprintf (fout,"%d %d %c\n",t.x+1,t.y+1,drt==2?'N':'E');
}

main () {
    FILE *fin  = fopen ("castle.in", "r");
    int i,j;
	int rt1;
	
    fout = fopen ("castle.out", "w");
    fscanf (fin, "%d %d", &am,&an);
	
	for(i=0;i<an;i++){
		for(j=0;j<am;j++){
			fscanf(fin, "%d", &csl[i][j]);
		}
	}
	
	cmpnt();
	brkw();
    exit (0);
}