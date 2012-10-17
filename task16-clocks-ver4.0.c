/*
ID: zltsang1
LANG: C
TASK: clocks
*/
#include <stdio.h>

#if 1 //ver4.0

//DO place marcro arg in parenthese!!!
#define set(x,v,i) x&=~(3<<((i)<<1));x|=((v)&3)<<((i)<<1); //set i-th 2bits to v
#define val(x,i) ((x)>>((i)<<1)&3)
typedef int pnl; //ptr and var passing make a big difference.

#define ok(x) (!(x)) //check is x all 0s, ie 12
#define a2i(x) ((x)^0x40)//char A-Z to idx

char opt[9][10]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
pnl opn(pnl ob,int a){
	char *t;
	t=opt[a];
	while(*t){
		set(ob,val(ob,a2i(*t)),a2i(*t));
		t++;
	}
	return ob;
}
#endif

#define mpn 16
#if 1 //ver3.0 3m24.334s for testcase3, remove '%'in ops reduce time to 3m5.348s
int sp[mpn]={-1},lvl=1;
pnl cch[mpn];//ver2.0
long long del[mpn],ctr;
int pth(long long a){//gen path for the a-th[1..a] search
	int i,c=0,t[mpn],ret;
	if(a>del[lvl])lvl++;
	a-=del[lvl-1];
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
	int i,j;
	char *t;
	pnl ob;
	for(i=len;i<lvl;i++){//ver3.0
		cch[i+1]=cch[i];
		t=opt[sp[i]];
		while(*t){
			j=val(cch[i+1],a2i(*t))+1;
			set(cch[i+1],j,a2i(*t));
			t++;
		}
	}
}
#endif

main () {
    FILE *fin  = fopen ("clocks.in", "r");
    FILE *fout = fopen ("clocks.out", "w");
    int i,j,l;
	long long seq;
	int clk[9];
	pnl ap;
	
	for(i=0;i<3;i++){
		fscanf(fin, "%d %d %d\n", clk+i*3,clk+1+i*3,clk+2+i*3);
	}

#if 1 //ver3.0 backtrack
	del[0]=0;
	for(i=1;i<mpn;i++){//9^9 is the largest exp
		del[i]=del[i-1]*9+9;
	}

	for(i=0;i<9;i++){
		set(ap,(clk[i]/3)&3,i+1);
	}
	seq=0;
	cch[0]=ap;
	while(1){
		l=pth(seq++);
		opp(l);
		if(ok(cch[lvl])){
			for(i=0;i<lvl-1;i++)
				fprintf(fout, "%d ", sp[i]+1);
			break;
		}
	}
#endif
	
    fprintf (fout, "%d\n", sp[lvl-1]+1);
    exit (0);
}