#include<stdio.h>
int main(){
	int memory[]={300,600,350,200,750,125};
	int process[]={115,500,358,200,375};
	int i,j,n,m;
	int output[5];
	n=sizeof(memory)/sizeof(memory[0]);
	m=sizeof(process)/sizeof(process[0]);
	for (i=0;i<m;i++){
		output[i]=-1;
		
	}
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if(process[i]<=memory[j]){
				output[i]=j;
				memory[j]=0;
				break;
			}
		}
	}
	printf("process no\tprocess size\tallocated block");
	for(i=0;i<m;i++){
		printf("\n%d\t\t",i+1);
		if (output[i]!=-1){
			printf("%d\t\t%d",process[i],output[i]+1);
		}
		else{
			printf("%d\t\tNot allocated",process[i]);
		}
	}
	return 0;
	
}
