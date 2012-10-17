/*
ID: zltsang1
LANG: C
TASK: maze1
*/
#include <stdio.h>

#define qsz 200

int min(int l,int r){
	return l<r?l:r;
}

main () {
    FILE *fin,*fout;
	
	char cmz[100*2+10][38*2+10];
	int edg[100*38+1][4];
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	int nd[100*38][2],que[qsz],hed,tal,pn,tn,l;
	
	int aw,ah,ret;
	int tx,ty,ex[2],c;
	int i,j,k;
	
	fin=fopen("maze1.in","r");
	fout=fopen("maze1.out","w");
	
	fscanf(fin,"%d %d",&aw,&ah);
	
	fgets(cmz[i],sizeof cmz[0],fin);
	while(fgets(cmz[i],sizeof cmz[0],fin)!=NULL)i++;

	c=0;
	for(i=0;i<ah;i++){
		for(j=0;j<aw;j++){
			//edg[i*aw+j]
			for(k=0;k<4;k++){
				ty=i+dy[k];
				tx=j+dx[k];
				if(tx>=0&&ty>=0&&tx<aw&&ty<ah){
					if(cmz[ty*2+1-dy[k]][tx*2+1-dx[k]]==' '){
						edg[i*aw+j][k]=ty*aw+tx+1;
					}
				}else{
					if(cmz[ty*2+1-dy[k]][tx*2+1-dx[k]]==' ')
						ex[c++]=i*aw+j+1;
				}
			}
		}
	}
	
	c=0;
	for(c=0;c<2;c++){
		hed=0;tal=0;l=1;
		que[tal++]=ex[c];
		while(hed!=tal){
			que[tal]=-1;
			tal=(tal+1)%qsz;
			
			while(1){
				pn=que[hed];hed=(hed+1)%qsz;
				if(pn==-1){
					l++;break;
				}
				nd[pn-1][c]=l;
				for(i=0;i<4;i++){
					if(tn=edg[pn-1][i]){
						if(!nd[tn-1][c]){
							nd[tn-1][c]=-1;
							que[tal]=tn;
							tal=(tal+1)%qsz;
						}
					}
				}
			}
		}
	}
	
	ret=0;
	for(i=0;i<aw*ah;i++){
		if(ret<min(nd[i][0],nd[i][1]))ret=min(nd[i][0],nd[i][1]);
	}
	fprintf(fout,"%d\n",ret);
	exit(0);
}