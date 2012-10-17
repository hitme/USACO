/*
ID: zltsang1
LANG: C
TASK: ttwo
*/
#include <stdio.h>

#define MN 10

char frt[MN][MN+2];
int nod[MN][MN][4];
char edg[MN*MN*4][MN*MN*4];

typedef struct position pos;
struct position{
	int y,x;
};

pos frm,cow;

pos nbr(const pos t,int d){
	pos r={-1,-1};
	switch(d){
		case 0: if(t.x){r.x=t.x-1;r.y=t.y;}break;
		case 1: if(t.y){r.y=t.y-1;r.x=t.x;}break;
		case 2: if(t.x<MN-1){r.x=t.x+1;r.y=t.y;}break;
		case 3: if(t.y<MN-1){r.y=t.y+1;r.x=t.x;}break;
		default:printf("illegal direction\n");
	};
	return r;
}

int obs(pos t){//check if obstacle
	if(t.x==-1||frt[t.y][t.x]=='*')return 1;
	return 0;
}

void cons(){
	int i,j,k;
	pos t,tn,t0,t1,t2,t3;
	for(i=0;i<MN;i++)for(j=0;j<MN;j++){
		t.y=i;t.x=j;
		//printf("%c ",frt[i][j]);
		switch(frt[i][j]){
			case 'F':
			case 'C':{
				if(frt[i][j]=='F'){frm.y=i;frm.x=j;}
				if(frt[i][j]=='C'){cow.y=i;cow.x=j;}
			}
			case '.':{
				for(k=0;k<4;k++){
					t0=nbr(t,k);
					t1=nbr(t,(k+1)%4);
					t2=nbr(t,(k+2)%4);
					t3=nbr(t,(k+3)%4);
					
					if(!obs(t2))
						edg[nod[i][j][k]][nod[t2.y][t2.x][k]]=1;
					if(obs(t2)&&!obs(t3))
						edg[nod[i][j][k]][nod[t3.y][t3.x][(k+1)%4]]=2;
					if(obs(t2)&&obs(t3)&&!obs(t0))
						edg[nod[i][j][k]][nod[t0.y][t0.x][(k+2)%4]]=3;
					if(obs(t2)&&obs(t3)&&obs(t0)&&!obs(t1))
						edg[nod[i][j][k]][nod[t1.y][t1.x][(k+3)%4]]=4;
				}								
				break;
			}
			case '*':break;
		};
	}
}

int p2n(pos t,int d){
	return (MN*t.y+t.x)*4+d;
}

pos n2p(int n){
	pos t;
	n>>=2;
	t.x=n%MN;
	t.y=n/MN;
	return t;
}

int tbf[4][MN][MN],tbc[4][MN][MN];
pos lif[MN*MN],lic[MN*MN];

int gcd(int a,int b){
	while(1){
		if(!(a%=b))return b;
		if(!(b%=a))return a;
	}
}

int max(int a,int b){
	if(a>b)return a;
	return b;
}

int min(int a,int b){
	if(a<b)return a;
	return b;
}

int euc(int a,int b){
	int q[10]={0};
	int i=0,t;
	do{
		q[i]=-(a/b);
		i++;
		t=a%b;
		a=b;b=t;
	}while(t);
	q[i]=1;
	if(i>1)
		for(i-=1;i>=0;i--)q[i]=q[i+2]+q[i+1]*q[i];
	return q[0];
}

int sol(int a,int b,int ca,int cb){
	int i,j,mi,ret=0;
	mi=0;
	for(i=0;i<b;i++){
		for(j=0;j<a;j++){
			if((a*i+ca)==(b*j+cb)&&(!mi||(b*j+cb)<mi))mi=(b*j+cb);
		}
	}
	ret=mi;
	return ret;
}

