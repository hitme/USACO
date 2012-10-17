/*
ID: zltsang1
LANG: C
TASK: sort3
*/
#include <stdio.h>

#define mxn 1000
int ipt[mxn];

int min(x,y){
	return x<y?x:y;
}

main () {
    FILE *fin  = fopen ("sort3.in", "r");
    FILE *fout = fopen ("sort3.out", "w");
    int an;
	int i,ret,c[4]={0},b[4][4]={0},x,y,z;
	
    fscanf (fin, "%d", &an);
	
	for(i=0;i<an;i++){
		fscanf (fin, "%d", ipt+i);
	}
	
	for(i=0;i<an;i++){
		c[ipt[i]]++;
	}
	
	for(i=0;i<c[1];i++){
		b[1][ipt[i]]++;
	}
	for(i=c[1];i<c[1]+c[2];i++){
		b[2][ipt[i]]++;
	}
	for(i=c[1]+c[2];i<c[1]+c[2]+c[3];i++){
		b[3][ipt[i]]++;
	}
	
	ret=0;
	ret+=min(b[1][2],b[2][1]);
	ret+=min(b[1][3],b[3][1]);
	ret+=min(b[2][3],b[3][2]);
	x=b[1][2]-b[2][1];
	y=b[1][3]-b[3][1];
	z=b[2][3]-b[3][2];
	
	if(x*y*z){//loop exist, deal with this by shifting around.
		ret+=-min(-x,x)*2;
	}
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}