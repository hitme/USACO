/*
ID: zltsang1
LANG: C
TASK: hamming
*/
#include <stdio.h>

int an,ab,ad;
int ret[64],cr;
int nod[1<<8];
int msk[1<<7],cm;

int ons(int v){
	int c=0;
	while(v){
		v=v&(v-1);c++;
	}
	return c;
}

int dfs(int v){
	int i,j,t,f;
	if(cr==an)return 1;
	/*
	for(i=0;i<cm;i++){
		t=v^msk[i];
	*/
	for(i=0;i<1<<ab;i++){
		t=i;
		if(nod[t])continue;
		nod[t]=1;
		f=0;
		for(j=0;j<cr;j++){
			if(ons(ret[j]^t)<ad){f=1;break;}
		}
		if(f)continue;
		ret[cr++]=t;
		if(dfs(t))return 1;
		else cr--;
	}
	return 0;
}

int cmp(const void*l,const void*r){
	return *(int*)l-*(int*)r;
}

main () {
    FILE *fin  = fopen ("hamming.in", "r");
    FILE *fout = fopen ("hamming.out", "w");
    int i;
	
	fscanf (fin, "%d %d %d", &an,&ab,&ad);
	
	//produce msk[], ele od length ab contains ad "1"s
	cm=0;
	for(i=0;i<1<<ab;i++){
		if(ons(i)==ad)msk[cm++]=i;
	}
	//start with 0,check if non-visited neighbour exists
	cr=0;
	for(i=0;i<1<<ab;i++){
		nod[i]=1;
		ret[cr++]=i;
		if(dfs(i))break;
		else cr--;
	}
	qsort(ret,an,sizeof(int),cmp);
	
	for(i=0;i<an;i++){
		fprintf(fout,"%d",ret[i]);
		if(i%10==9||i==an-1)fprintf(fout,"\n");
		else fprintf(fout," ");
	}
	exit (0);
}