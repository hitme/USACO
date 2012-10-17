/*
ID: zltsang1
LANG: C
TASK: subset
*/
#include <stdio.h>

#define set(x,i) x|=1<<(i)
#define ust(x,i) x&=~(1<<(i))
#define iss(x,i) (x&(1<<(i)))

int dp[50][50][400];
int vst[50];

int pth[50],lp;
long long msk;
int cnt;

int an;
void helper(int lo,int hi,int sm){
	int ret=0;
	int i;
	
	if(sm==0){
		cnt++;
#if 0
		for(i=0;i<lp;i++){
			printf("%d ",pth[i]);
		}
		printf("\n");
#endif
	}
	if(hi<lo)return;
	if(sm<lo)return;
	
	for(i=hi;i>=lo;i--){
		if(!vst[i]){
			vst[i]=1;
			helper(lo,i,sm-i);
			vst[i]=0;
		}
#if 0
		if(!iss(msk,i)){
//			pth[lp++]=i;
			set(msk,i);
			helper(lo,i,sm-i);
			ust(msk,i);
//			lp--;
		}
#endif
	}
	
	return ret;
}

main () {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");
    int ret;
	int i,t;
    fscanf (fin, "%d", &an);
	
	if(an*(an+1)%4){
		fprintf (fout, "0\n");
		exit(0);
	}
	
//	set(msk,1);
	vst[1]=1;
//	pth[lp++]=1;
	helper(2,an,an*(an+1)/4-1);
	
    fprintf (fout, "%d\n",cnt);
    exit (0);
}