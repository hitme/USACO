/*
ID: zltsang1
LANG: C
TASK: cowtour
*/
#include <stdio.h>
#include <math.h>

typedef struct pasture pst;
struct pasture{
	int x,y;
};
#define mxn 150
#define eps 1e-9
pst pa[mxn];
double adj[mxn][mxn];
int field[mxn];
double sp[mxn],fdm[mxn];

double max(double l,double r){
	return l>r?l:r;
}

main () {
    FILE *fin  = fopen ("cowtour.in", "r");
    FILE *fout = fopen ("cowtour.out", "w");
	
	int an;
	double ret,td;
    int i,j,k,f;
	char buf[mxn+10];
	pst tp;
	
    fscanf (fin, "%d", &an);
	for(i=0;i<an;i++){
		fscanf (fin, "%d %d", &tp.x,&tp.y);
		pa[i]=tp;
	}
	
	ret=0;
	for(i=0;i<an;i++){
		fscanf (fin, "%s", buf);
		for(j=0;j<an;j++){
			if(buf[j]=='1')
				adj[i][j]=sqrt((pa[i].x-pa[j].x)*(pa[i].x-pa[j].x)+(pa[i].y-pa[j].y)*(pa[i].y-pa[j].y));
		}
	}
	
	//all pairs short path
	for(k=0;k<an;k++){
		for(i=0;i<an;i++){
			for(j=0;j<an;j++){
				if(i!=j&&adj[i][k]>eps&&adj[j][k]>eps&&(adj[i][j]<eps||adj[i][k]+adj[j][k]<adj[i][j]))
					adj[i][j]=adj[i][k]+adj[j][k];
			}
		}
	}
	
	//each point's farthest 'pasture' reachable
	for(i=0;i<an;i++){
		sp[i]=0;
		for(j=0;j<an;j++){
			if(i!=j&&adj[i][j]>eps&&(sp[i]<eps||adj[i][j]>sp[i]))sp[i]=adj[i][j];
		}
	}
	
	//label fields
	k=1;
	for(i=0;i<an;i++){
		if(!field[i]){
			field[i]=k;
			fdm[k]=sp[i];
			for(j=0;j<an;j++)
				if(adj[i][j]){
					field[j]=k;
					if(fdm[k]<sp[j])fdm[k]=sp[j];
				}
			k++;
		}
	}
	
	//try if connecting i and j(in different field) leads to shorter diameter
	ret=0;
	for(i=0;i<an;i++){
		for(j=0;j<an;j++){
			if(i!=j&&adj[i][j]<eps){
				td=sqrt((pa[i].x-pa[j].x)*(pa[i].x-pa[j].x)+(pa[i].y-pa[j].y)*(pa[i].y-pa[j].y));
				td=max(td+sp[i]+sp[j],max(fdm[field[i]],fdm[field[j]]));
				if(ret<eps||ret>td)
					ret=td;
			}
		}
	}
	
    fprintf (fout, "%.6f\n",ret);
    exit (0);
}