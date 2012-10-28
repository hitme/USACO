/*
ID: zltsang1
LANG: C
TASK: msquare
*/
#include <stdio.h>

typedef long long int64;
typedef long int32;

typedef struct trans{
char type;
int prev;
}trans;

#define SZ 8*7*6*5*4*3*2

trans dp[SZ];
int destination;

int queue[SZ][8];
int head,tail;

//copyright by Keith Randall:
//http://stackoverflow.com/questions/1506078/fast-permutation-number-permutation-mapping-algorithms
// perm[0]..perm[n-1] must contain the numbers in {0,..,n-1} in any order.
int permToNumber(int *perm, int n) {
  // base case
  if (n == 1) return 0;

  // fix up perm[1]..perm[n-1] to be a permutation on {0,..,n-2}.
  int i;
  for (i = 1; i < n; i++) {
    if (perm[i] > perm[0]) perm[i]--;
  }

  // recursively compute
  return perm[0] + n * permToNumber(perm + 1, n - 1);
}

void swap(int *perm,int x,int y){
int t=perm[x];
perm[x]=perm[y];
perm[y]=t;
}

void transform(int *perm,char type){
int i,t;
switch(type){
case 'A':
for(i=0;i<4;i++){
swap(perm,i,7-i);
}
break;
case 'B':
t=perm[3];
for(i=3;i>0;i--)
perm[i]=perm[i-1];
perm[0]=t;
t=perm[4];
for(i=4;i<7;i++)
perm[i]=perm[i+1];
perm[7]=t;
break;
case 'C':
t=perm[1];
perm[1]=perm[6];
perm[6]=perm[5];
perm[5]=perm[2];
perm[2]=t;
break;
}
}

void solve(){
int i,j;
int temp[8],save[8];
trans *tr;
char type;

int source,target;
while(head<tail){
int *src=queue[head];
for(i=0;i<8;i++)
temp[i]=src[i];
source=permToNumber(temp,8);

for(j=0;j<3;j++){
type='A'+j;

for(i=0;i<8;i++)
save[i]=src[i];
transform(save,type);

for(i=0;i<8;i++)
temp[i]=save[i];
target=permToNumber(temp,8);

if(target==destination){
dp[destination].prev=source;
dp[destination].type=type;
return;
}
if(dp[target].prev>=0)
continue;
dp[target].prev=source;
dp[target].type=type;

for(i=0;i<8;i++)
queue[tail][i]=save[i];
tail++;
}//end for type
head++;
}//end while

}

main () {
    FILE *fin  = fopen ("msquare.in", "r");
    FILE *fout = fopen ("msquare.out", "w");
	//fout=stdout;
    int i;
	int perm[8];
	
	for(i=0;i<8;i++)
		fscanf (fin, "%d", perm+i);
		
	for(i=0;i<SZ;i++)
		dp[i].prev=-1;
	
	int temp[8];
	for(i=0;i<8;i++)
	temp[i]=perm[i]-1;
	destination=permToNumber(temp,8);
	
	for(i=0;i<8;i++)
		queue[0][i]=i;
	head=0;tail=1;
	
	solve();
	
	char path[SZ];
	
	for(i=0;i<SZ;i++){
		if(destination==0)break;
		path[i]=dp[destination].type;
		destination=dp[destination].prev;
	}
	
	fprintf(fout, "%d\n",i);
	int j=0;
	for(;i>0;){
		++j;
		if(j==60){
			j=0;
			fprintf(fout, "\n");
		}
		fprintf(fout, "%c",path[--i]);
	}
	fprintf(fout, "\n");
	
    //fprintf (fout, "\n");
    exit (0);
}