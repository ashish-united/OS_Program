#include<stdio.h>
 void main()
 {
    int p[10],bt[10],at[10],ct[10],tat[10],wt[10];
    int n,i;
    printf("Enter the Number of Process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the p[%d],Enter the at[%d],Enter the bt[%d]",i+1,i+1,i+1);
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
    }
    printf("\npno.\tbtno\twtno.");
   for(i=0;i<n;i++)
   {
    printf("\n%d\t%d\t%d",p[i],bt[i],at[i]);
   }

 }