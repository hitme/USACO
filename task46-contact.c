/*
ID: zltsang1
LANG: C
TASK: contact
*/
#include <stdio.h>
#include <string.h>

typedef long long int64;
typedef long int32;

#define nl 80

typedef struct freqpat frp;
struct freqpat{
	int f,p;
};

#define xn 12
frp cnt[1<<(xn+1)];

int cmp(const void*l,const void*r){
	frp *a,*b;
	a=(frp *)l;b=(frp *)r;
	if(a->f!=b->f)return b->f-a->f;
	else return a->p-b->p;
}

char str[15];
char* i2s(int v){
	int i;
	char *ret;
	ret=str+12;
	*ret=0;
	while(v){
		ret--;
		*ret=v%2+'0';
		v/=2;
	}
	return ret+1;
}

main () {
    FILE *fin  = fopen ("contact.in", "r");
    FILE *fout = fopen ("contact.out", "w");
	//fout=stdout;
	
	int aa,ab,an;
	char buf[nl+xn+10];
	int off,len,sl;
	char *cp;
	int idx;
    int i,j,k;
    fscanf (fin, "%d %d %d", &aa,&ab,&an);
	
	for(i=0;i<sizeof(cnt)/sizeof(frp);i++){
		cnt[i].p=i;
	}
	
	cp=buf+xn-1;
	while(1){
		//read new line,if fail break.
		fscanf(fin,"%s",buf+xn-1);
		sl=strlen(buf+xn-1);
		if(sl<nl)break;
		len=nl-(xn-1);
		if(cp==buf)len=nl;
		//process pattern
		for(j=0;j<len;j++){
			idx=0;off=1;
			for(i=0;i<aa-1;i++){
				idx<<=1;
				idx+=(cp[i]-'0');
			}
			for(i=aa-1;i<ab;i++){
				idx<<=1;
				idx+=(cp[i]-'0');
				off=1<<(i+1);
				cnt[off+idx].f++;
			}
			cp++;
		}
		strncpy(buf,cp,xn-1);cp=buf;
		memset(buf+xn-1,0,nl);
	}
	
	if(cp==buf)sl+=xn-1;
	{
		for(j=0;j<sl;j++){
			idx=0;off=1;
			for(i=0;i<aa-1;i++){
				idx<<=1;
				if(cp[i]=='\0')break;
				idx+=(cp[i]-'0');
			}
			for(i=aa-1;i<ab;i++){
				idx<<=1;
				if(cp[i]=='\0')break;
				idx+=(cp[i]-'0');
				off=1<<(i+1);
				cnt[off+idx].f++;
			}
			cp++;
		}
	}
	
	qsort(cnt,sizeof(cnt)/sizeof(frp),sizeof(frp),cmp);
	
	k=0;
	for(i=0;;i++){
		if(!cnt[i].f)break;
		if(!i||cnt[i].f<cnt[i-1].f){
			k++;
			if(k>an)break;
			fprintf(fout,"%d\n",cnt[i].f);
			j=0;
		}
		if(cnt[i].f==cnt[i+1].f&&j<5){
			fprintf(fout,"%s ",i2s(cnt[i].p));j++;
		}else{
			if(j==5)j=0;
			fprintf(fout,"%s\n",i2s(cnt[i].p));
		}
	}
	
    //if(j<5)fprintf (fout, "\n");
    exit (0);
}