/*
ID: zltsang1
LANG: C
TASK: rect1
*/
#include <stdio.h>
#include <assert.h>

typedef long long int64;
typedef long int32;

#define xn 10000
typedef struct rectangle rect;
struct rectangle{
	int lx, ly, rx, ry, clr;
};
rect ary[xn];
int arc;

#define xc 2500
int ara[xc+1];

int sar(rect rt){
	return (rt.ry-rt.ly)*(rt.rx-rt.lx);
}

int check(int a,int b){
	int i;
	int s=a*b;
	rect rt;
	for(i=0;i<arc;i++){
		rt=ary[i];
		s-=sar(rt);
	}
	if(s)return 1;
	return 0;
}

main () {
    FILE *fin  = fopen ("rect1.in", "r");
    FILE *fout = fopen ("rect1.out", "w");
	//fout=stdout;
	
	int aa,ab,an;
    int i,j,cr;
	rect rt,rti,*rp;
	
    fscanf (fin, "%d %d %d", &aa,&ab,&an);
	
	rt.lx=0;rt.ly=0;rt.rx=aa;rt.ry=ab;rt.clr=1;
	ary[0]=rt;
	arc=1;rp=ary+arc;
	
	for(i=1;i<=an;i++){
		fscanf (fin, "%d %d %d %d %d", &rt.lx,&rt.ly,&rt.rx,&rt.ry,&rt.clr);
		//add rt to ary,split rects.
		for(j=0;j<arc;j++){
			rti=ary[j];
			if(rt.lx>=rti.rx||rt.rx<=rti.lx||rt.ly>=rti.ry||rt.ry<=rti.ly)continue;
			//rp=ary+arc;
			cr=0;
			if(rti.lx<rt.lx){
				rp->lx=rti.lx;
				rp->ly=rti.ly;
				rp->rx=rt.lx;
				rp->ry=rti.ry;
				rp->clr=rti.clr;
				rp++;cr++;
				rti.lx=rt.lx;
			}
			if(rti.rx>rt.rx){
				rp->lx=rt.rx;
				rp->ly=rti.ly;
				rp->rx=rti.rx;
				rp->ry=rti.ry;
				rp->clr=rti.clr;
				rp++;cr++;
				rti.rx=rt.rx;
			}
			if(rti.ly<rt.ly){
				rp->lx=rti.lx;
				rp->ly=rti.ly;
				rp->rx=rti.rx;
				rp->ry=rt.ly;
				rp->clr=rti.clr;
				rp++;cr++;
				rti.ly=rt.ly;
			}
			if(rti.ry>rt.ry){
				rp->lx=rti.lx;
				rp->ly=rt.ry;
				rp->rx=rti.rx;
				rp->ry=rti.ry;
				rp->clr=rti.clr;
				rp++;cr++;
				rti.ry=rt.ry;
			}
			assert(rp-ary<=xn);
			{rp--;ary[j]=rp[0];}//dont waste ary[j]
			if(rp-ary<arc){arc--;j--;}//this is the hard case
		}
		rp[0]=rt;rp++;
		arc=rp-ary;
		assert(check(aa,ab)==0);
	}
	arc=rp-ary;
	
	for(i=0;i<arc;i++){
		rt=ary[i];
		ara[rt.clr]+=sar(rt);
	}
	
	for(i=1;i<xc+1;i++){
		if(ara[i]>0)
			fprintf (fout, "%d %d\n",i,ara[i]);
	}
	
    exit (0);
}