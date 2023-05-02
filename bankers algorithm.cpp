#include<stdio.h>
void input(int mat[4][3],int n,int m);
void output(int mat[4][3],int n,int m);
int main(){
	int max[4][3],allocation[4][3],need[4][3],available[4],safe[4],status[4];
	int n,m,i,j,iter=0,complete=0;
	printf("enter the no.of processes ");
	scanf("%d",&n);
	printf("enter the no.of resources ");
	scanf("%d",&m);
	
	//Getting the max matrix
	printf("enter the max matrix");
	input(max,n,m);
	
	//Getting the allocation matrix
	printf("enter the allocation matrix");
	input(allocation,n,m);
	
	//Getting the available matrix
	for(i=0;i<m;i++){
		printf("enter the available number for resource %d",i);
		scanf("%d",&available[i]);
		
	}
	
	//Computing the need matrix
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	//Printing max matrix
	printf("Max Matrix\n");
	output(max,n,m);
	
	//Printing allocation matrix
	printf("Allocation Matrix\n");
	output(allocation,n,m);
	
	//Printing need matrix
	printf("Need Matrix\n");
	output(need,n,m);
	
	//set the status of the process
    for(i=0;i<n;i++)
    {
        status[i]=0;
        safe[i]=0;
    }
    
    i=0;
    complete=0;
    iter=0;
   while(complete<n&&iter<2)
   {
       if(status[i]==0 && need[i][0]<=available[0] && need[i][1]<=available[1]&& need[i][2]<=available[2])
       {
           available[0]+=allocation[i][0];
           available[1]+=allocation[i][1];
           available[2]+=allocation[i][2];
           status[i]=1;
           safe[complete]=i;
           complete++;
       }
       if(i<n)
        i++;
       else
       {
         i=0;
         iter++;
       }

   }

  if(complete < n-1)
   {
      printf("\n The system is in unsafe state");
   }
   else
   {
      printf("\n The safe sequence is ");
      for(i=0;i<n;i++)
      {
          printf("%d -> ",safe[i]);
      }

   printf("\n the total no of resource available is ");
   for(i=0;i<m;i++)
    {
        printf("\n the available resources for the %d ",available[i]);
    }
   }
}


void input(int mat[4][3],int n,int m){
	int i,j;
	for (i=0;i<n;i++){
		printf("enter the column %d elements",i);
		for (j=0;j<m;j++){
			printf("\nenter the row %d element ",j);
			scanf("%d",&mat[i][j]);
		}
	}
}

void output(int mat[4][3],int n,int m){
	int i,j;
	for (i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",mat[i][j]);
		}
	}
}
