/*
ID: zltsang1
LANG: C
TASK: ride
*/
#include <stdio.h>

int s2n(char* s){
	int res=1;
	while(*s){
		res*=*s++-'A'+1;
	}
	return res;
}

main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[7]={0}, b[7]={0};
    fscanf (fin, "%s", a);
    fscanf (fin, "%s", b);
	if((s2n(a)-s2n(b))%47)
		fprintf (fout, "%s\n", "STAY");
	else
		fprintf (fout, "%s\n", "GO");
    exit (0);
}