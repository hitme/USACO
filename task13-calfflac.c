/*
ID: zltsang1
LANG: C
TASK: calfflac
*/
#include <stdio.h>

#define maxn 20000

char txt[maxn];

/*//ver2.0
char dp[maxn][maxn];
*/
char sch[maxn];
int spo[maxn];

int isp(const char* l, const char* r){//ver1.0
	int i,len;
	len=r-l;
	for(i=0;i<len;i++){
		if(l[i]!=r[-i-1])return 0;
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("calfflac.in", "r");
    FILE *fout = fopen ("calfflac.out", "w");
    
	char *ln,ct;
	int l,tl,cl,cc;
	int i,j;
	int t,ml,a,b,lw,hg;
	
	//pass input to txt[];filter chars into sch while its pos into spo
	ln=txt;tl=0;cl=0;
	while(fgets(ln,81,fin)){
		l=strlen(ln);
		ln+=l;
		tl+=l;
	}
	
	j=0;
	for(i=0;i<tl;i++){
		ct=txt[i];
		if(isalpha(ct)){
			sch[j]=ct|0x20;
			spo[j++]=i;
		}
	}
	cc=j;//total alpha char count
	
	//check sch for the longest pal(length measured by # chars), mem the max one
	
	//ver3.0, the pal:sch[lw,hg)
	lw=hg=0;t=0;
	for(i=0;i<cc;i++){
		for(j=0;j<=i&&j<=cc-i-1;){//err when j dual inc
			while(sch[i-j]==sch[i+j])j++;
			if(2*j-1>t){
				t=2*j-1;lw=i-j+1;hg=i+j;
			}
			break;
		}
	}

	for(i=0;i<cc-1;i++){
		for(j=0;j<=i&&j<=cc-i-2;){
			while(sch[i-j]==sch[i+j+1])j++;
			if(2*j>t){
				t=2*j;lw=i-j+1;hg=i+j+1;
			}
			break;
		}
	}
	
	
	/*//ver2.0 dp over brute-force,used too much resource(ie,memory)
	lw=hg=0;t=0;
	for(i=0;i<cc;i++){
		dp[i][i]=1;
		t=1;hg=1;
	}
	
	for(i=0;i<cc-1;i++){
		dp[i][i+1]|=sch[i]==sch[i+1];
		if(2>hg-lw&&dp[i][i+1]){
			lw=i;hg=lw+2;
		}
	}
	
	for(i=2;i<cc;i++){
		for(j=0;j<cc-i;j++){
			dp[j][j+i]=(dp[j+1][j+i-1]&&(sch[j]==sch[j+i]));
			if(hg-lw<i+1&&dp[j][j+i]){
				lw=j;hg=lw+i+1;
			}
		}
	}
	*/
	
	/*//ver1.0 exceeds time limit
	lw=0;hg=cc;ml=0;
	for(i=0;i<cc;i++){//check if chars in [i,j) make pal;i==j trival, output the first char
		for(j=cc;j>i;j--){
			t=j-i;
			if(t>ml)
				if(isp(sch+i,sch+j)){
					hg=j;lw=i;ml=t;break;
				}
		}
	}
	*/
	
	fprintf (fout, "%d\n", hg-lw);
    //output [spo[lw],spo[hg-1]] from txt to file
	
	i=spo[lw];
	while(i<=spo[hg-1]){
		fputc(txt[i++],fout);
	}
	fflush(fout);
	
    fprintf (fout, "\n");
    exit (0);
}