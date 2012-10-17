/*
ID: zltsang1
LANG: C
TASK: crypt1
*/
#include <stdio.h>

int ok(int t,int d,const int* dt){
	int num[5]={1,10,100,1000,10000};
	//if(t>=num[d]||t<num[d-1])
	if(t>=num[d])
		return 0;
	while(t){
		if(!dt[t%10])return 0;
		t/=10;
	}
	return 1;
}

main () {
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");
    int an;
	int dg[9]={0},dt[10]={0};
	int i,j,k,l,m,a,b,c,d,e,p1,p2,f1,f2,ret;
	
    fscanf (fin, "%d", &an);
	
	for(i=0;i<an;i++){
		fscanf (fin, "%d", dg+i);
		dt[dg[i]]=1;
	}
	
	ret=0;
    for(i=0;i<an;i++){
        c=dg[i];
        for(j=0;j<an;j++){
            //f1=(f1<<3)+(f1<<1)+dg[j];//(1)opt is not necessary(2)WRONG:f1 could be altered by inner loop
			d=c*10+dg[j];
            for(k=0;k<an;k++){
                //f1=(f1<<3)+(f1<<1)+dg[k];
				e=d*10+dg[k];
                for(l=0;l<an;l++){
                    a=dg[l];
                    p1=e*a;
                    if(ok(p1,3,dt))
						for(m=0;m<an;m++){
							b=dg[m];
							p2=e*b;
							if(ok(p2,3,dt)){
								if(b=ok(a=p2*10+p1,4,dt))ret++;
						}
                    }
                }
            }
        }
    }
	
    fprintf (fout, "%d\n", ret);
    exit (0);
}