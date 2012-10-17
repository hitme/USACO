/*
ID: zltsang1
LANG: C
TASK: comehome
*/
#include <stdio.h>

#define xn 26
int adj[xn*2+2][xn*2+2];

int c2n(char v){
	if(v>='a'&&v<='z')return v-'a';
	if(v>='A'&&v<='Z')return v-'A'+xn;
}

main () {
    FILE *fin  = fopen ("comehome.in", "r");
    FILE *fout = fopen ("comehome.out", "w");
	
	int an,ret;
    int i,j,k,t;
	char a,b;
	
    fscanf (fin, "%d\n", &an);
	
	for(i=0;i<an;i++){
		fscanf (fin, "%c %c %d\n", &a,&b,&t);
		if(!adj[c2n(a)][c2n(b)]||adj[c2n(a)][c2n(b)]>t){
			adj[c2n(a)][c2n(b)]=t;
			adj[c2n(b)][c2n(a)]=t;
		}
	}
	
	for(k=0;k<xn*2-1;k++){
		for(i=0;i<xn*2;i++){
			for(j=0;j<xn*2;j++){
				if(i!=j&&adj[i][k]&&adj[j][k]&&(!adj[i][j]||adj[i][j]>adj[i][k]+adj[j][k]))
					adj[i][j]=adj[i][k]+adj[j][k];
			}
		}
	}
	
	t=0;ret=xn-1;
	for(i=xn;i<xn*2-1;i++){
		if(adj[i][xn*2-1]&&(!t||t>adj[i][xn*2-1])){
			ret=i-xn;
			t=adj[i][xn*2-1];
		}
	}
	
    fprintf (fout, "%c %d\n",(char)(ret+'A'),t);
    exit (0);
}