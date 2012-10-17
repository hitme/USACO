/*
ID: zltsang1
LANG: C
TASK: friday
*/
#include <stdio.h>

main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
	
	int mp[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int ml[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int c[7]={0};
	int ny,ye,da;
	int i,j;
	
	fscanf(fin, "%d", &ny);
	
	da=13;
	for(i=0;i<ny;i++){
			ye=1900+i;
			if(ye%4||(!(ye%100)&&ye%400)){
				for(j=0;j<12;j++){
					c[da%7]++;
					da+=mp[j];
				}
			}else{
				for(j=0;j<12;j++){
					c[da%7]++;
					da+=ml[j];
				}
			}
	}
	
    fprintf(fout, "%d ", c[6]);
    for(i=0;i<5;i++){
        fprintf (fout, "%d ", c[i]);//20:36 33 34 33 35 35 34
    }
    fprintf(fout, "%d\n", c[5]);
    exit (0);
}