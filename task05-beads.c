/*
ID: zltsang1
LANG: C
TASK: beads
*/
#include <stdio.h>

typedef struct segment seg;

struct segment{
	char cl;
	int le;
};

seg seq[200]={0};
int csq=0;

seg* bite(char *nec){
	char clr=*nec;
	seq[csq].cl=clr;
	seq[csq].le=1;
	while(*++nec==clr){
		seq[csq].le++;
	}
	csq++;
	return seq+csq-1;//no return cause segfault
}

main () {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
    int res,nb;
	char nec[360];
	
	seg *cs;
	int a,b;
	int i,t,j,k;
	
    fscanf (fin, "%d",&nb);
    fscanf (fin, "%s",nec);
	
    i=0;
    while(*(nec+i)){
        cs=bite(nec+i);
        i+=(cs->le);//const pointer
    }
	
	if(seq[0].cl=='w'&&seq[csq-1].cl=='w'){
		seq[0].le+=seq[csq-1].le;
		csq--;
	}
		
	for(i=0;i<csq;i++){
		if(seq[(i+csq)%csq].cl=='w'&&(seq[(i+csq-1)%csq].cl==seq[(i+csq+1)%csq].cl))// order of logic arithmatic
			seq[(i+csq)%csq].cl=seq[(i+csq-1)%csq].cl;
	}
	
	t=0;
	for(i=1;i<csq;i++){//method for encompact
		if(seq[i].cl==seq[t].cl)
			seq[t].le+=seq[i].le;
		else{
			seq[++t].cl=seq[i].cl;
			seq[t].le=seq[i].le;
		}
	}
	csq=t+1;
	
	while(seq[0].cl==seq[csq-1].cl){
		seq[0].le+=seq[csq-1].le;
		csq--;
	}

	if(csq<2||(csq==2&&(seq[0].cl=='w'||(seq[1].cl=='w')))){
		fprintf (fout, "%d\n", nb);	exit (0);
	}
	
	res=0;
	for(i=0;i<csq;){
		t=0;
		if(seq[i].cl=='w'){++i;continue;}
		if(seq[(i+csq-1)%csq].cl=='w')t+=seq[(i+csq-1)%csq].le;
		t+=seq[i].le;
		if(seq[(i+csq+1)%csq].cl=='w'){
			j=i+2;
			t+=seq[(i+csq+1)%csq].le;
		}else{
			j=i+1;
		}
		t+=seq[j%csq].le;
		if(seq[(j+csq+1)%csq].cl=='w'&&((j+csq+1)%csq!=(i+csq-1)%csq))t+=seq[(j+csq+1)%csq].le;
		if(t>res)res=t;
		i=j;
	}
	
	fprintf (fout, "%d\n", res);
    exit (0);
}