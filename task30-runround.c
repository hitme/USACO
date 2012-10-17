/*
ID: zltsang1
LANG: C
TASK: runround
*/
#include <stdio.h>

#define set(x,i) x|=1<<(i)
#define bit(x,i) (x&1<<(i))

int ok(const char* av){
	int l,msk;
	int i,p;
	char* t;
	
	t=av;
	while(*t){
		if(*t=='0')return 0;
		*t-='0';t++;
	}
	l=t-av;
	
	msk=0;
	for(i=0;i<l;i++){
		if(bit(msk,*(av+i)))return 0;
		set(msk,*(av+i));
	}
	
	msk=~((1<<l)-1);
	p=0;
	for(i=0;i<l;i++){
		set(msk,p);
		p=(p+(*(p+av)))%l;
	}
	
	if(!p&&!~msk)return 1;
	return 0;
}

main () {
    FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");
    int am;
	
	int i;
	char ct[10],*t;
	
    fscanf (fin, "%d", &am);
	
	for(i=am+1;i<999999999;i++){
		sprintf(ct,"%d",i);
		if(ok(ct)){
			t=ct;
			while(*t){*t+='0';t++;}
			fprintf(fout,"%s\n",ct);break;
		}
	}
	
    exit (0);
}