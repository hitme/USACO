/*
ID: zltsang1
LANG: C
TASK: transform
*/
#include <stdio.h>

int nt;
char pbf[10][10]={0},paf[10][10]={0},pt[10][10]={0},pt2[10][10]={0};

void ref(){
	int i,j;
	char t;
	
	for(i=0;i<nt;i++){
		for(j=0;j<nt/2;j++){
			t=pt[i][j];pt[i][j]=pt[i][nt-j-1];pt[i][nt-j-1]=t;
		}
	}
}

int ide(){
	int i,j;
	for(i=0;i<nt;i++){
		for(j=0;j<nt;j++){
			if(paf[i][j]!=pt[i][j])return 0;
		}
	}
	return 1;
}

void rot90(int t){
	int i,j,k;
	for(k=0;k<t;k++){
		for(i=0;i<nt;i++){
			for(j=0;j<nt;j++){
				pt2[j][nt-1-i]=pt[i][j];
			}
		}
		for(i=0;i<nt;i++){
			for(j=0;j<nt;j++){
				pt[i][j]=pt2[i][j];
			}
		}
	}
}

void cpy(){
	int i,j;
	for(i=0;i<nt;i++){
		for(j=0;j<nt;j++){
			pt[i][j]=pbf[i][j];
		}
	}
}

main () {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
    int a, b;
    int i,j,k;
	char ln[10];
	
	fscanf (fin, "%d", &nt);
	for(i=0;i<nt;i++){
		fscanf(fin, "%s", ln);
		for(j=0;j<nt;j++)pbf[i][j]=ln[j];
	}
	for(i=0;i<nt;i++){
		fscanf(fin, "%s", ln);
		for(j=0;j<nt;j++)pt[i][j]=paf[i][j]=ln[j];
	}
	
	for(k=1;k<4;k++){
		cpy();
		rot90(k);
		if(ide()){
			fprintf (fout, "%d\n", k);exit(0);
		}
	}
	
	cpy();
	ref();
	if(ide()){
		fprintf (fout, "%d\n", 4);exit(0);
	}
	
	for(k=1;k<4;k++){
		cpy();
		ref();
		rot90(k);
		if(ide()){
			fprintf (fout, "%d\n", 5);exit(0);
		}
	}

	cpy();
	if(ide()){
		fprintf (fout, "%d\n", 6);exit(0);
	}
	
    fprintf (fout, "%d\n", 7);
    exit (0);
}