int equ(int a,int b,int ca,int cb){//the equation:a*x+ca=b*y+cb,ret=min{b*y+cb},y=0,1,2...
	int ret=0;
	int A,B,C,ma,mb,mc,apb,amb,xcor,ycor;
	int cf,x,y,t;
	
	int i,j;
	
	A=a;B=b;t=0;
	if(ca>cb){
		t=(ca-cb)/(a+b)+1;
		C=t*(a+b)+(cb-ca);
	}else C=cb-ca;
	
	if(C==0)return a+ca;
	
	cf=gcd(gcd(A,B),C);
	A/=cf;B/=cf;C/=cf;
	if(gcd(A,B)>1)return 0;
#if 1
	for(i=1;i<A;i++){
		if(!((A*i-1)%B)){
			ret=i*A*C*cf+ca;
			break;
		}
	}
	
	return ret;
#endif

#if 0
	else{
		apb=A+B;amb=A-B;
		ma=A;mb=B;mc=C;
		xcor=ycor=(C-1)/apb;
		mc=C-apb*xcor;
		ycor+=(mc-1)/mb;
		if(mc%mb)mc%=mb;
		if(amb){
			xcor+=(mc-1)/amb;ycor-=(mc-1)/amb;
			if(mc%amb)
				mc%=amb;
		}
		y=cf*euc(ma,mb)+ycor;
	}
#endif
}

main () {
    FILE *fin  = fopen ("ttwo.in", "r");
    FILE *fout = fopen ("ttwo.out", "w");
    int i,j,k,min,mt,at,bt;
	int st,ed,pf,pc;
	int ft,ct,lf,lc,fl,cl;
	pos t,tc,ef,ec,a,b;
    
	for(i=0;i<MN;i++)fscanf (fin, "%s", frt[i]);
	
	for(i=0;i<MN;i++)for(j=0;j<MN;j++)for(k=0;k<4;k++)
		nod[i][j][k]=(i*MN+j)*4+k;
	
	cons();
	
	pf=st=p2n(frm,3);
	pc=ed=p2n(cow,3);
	
	j=fl=0;
	t=n2p(pf);
	while(!tbf[pf%4][t.y][t.x]){
		tbf[pf%4][t.y][t.x]=fl+1;
		i=0;
		while(i<MN*MN*4&&!edg[pf][i])i++;
		if(i==MN*MN*4)break;
		fl+=edg[pf][i];
		while(j<fl){lif[j++]=t;}
		pf=i;
		t=n2p(pf);
	};
	ef=t;
	ft=tbf[pf%4][t.y][t.x];
	lf=fl-ft+1;
	
	j=cl=0;
	t=n2p(pc);
	while(!tbc[pc%4][t.y][t.x]){
		tbc[pc%4][t.y][t.x]=cl+1;
		i=0;
		while(i<MN*MN*4&&!edg[pc][i])i++;
		if(i==MN*MN*4)break;
		cl+=edg[pc][i];
		while(j<cl){lic[j++]=t;}
		pc=i;
		t=n2p(pc);
	};
	ec=t;
	ct=tbc[pc%4][t.y][t.x];
	lc=cl-ct+1;
	
	min=mt=0;
	for(i=0;i<fl;i++){
		a=lif[i];
		for(j=0;j<cl;j++){
			b=lic[j];
			if(a.x==b.x&&a.y==b.y){
				at=i+1;bt=j+1;
				if(at==bt&&(!min||at<min))min=at;
				//assert(lc!=0,"check lc zero");
				//assert(lf!=0,"check lf zero");
				if(at<ft&&bt<ct){
					if(at==bt&&(!min||at<min))min=at;
				}
				if(at<ft&&bt>=ct){
					if(at>=bt&&!((at-bt)%lc)&&(!min||at<min))min=at;
				}
				if(at>=ft&&bt<ct){
					if(bt>=at&&!((bt-at)%lf)&&(!min||bt<min))min=bt;
				}
				if(at>=ft&&bt>=ct){
					if(lc>lf)mt=equ(lc,lf,bt,at);
					else mt=equ(lf,lc,at,bt);
					if(mt&&(!min||mt<min))min=mt;
				}
			}
		}
	}
	if(min)
		fprintf (fout, "%d\n",min-1);
	else
		fprintf (fout, "%d\n",min);
    exit (0);
}