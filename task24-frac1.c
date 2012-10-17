/*
ID: zltsang1
LANG: C
TASK: frac1
*/
#include <stdio.h>

typedef struct fraction fra;
struct fraction{
	int nu,de;
};

fra arr[10000]={0};

int cop(int a,int b){
	while(1){
		if(!(a%=b))return b==1;
		if(!(b%=a))return a==1;
	}
}

int cmp(const void* l,const void*r){
	return ((fra*)l)->nu*((fra*)r)->de-((fra*)l)->de*((fra*)r)->nu;
}

main () {
    FILE *fin  = fopen ("frac1.in", "r");
    FILE *fout = fopen ("frac1.out", "w");
    int an;
	int i,j,c;
	fra tf;
	
    fscanf (fin, "%d", &an);
	
	c=0;
	tf.nu=0;tf.de=1;
	arr[c++]=tf;
	tf.nu=1;tf.de=1;
	arr[c++]=tf;
	
	for(i=2;i<=an;i++){
		for(j=1;j<i;j++){
			if(cop(i,j)){
				tf.nu=j;tf.de=i;
				arr[c++]=tf;
			}
		}
	}
	
	qsort(arr,c,sizeof(fra),cmp);
	
	for(i=0;i<c;i++){
		fprintf(fout,"%d/%d\n",arr[i].nu,arr[i].de);
	}
	
    exit (0);
}