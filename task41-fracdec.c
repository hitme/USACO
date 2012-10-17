/*
ID: zltsang1
LANG: C
TASK: fracdec
*/
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define mxn 100000
char ret[mxn];

int ql[mxn+10];

FILE *fin,*fout;
void out(){
	char buf[80];
	char *p;
	p=ret;
	buf[76]='\0';
	//assert(strlen(p)<mxn,"str too long");
	while(1){
		strncpy(buf,p,76);
		if(strlen(p)<76){
			buf[strlen(p)]='\0';
			fprintf(fout,"%s\n",buf);
			break;
		}
		fprintf(fout,"%s\n",buf);
		p+=76;
	};
}

int min(int l,int r){
	return l<r?l:r;
}

main () {
	
	int an,ad;
	int rm;
	char *p;
    int i,j,k,c;
	int hl,sz,lp,pl;
	
	//clock_t st,ed,*pt;
    
	fin  = fopen ("fracdec.in", "r");
	fout = fopen ("fracdec.out", "w");
	//fout = stdout;
	
    fscanf (fin, "%d %d", &an,&ad);
	//scanf ("%d %d", &an,&ad);
	
	sprintf(ret,"%d",an/ad);
	hl=strlen(ret);
	lp=pl=0;//big trouble without init
	if(an%ad==0){
		strcpy(ret+hl,".0");
	}else{
		ret[hl]='.';
		p=ret+hl+1;
		for(i=0;i<mxn-hl-10;i++){
			rm=an%ad;
			if(!ql[rm])ql[rm]=i+1;
			else{
				lp=ql[rm]-1;
				pl=i-lp;
				*p='\0';
				break;
			}
			rm*=10;
			*p++=rm/ad+'0';
			an=rm%ad;
			if(an==0){
				*p='\0';break;
			}
		}
	}
	
	if(pl){
		*p='\0';
		p=ret+hl+1;
		i=lp;k=pl;
#if 0 //tle
	if(i==mxn-hl-10){
		*p='\0';
		p=ret+hl+1;
		sz=mxn-hl-10;
		for(k=1;k<ad&&k<sz/2;k++){
			for(i=0;i<k;i++){
				j=i+k;
				while(j<sz-k){
					if(strncmp(p+i,p+j,k)!=0)break;
					j+=k;
				}
				if(j>=sz-k)break;
			}
			if(i<k)break;
		}
#endif
		printf("%d %d\n",i,k);
		p[i+k+1]=')';
		p[i+k+2]='\0';
		for(j=i+k;j>i;j--){
			p[j]=p[j-1];
		}
		p[i]='(';
    }
	
	out();
    exit (0);
}