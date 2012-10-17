/*
ID: zltsang1
LANG: C
TASK: lamps
*/
#include <stdio.h>

typedef struct configuration cnf;
struct configuration{
	int t;
	unsigned int v[4];
};

#define set(x,i) (x).v[(an-(i))/32]|=1<<((an-(i))%32)
#define bit(x,i) ((x).v[(an-(i))/32]&1<<((an-(i))%32))
#define ust(x,i) (x).v[(an-(i))/32]&=~(1<<((an-(i))%32))

int cmp(const void*l,const void*r){
	cnf a,b;
	int i;
	a=*(cnf*)l;b=*(cnf*)r;
	for(i=4;i-->0;){
		if(a.v[i]!=b.v[i])return a.v[i]-b.v[i];
	}
	return 0;
}

cnf on,off,but[4];
cnf var[16];
int an,ac;

cnf toggle(const cnf v,const cnf b){
	cnf t=v;
	int i;
	for(i=0;i<4;i++){
		t.v[i]=v.v[i]^b.v[i];
	}
	return t;
}

FILE *fout;

void print(cnf x){
	int i;
	//printf("%2d ",x.t);
	for(i=1;i<=an;i++){
	//	if(bit(x,i))fputchar('1');
	//	else fputchar('0');
		if(bit(x,i))fputc('1',fout);
		else fputc('0',fout);
	}
	fprintf(fout,"\n");
}

main () {
    FILE *fin  = fopen ("lamps.in", "r");
    fout = fopen ("lamps.out", "w");
	
	int i,j,t,f1,f2;
	cnf tc;
    fscanf (fin, "%d", &an);
	fscanf (fin, "%d", &ac);
	
	for(i=1;i<=an;i++)set(but[0],i);
	for(i=1;2*i<=an;i++)set(but[1],2*i);
	for(i=1;2*i-1<=an;i++)set(but[2],2*i-1);
	for(i=0;3*i+1<=an;i++)set(but[3],3*i+1);
		
    while(1){
		fscanf (fin, "%d", &t);
		if(t<0)break;
		set(on,t);
	}
	
	while(1){
		fscanf (fin, "%d", &t);
		if(t<0)break;
		set(off,t);
	}
	
	for(i=0;i<4;i++)tc.v[i]=0;
	for(i=0;i<16;i++){//16 possible states
		for(j=1;j<=an;j++)set(tc,j);
		tc.t=0;
		if(i&1){tc=toggle(tc,but[0]);tc.t++;}
		if(i&2){tc=toggle(tc,but[1]);tc.t++;}
		if(i&4){tc=toggle(tc,but[2]);tc.t++;}
		if(i&8){tc=toggle(tc,but[3]);tc.t++;}
		var[i]=tc;
	}
	
	qsort(var,16,sizeof(cnf),cmp);
	
	for(i=0;i<4;i++)tc.v[i]=1;
	
	f2=0;
	for(i=0;i<16;i++){
		f1=1;
		for(j=1;j<=an;j++){
			if((bit(on,j)&&!bit(var[i],j))||(bit(off,j)&&bit(var[i],j))){
				f1=0;
			}
		}
		if(!f1)continue;
		if(ac<var[i].t)continue;
		if((ac-var[i].t)%2==0){
			if(!cmp(&tc,&var[i]))continue;
			f2=1;
			print(var[i]);
			tc=var[i];
		}
	}
	if(!f2)fprintf(fout,"IMPOSSIBLE\n");
	exit (0);
}