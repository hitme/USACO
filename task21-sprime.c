/*
ID: zltsang1
LANG: C
TASK: sprime
*/
#include <stdio.h>

int isp(int n){
	int i;
	for(i=2;i*i<=n;i++){
		if(!(n%i))return 0;
	}
	return 1;
}

FILE *fout;

int spr(int num,int l){
	if(!l)if(isp(num))fprintf(fout,"%d\n",num);
	int i;
	for(i=1;i<10;i+=2){
		if(isp(num))spr(num*10+i,l-1);
	}
}

main () {
    FILE *fin  = fopen ("sprime.in", "r");
    int al;
	int i,j,tp;
	fout=fopen ("sprime.out", "w");
    fscanf (fin, "%d", &al);
	
	spr(2,al-1);
	spr(3,al-1);
	spr(5,al-1);
	spr(7,al-1);
	
    exit (0);
}