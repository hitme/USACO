/*
ID: zltsang1
LANG: C
TASK: zerosum
*/
#include <stdio.h>

int an;
char ep[20];
int sum[20],sum2[10];

int op(int a,int b,char c){
	switch(c){
		case '+':return a+b;
		case '-':return a-b;
		case ' ':return a*10+b;
		default:printf("err,op %c\n",c);
	}
}

int cal(char* e){
	int t1=*e-'0';
	int t2=0;
	char o='+';
	while(*++e){
		++e;
		if(e[-1]==' '){
			t1=op(t1,e[0]-'0',' ');
		}else{
			t2=op(t2,t1,o);
			o=e[-1];
			t1=e[0]-'0';
		}
	}
	if(!op(t2,t1,o))return 1;
	return 0;
}
FILE *fout;
void helper(char o,int n){
	int i,t;
	ep[n*2-3]=o;
	ep[n*2-2]=n+'0';
	if(n==an){
		if(cal(ep)){
			ep[an*2-1]='\0';
			fprintf(fout,"%s\n",ep);
		}
		return;
	}
	helper(' ',n+1);
	helper('+',n+1);
	helper('-',n+1);
}

main () {
    FILE *fin  = fopen ("zerosum.in", "r");
    
	fout = fopen ("zerosum.out", "w");
    
    fscanf (fin, "%d", &an);
	//scanf ("%d", &an);
	
	ep[0]=1+'0';
	helper(' ',2);
	helper('+',2);
	helper('-',2);
   exit (0);
} 
