/*
ID: zltsang1
LANG: C
TASK: packrec
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct rectangle rect;
struct rectangle{
	int w,h;
};
rect frec[4]={0};
rect bxs[200]={0};
int sz=0;
int min=0;

int pm[24][4]={
{0,1,2,3},{0,2,3,1},{0,3,1,2},
{0,1,3,2},{0,3,2,1},{0,2,1,3},
{1,0,2,3},{2,0,3,1},{3,0,1,2},
{1,0,3,2},{3,0,2,1},{2,0,1,3},
{2,1,0,3},{3,2,0,1},{1,3,0,2},
{3,1,0,2},{2,3,0,1},{1,2,0,3},
{3,1,2,0},{1,2,3,0},{2,3,1,0},
{2,1,3,0},{1,3,2,0},{3,2,1,0}
};

int max(int a, int b){
	return (a>b)?a:b;
}

void swap(int *a,int* b){
	*a^=*b;*b^=*a;*a^=*b;
}

int cmp(const void *l,const void *r){
	return ((rect*)l)->w-((rect*)r)->w;
}

rect rot(const rect x){
	rect t;
	t.w=x.h;t.h=x.w;
	return t;
}

rect vrt(const rect x){
	if(x.h<x.w)return rot(x);
	return x;
}

rect hor(const rect x){
	if(x.w<x.h)return rot(x);
	return x;
}

rect cnnt(const rect a,const rect b,int cond,int olp){//the box a,b packed in
	rect t;
	if(cond){//ab side-by-side
		t.h=max(a.h,b.h);
		t.w=a.w+b.w-olp;
	}else{//a above b
		t.h=a.h+b.h-olp;
		t.w=max(a.w,b.w);
	}
	return t;
}

void sto(rect nr){
	int i;
	nr=vrt(nr);
	if(min){
		if(min>nr.w*nr.h){min=nr.w*nr.h;sz=1;bxs[0]=nr;return;}
		if(min==nr.w*nr.h){
			for(i=0;i<sz;i++)
				if(bxs[i].w==nr.w)return;
			bxs[sz++]=nr;
		}
	}else{
		min=nr.w*nr.h;
		sz=1;bxs[0]=nr;
	}
}

void pose(int a){
	int i;
	for(i=0;i<4;i++){
		if(a&(1<<i))
			frec[i]=vrt(frec[i]);
		else
			frec[i]=hor(frec[i]);
	}
}

main () {
    FILE *fin  = fopen ("packrec.in", "r");
    FILE *fout = fopen ("packrec.out", "w");
    int rw,rh,era,ret,m[4]={0};
	int i,j,k;
	rect rt,rt2,a,b,c,d;
	
	for(i=0;i<4;i++){
		fscanf (fin, "%d %d", &(frec[i].w),&(frec[i].h));
		frec[i]=vrt(frec[i]);
	}

	for(i=0;i<16;i++){//A
		pose(i);
		rt.w=rt.h=0;
		for(k=0;k<4;k++){
			rt=cnnt(rt,frec[k],1,0);
		}
		sto(rt);
	}
	
	for(i=0;i<16;i++){//B
		pose(i);
		for(j=0;j<24;j++){
			rt.w=rt.h=0;
			rt=cnnt(rt,frec[pm[j][0]],1,0);
			rt=cnnt(rt,frec[pm[j][1]],1,0);
			rt=cnnt(rt,frec[pm[j][2]],1,0);
			rt=cnnt(rt,frec[pm[j][3]],0,0);
			sto(rt);
		}
	}
	
	for(i=0;i<16;i++){//C
		pose(i);
		for(j=0;j<24;j++){
			rt.w=rt.h=0;
			rt=cnnt(rt,frec[pm[j][0]],1,0);
			rt=cnnt(rt,frec[pm[j][1]],1,0);
			rt=cnnt(rt,frec[pm[j][2]],0,0);
			rt=cnnt(rt,frec[pm[j][3]],1,0);
			sto(rt);
		}
	}
	
	for(i=0;i<16;i++){//D,E
		pose(i);
		for(j=0;j<24;j++){
			rt.w=rt.h=0;
			rt=cnnt(rt,frec[pm[j][0]],1,0);
			rt=cnnt(rt,frec[pm[j][1]],0,0);
			rt=cnnt(rt,frec[pm[j][2]],1,0);
			rt=cnnt(rt,frec[pm[j][3]],1,0);
			sto(rt);
		}
	}
	
	for(i=0;i<16;i++){//F
		pose(i);
		for(j=0;j<24;j++){
			rt.w=rt.h=rt2.w=rt2.h=0;
			rt=cnnt(rt,a=frec[pm[j][0]],1,0);
			rt=cnnt(rt,b=frec[pm[j][1]],0,0);
			rt2=cnnt(rt2,c=frec[pm[j][2]],1,0);
			rt2=cnnt(rt2,d=frec[pm[j][3]],0,0);
			rt=cnnt(rt,rt2,1,0);
			if(b.h<d.h&&c.w>d.w&&a.w<b.w)
				rt.w=max(b.w+d.w,a.w+c.w);
			sto(rt);
		}
	}
	
	/*//ver0.1
	rw=0;rh=0;ret=0;
	for(i=0;i<4;i++){
		fscanf (fin, "%d %d", &(frec[i].w),&(frec[i].h));
		frec[i]=vrt(frec[i]);
		if (frec[i].w>frec[i].h){
			swap(&(frec[i].w),&(frec[i].h));
		}
		rw+=frec[i].h;
	}
	rh=rw;
	era=rw*rh;
	*/
	
	//type A
	/*//ver0.2
	rt.w=rt.h=0;
	for(i=0;i<4;i++){
		rt=cnnt(rt,frec[i],1,0);
	}
	sto(vrt(rt));
	*/
	/*//ver0.1
	rh=0;
	for(i=0;i<4;i++){
		if(frec[i].h>rh)rh=frec[i].h;
		rw+=frec[i].w;
	}
	rt.w=rw;rt.h=rh;
	sto(rt);
	*/
	
	//type B
	/*//ver0.2
	rt.w=rt.h=0;
	for(i=0;i<4;i++){
		m[i]=1;
		for(j=0;j<4;j++){
			if(!m[j])rt=cnnt(rt,frec[j],1,0);
		}
		sto(vrt(rt,hor(frec[i])));
		m[i]=0;
	}
	*/
	/*//ver0.1
	for(i=0;i<4;i++)m[i]=0;
	for(i=0;i<4;i++){
		m[i]=1;
		rw=frec[i].h;rh=0;t=0;
		for(j=0;j<4;j++){
			if(!m[j]){
				t+=frec[j].w;
				if (frec[j].h>rh)rh=frec[j].h;
			}
		}
		rw=max(rw,t);
		rh+=frec[i].w;
		rt.w=rw;rt.h=rh;
		sto(rt);
		m[i]=0;
	}
	*/
	
	//type C 
	/*//ver0.2
	for(i=0;i<4;i++){
		m[i]=1;
		for(j=0;j<4;j++){
			if(!m[j]){
				m[j]=1;
				rt.w=rt.h=0;
				for(k=0;k<4;k++){
					if(!frec[k]){
						rt=cnnt(rt,frec[k],1,0);
					}
				}
				rt=cnnt(rt,hor(frec[j]),0,0);
				rt=cnnt(rt,frec[i],1,0);
				sto(vrt(rt));
				m[j]=0;
			}
		}
		m[i]=0;
	}
	*/
	/*//ver0.1
	for(i=0;i<4;i++)m[i]=0;
	for(i=0;i<4;i++){
		m[i]=1;
		for(j=0;j<4;j++){
			if(!m[j]){
				m[j]=1;
				rw=0;rh=0;
				for(k=0;k<4;k++){
					if(!frec[k]){
						if(frec[k].h>rh)rh=frec[k].h;
						rw+=frec[k].w;
					}
				}
				rh+=frec[j].w;
				rw=max(frec[j].h,rw);
				rw+=frec[i].w;
				rh=max(frec[i].h,rh);
				rt.w=rw;rt.h=rh;
				sto(rt);
				m[j]=0;
			}
		}
		m[i]=0;
	}
	*/
	
	//type D
	/*//ver0.2
	for(i=0;i<4;i++){
		m[i]=1;
		for(j=0;j<4;j++){
			if(!m[j]){
				m[j]=1;
				rt.w=rt.h=0;
				for(k=0;k<4;k++){
					if(!frec[k]){
						rt=cnnt(rt,frec[k],0,0);
					}
				}
				rt=cnnt(rt,hor(frec[j]),1,0);
				rt=cnnt(rt,frec[i],1,0);
				sto(vrt(rt));
				m[j]=0;
			}
		}
		m[i]=0;
	}
	*/
	//type E same as D
	//type F
	
	qsort(bxs,sz,sizeof(rect),cmp);
	fprintf (fout, "%d\n", min);
	for(i=0;i<sz;i++){
		fprintf (fout, "%d %d\n", bxs[i].w, bxs[i].h);
	}
    exit (0);
}