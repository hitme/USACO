/*
ID: zltsang1
LANG: C
TASK: prefix
*/
#include <stdio.h>

#define mxl 200000 

char prm[200][11];
char txt[mxl+10];
char dp[mxl+10];//mem must be cleared to '\0's,if made local.
    
main () {
    FILE *fin  = fopen ("prefix.in", "r");
    FILE *fout = fopen ("prefix.out", "w");
	
	int cp,ret;
	char *p;
	int lt,f;
	int i,l;
	
	cp=0;
    while(1){
		fscanf(fin,"%s",prm[cp]);
		if(prm[cp][0]=='.')break;
		cp++;
	}
	
	p=txt;
	while(fscanf(fin,"%s", p)!=EOF){
		p+=strlen(p);
	}
	
	lt=strlen(txt);
	
	p=txt;
	f=1;
	do{
		ret=p-txt;
		for(i=0;i<cp;i++){
			l=strlen(prm[i]);
			if(dp[ret+l])continue;
			if(!strncmp(prm[i],p,l))dp[ret+l]=1;
		}
		do{
			p++;
			if(p-txt>lt){
				f=0;break;
			}
		}while(!dp[p-txt]);//test dp[lt],so be careful it is not initilized to zero.
	}while(f);
	
    fprintf (fout, "%d\n",ret);
    exit (0);
}