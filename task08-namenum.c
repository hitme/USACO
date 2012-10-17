/*
ID: zltsang1
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1000000
#define mlen 12
#define maxw 5000
char nms[maxn][mlen+1]={0};//make this local var, and segfault arise, don't know why.
char dic[maxw][mlen+1]={0};
int nc,cn;

int cmp(const void* l, const void* r){
	return strcmp(l,r);
}

main () {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
	
	FILE *fdic=fopen("dict.txt","r");
	
	char pad[8][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},
					{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
	
    char brd[mlen+1];
	//int nc,cn;
	int sa,sb,i,j,k,t,fg,cd;
	
	fscanf (fin, "%s", brd);
	nc=strlen(brd);
	
	cd=0;
	while(1){
		if(fscanf (fdic, "%s", dic[cd])==EOF)break;
		if(strlen(dic[cd])!=nc)continue;
		cd++;
	}
	
	sa=1,sb=1;
	for(i=0;i<nc;i++){
		sa*=3;
	}
	cn=sa;
	
	for(i=0;i<nc;i++){
		sb*=3;sa/=3;
		for(j=0;j<sb;j++){
			t=j%3;
			for(k=0;k<sa;k++)
				nms[sa*j+k][i]=pad[brd[i]-'2'][t];
		}
	}
	
	fg=0;
	for(i=0;i<cn;i++){//missing ini of var(i) cause great trouble.
		if(bsearch(nms[i],dic,cd,mlen+1,cmp)){
			fg=1;fprintf(fout,"%s\n", nms[i]);
		}
	}
	
	if(!fg)
		fprintf(fout, "NONE\n");
	
    exit (0);
}