/*
ID: zltsang1
LANG: C
TASK: checker
*/
#include <stdio.h>

#define mxn 13
int ln1[mxn]={0};
int ln2[mxn]={0};
int ln3[mxn*2]={0};
int ln4[mxn*2]={0};

#define g1(i,j) (i)
#define g2(i,j) (j)
#define g3(i,j) ((i)-(j))+mxn
#define g4(i,j) ((i)+(j))

int put(int x,int y){
	if(ln1[g1(x,y)])return 0;
	if(ln2[g2(x,y)])return 0;
	if(ln3[g3(x,y)])return 0;
	if(ln4[g4(x,y)])return 0;
	ln1[g1(x,y)]=1;
	ln2[g2(x,y)]=1;
	ln3[g3(x,y)]=1;
	ln4[g4(x,y)]=1;
	return 1;
}

void undo(int x,int y){
	ln1[g1(x,y)]=0;
	ln2[g2(x,y)]=0;
	ln3[g3(x,y)]=0;
	ln4[g4(x,y)]=0;
}

int pth[mxn],top,an,c=0;
FILE *fout;

int helper(int x,int y,int d){
	int i;
	if(!d){
		c++;
		if(c<4){
			for(i=0;i<an-1;i++){
				fprintf(fout,"%d ",pth[i]+1);
			}
			fprintf(fout,"%d\n",x+1);
		}
	}else{
		for(i=0;i<an;i++){
			if(put(i,top)){
				put(i,top);
				pth[top]=i;
				top++;
				helper(i,top,d-1);
				top--;
				undo(i,top);
			}
		}
	}
	
}

main () {
    FILE *fin  = fopen ("checker.in", "r");
    int i;
	
    fout = fopen ("checker.out", "w");
    fscanf (fin, "%d", &an);
	
	top=0;
	for(i=0;i<an;i++){
		put(i,top);
		pth[top]=i;
		top++;
		helper(i,top,an-1);
		top--;
		undo(i,top);
	}
	
	fprintf(fout,"%d\n",c);
	
    exit (0);
}