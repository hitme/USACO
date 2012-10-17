/*
ID: zltsang1
LANG: C
TASK: palsquare
*/
#include <stdio.h>

typedef struct bsn bsn;
struct bsn{
	int ln;
	char rep[10];
};

#define maxn 300

//char ch[21]={'0','1','2','3','4','5','6','7','8','9',
//			 'A','B','C','D','E','F','G','H','I','J','K'};
char *ch="012345678ABCDEFGHIJK";//the concise way.

bsn ton(int v,int n){
	bsn t;
	int i,j;
	char ct[10];
	i=0;
	while(v){
		ct[i++]=ch[v%n];
		v/=n;
	}
	for(j=0;j<i;j++){
		t.rep[j]=ct[i-1-j];
	}
	t.rep[i]=0;
	t.ln=i;
	return t;
}
			 
int isp(const bsn *ob){
	int i;
	for(i=0;i<ob->ln/2;i++){
		if((ob->rep)[i]!=(ob->rep)[ob->ln-i-1])
			return 0;
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
    int bas;
    fscanf (fin, "%d", &bas);
	
	int i,j;
	bsn an,a2;
	
	for(i=1;i<=maxn;i++){
		an=ton(i,bas);
		a2=ton(i*i,bas);
		if(isp(&a2))
			fprintf (fout, "%s %s\n", an.rep, a2.rep);
    }
	
    exit (0);
}