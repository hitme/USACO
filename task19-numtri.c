/*
ID: zltsang1
LANG: C
TASK: numtri
*/
#include <stdio.h>

#define mxn 1000
int tri[mxn+1][mxn+1]={0};
#define arg(i,j) tri[(i)+1][(j)]
#define dp(i,j) tri[(j)][(i)+1]

int max(const int a,const int b){
	if(a>b)return a;
	return b;
}

main () {
    FILE *fin  = fopen ("numtri.in", "r");
    FILE *fout = fopen ("numtri.out", "w");
    int an;
    int i,j,tmx;
	
	fscanf (fin, "%d", &an);
	
	for(i=0;i<an;i++){
		for(j=0;j<=i;j++){
			fscanf(fin,"%d",&arg(i,j));
		}
	}
#if 0
	for(i=0;i<an;i++){
		for(j=0;j<=i;j++){
			printf("%d ",arg(i,j));
		}
		printf("\n");
	}
#endif
	dp(0,0)=arg(0,0);
	for(i=1;i<an;i++){
		dp(i,0)=dp(i-1,0)+arg(i,0);
		dp(i,i)=dp(i-1,i-1)+arg(i,i);
	}
	for(i=1;i<an;i++){
		for(j=1;j<i;j++){
			dp(i,j)=max(dp(i-1,j-1),dp(i-1,j))+arg(i,j);
		}
	}
	
#if 0
	for(i=0;i<an;i++){
		for(j=0;j<=i;j++){
			printf("%d ",arg(i,j));
		}
		printf("\n");
	}
#endif

#if 0
	for(i=0;i<an;i++){
		for(j=0;j<=i;j++){
			printf("%d ",dp(i,j));
		}
		printf("\n");
	}
#endif
	
	tmx=0;
	for(i=0;i<an;i++){
		if(dp(an-1,i)>tmx)
			tmx=dp(an-1,i);
	}
	
    fprintf (fout, "%d\n",tmx);
    exit (0);
}