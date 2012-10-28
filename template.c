/*
ID: zltsang1
LANG: C
TASK: milk
*/
#include <stdio.h>

typedef long long int64;
typedef long int32;

main () {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
	//fout=stdout;
    int i;
    fscanf (fin, "%d", &i);
    fprintf (fout, "\n");
    exit (0);
}