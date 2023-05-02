#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j,p[4][2],wt[4],ct[4],tat[4];
    printf("Enter the number of process \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter the Arrival time");
        scanf("%d",&p[i][0]);
        printf("\n Enter the Burst time");
        scanf("%d",&p[i][1]);
    }

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
            printf("\t %d",p[i][j]);
    }

    for(i=0;i<n;i++)
    {
     if(i==0)
        wt[i]=0;
     else
        wt[i]=ct[i-1]-p[i][0];
     if(i==0)
        ct[i]=p[i][1];
     else
        ct[i]=ct[i-1]+p[i][1];

     tat[i]=wt[i]+p[i][1];
    }
    printf("\n Waiting time of the process \n");
    for(i=0;i<n;i++)
       printf("\t %d -> %d",i,wt[i]);
    printf("\n Completion time of the process \n");
    for(i=0;i<n;i++)
       printf("\t %d -> %d",i,ct[i]);
    printf("\n Turn around time of the process \n");
    for(i=0;i<n;i++)
       printf("\t %d -> %d",i,tat[i]);
    return 0;
}
