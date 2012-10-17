/*
ID: zltsang1
LANG: C
TASK: money
*/
#include <stdio.h>

int cng[25];
#define mem1 10000+1
#define mem2 25+1
long long mem[mem1][mem2];

long long cons(int am,int av){
	int i;
	long long ret=0;
	if(!am)return 1;
	if(!av)return 0;
	if(mem[am][av])return mem[am][av]-1;//fail testcase 10
	for(i=0;i<=am/cng[av-1];i++){
		ret+=cons(am-cng[av-1]*i,av-1);
	}
	mem[am][av]=ret+1;
	return ret;
}

main () {
    FILE *fin  = fopen ("money.in", "r");
    FILE *fout = fopen ("money.out", "w");
	long long ret;
	int av,an;
	int i,j;
	
    fscanf (fin, "%d %d", &av,&an);
	for(i=0;i<av;i++){
		fscanf (fin, "%d", cng+i);
	}
	
	ret=0;
	for(i=0;i<=an/cng[av-1];i++){
		ret+=cons(an-cng[av-1]*i,av-1);
	}
	
    fprintf (fout, "%lld\n",ret);
    exit (0);
}