/*
ID: zltsang1
LANG: C
TASK: kimbits
*/
#include <stdio.h>

typedef long long int64;
typedef long int32;

main () {
    FILE *fin  = fopen ("kimbits.in", "r");
    FILE *fout = fopen ("kimbits.out", "w");
    int i;
    fscanf (fin, "%d", &i);
    fprintf (fout, "\n");
    exit (0);
}