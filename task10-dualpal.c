/*
ID: zltsang1
LANG: C
TASK: dualpal
*/
#include <stdio.h>

int ispal(char *s){
	int i,t;
	t=strlen(s);
	for(i=0;i<(t>>1);i++){
		if(s[i]!=s[t-i-1])return 0;
	}
	return 1;
}

void rnb(char *s,int n,int b){//123base10 rep as "321"
	while(n){
		*s++="0123456789"[n%b];
		n/=b;
	}
	*s=0;
}

main () {
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");
    int an, as;
	int i,j,t,ok;
	char s[33];
	
    fscanf (fin, "%d %d", &an, &as);
    
	t=0;
	for(i=as+1;;i++){
		ok=0;
		for(j=2;j<=10;j++){
			rnb(s,i,j);
			if(ispal(s)){
				if(++ok>1)break;
			}
		}
		if(ok>1){
			if(++t>an)break;
			fprintf (fout, "%d\n", i);
		}
	}

    exit (0);
}