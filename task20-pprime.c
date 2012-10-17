/*
ID: zltsang1
LANG: C
TASK: pprime
*/
#include <stdio.h>

int isp(int n){
	int i;
	for(i=2;i*i<=n;i++){
		if(!(n%i))return 0;
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("pprime.in", "r");
    FILE *fout = fopen ("pprime.out", "w");
    int aa,ab,pal;
	int d1,d2,d3,d4;
	
    fscanf (fin, "%d %d", &aa,&ab);
	
	if(aa<9)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		pal = d1;
		//... deal with palindrome ...
		if(pal<aa)continue;
		if(pal>ab)exit(0);
		if(isp(pal))fprintf(fout,"%d\n",pal);
	}
	
	if(aa<99)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		pal = d1*10+d1;
		//... deal with palindrome ...
		if(pal<aa)continue;
		if(pal>ab)exit(0);
		if(isp(pal))fprintf(fout,"%d\n",pal);
	}
	
	if(aa<999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {	/* only odd; evens aren't so prime */
			pal = d1*100+d2*10+d1;
			//... deal with palindrome ...
			if(pal<aa)continue;
			if(pal>ab)exit(0);
			if(isp(pal))fprintf(fout,"%d\n",pal);
		}
	}
	
	if(aa<9999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {
			pal = 1000*d1 + 100*d2 + 10*d2 + d1;
			//... deal with palindrome ...
			if(pal<aa)continue;
			if(pal>ab)exit(0);
			if(isp(pal))fprintf(fout,"%d\n",pal);
		}
	}
	
	if(aa<99999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				pal = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
				//... deal with palindrome ...
				if(pal<aa)continue;
				if(pal>ab)exit(0);
				if(isp(pal))fprintf(fout,"%d\n",pal);
			}
		}
	}
	
	if(aa<999999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				pal = 100000*d1 + 10000*d2 +1000*d3 +100*d3 + 10*d2 + d1;
				//... deal with palindrome ...
				if(pal<aa)continue;
				if(pal>ab)exit(0);
				if(isp(pal))fprintf(fout,"%d\n",pal);
			}
		}
	}

	if(aa<9999999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					pal = 1000000*d1 + 100000*d2 +10000*d3 +1000*d4 +100*d3 + 10*d2 + d1;
					//... deal with palindrome ...
					if(pal<aa)continue;
					if(pal>ab)exit(0);
					if(isp(pal))fprintf(fout,"%d\n",pal);
				}
			}
		}
	}
	
	if(aa<99999999)
	for (d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					pal = 10000000*d1 + 1000000*d2 +100000*d3 +10000*d4 +1000*d4 +100*d3 + 10*d2 + d1;
					//... deal with palindrome ...
					if(pal<aa)continue;
					if(pal>ab)exit(0);
					if(isp(pal))fprintf(fout,"%d\n",pal);
				}
			}
		}
	}
	
    exit (0);
}