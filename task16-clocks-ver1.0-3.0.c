/*
ID: zltsang1
LANG: C
TASK: clocks
*/
#include <stdio.h>

#define pn 9
typedef struct clocks pnl;
struct clocks{
	int c[pn];
};

#if 1 //ver3.0
int ok(const pnl *a){
	int i;
	for(i=0;i<pn;i++){
		if(a->c[i])return 0;
	}
	return 1;
}

void ops(pnl *ob,int *a){
	while(*a){
		ob->c[*a-1]=(ob->c[*a-1]+1)&3;
		a++;
	}
}

int opt[9][10]={
{1,2,4,5},{1,2,3},{2,3,5,6},
{1,4,7},{2,4,5,6,8},{3,6,9},
{4,5,7,8},{7,8,9},{5,6,8,9}};
void opn(pnl *ob,int a){
	ops(ob,opt[a]);
}
#endif

#if 0 //ver 1.0&&2.0
int ok(const pnl a){
	int i;
	for(i=0;i<pn;i++){
		if(a.c[i]!=12)return 0;
	}
	return 1;
}

pnl ops(pnl ob,char *a){
	while(*a){
		ob.c[*a-'A']=(ob.c[*a-'A']+3)%12;
		if(!ob.c[*a-'A'])ob.c[*a-'A']=12;
		a++;
	}
	return ob;
}

char opt[9][10]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
pnl opn(pnl ob,int a){
	ob=ops(ob,opt[a]);
	return ob;
}
#endif

#define mpn 16
#if 1 //ver3.0 3m24.334s for testcase3, remove '%'in ops reduce time to 3m5.348s
int sp[mpn]={-1},lvl=1;
pnl cch[mpn];//ver2.0
long long del[mpn];
int pth(long long a){//gen path for the a-th[1..a] search
	int i,c=0,t[mpn],ret;
	if(a==0){//only once
		del[0]=0;
		for(i=1;i<mpn;i++){//9^9 is the largest exp
			del[i]=del[i-1]*9+9;
		}
	}
	if(a>del[lvl])lvl++;
	a-=del[lvl-1];
	if(lvl==mpn){printf("overflow\n");exit(0);}//debug
	for(i=0;i<lvl;i++){
		t[i]=a%9;a=a/9;
	}
	ret=0;
	while(sp[ret]==t[lvl-1-ret]){
		ret++;
	}
	for(i=ret;i<lvl;i++){
		sp[i]=t[lvl-1-i];
	}
	return ret;
}
void opp(int len){
	int i;
	int t,*p;
	pnl *ob;
	for(i=len;i<lvl;i++){//ver3.0
		cch[i+1]=cch[i];
//		opn(cch+i+1,sp[i]);//reduce fun calls, 3m2.094s
		ob=cch+i+1;
		p=opt[sp[i]];
		t=*p;
		while(t){
			t--;p++;
			ob->c[t]=(ob->c[t]+1)&3;
			t=*p;
		}
	}
}
#endif
#if 0 //ver2.0 faulty with lvl
int sp[mpn]={-1},lvl=1;
pnl cch[mpn];//ver2.0
long long del[mpn];
int pth(long long a){//gen path for the a-th[1..a] search
	int i,c=0,t[mpn],ret;
	if(a==0){//only once
		del[0]=0;
		for(i=1;i<mpn;i++){//9^9 is the largest exp
			del[i]=del[i-1]*9+9;
		}
	}
	if(a>del[lvl])lvl++;
	a-=del[lvl-1];
	if(lvl==mpn){printf("overflow\n");exit(0);}//debug
	for(i=0;i<lvl;i++){
		t[i]=a%9;a=a/9;
	}
	ret=0;
	while(sp[ret]==t[lvl-1-ret]){
		ret++;
	}
	for(i=ret;i<lvl;i++){
		sp[i]=t[lvl-1-i];
	}
	return ret;
}
pnl opp(pnl ob,int len){
	int i;
	for(i=len;i<lvl;i++){//ver2.0
		ob=opn(ob,sp[i]);
		cch[i+1]=ob;
	}
	return ob;
}
#endif
#if 0 //ver1.0
int sp[mpn],lvl;
long long del[mpn];
int pth(long long a){//gen path for the a-th[1..a] search
	int i,c=0,t[mpn];
	if(a==0){//only once
		del[0]=9;
		for(i=1;i<mpn;i++){//9^9 is the largest exp
			del[i]=del[i-1]*9;
		}
	}
	for(c=0;c<mpn;){//interval of a vs level of search
		if(a>=del[c]){
			a-=del[c++];
		}else break;
	}
	if(c==mpn){printf("overflow\n");exit(0);}//debug
	for(i=0;i<=c;i++){
		t[i]=a%9;a=a/9;
	}
	
	for(i=0;i<=c;i++){
		sp[i]=t[c-i];
	}
	
	return c+1;
}
pnl opp(pnl ob,int len){
	int i;
	for(i=0;i<len;i++){//ver1.0
		ob=opn(ob,sp[i]);
	}
	return ob;
}
#endif

main () {
    FILE *fin  = fopen ("clocks.in", "r");
    FILE *fout = fopen ("clocks.out", "w");
    int i,j,l;
	long long seq;
	pnl ap;
	
	for(i=0;i<3;i++){
		fscanf(fin, "%d %d %d\n", ap.c+i*3,ap.c+1+i*3,ap.c+2+i*3);
	}

#if 1 //ver3.0 backtrack
	for(i=0;i<9;i++){
		ap.c[i]=(ap.c[i]/3)&3;
	}
	seq=0;
	cch[0]=ap;
	while(1){
		l=pth(seq++);
		opp(l);
		if(ok(cch+lvl)){
			for(i=0;i<lvl-1;i++)
				fprintf(fout, "%d ", sp[i]+1);
			break;
		}
	}
#endif
	
#if 0 //ver2.0 backtrack
	seq=0;
	cch[0]=ap;
	while(1){
		l=pth(seq++);
		if(ok(opp(cch[l],l))){
			for(i=0;i<lvl-1;i++)
				fprintf(fout, "%d ", sp[i]+1);
			break;
		}
	}
#endif
	
#if 0 //ver1.0 without backtracking
	seq=0;
	while(1){
		l=pth(seq++);
		if(ok(opp(ap,l))){
			for(i=0;i<l-1;i++)
				fprintf(fout, "%d ", sp[i]+1);
			break;
		}
	}
#endif
	
    fprintf (fout, "%d\n", sp[lvl-1]+1);
    exit (0);
}