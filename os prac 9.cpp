#include<stdio.h>
#include<stdlib.h>
int main(){
	int bt[3]={2,4,8};
	int wt[3],tat[3],ct[3],i;
	int n=sizeof(bt);
	for (i=0;i<n;i++){
		if (i==0){
			ct[i]=bt[i];
			wt[i]=0;
			tat[i]=bt[i];
		
		}
		else{
			ct[i]=ct[i-1]+bt[i];
			wt[i]=ct[i-1];
			tat[i]=wt[i]+bt[i];
		}
	}
	float avg_wt=0,avg_tat=0;
	for (i=0;i<n;i++){
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	
	printf("the average waiting time is %.2f",avg_wt/3);
	printf("\nthe average turn around time is %.2f",avg_tat/3);
	return 0;
	
}
