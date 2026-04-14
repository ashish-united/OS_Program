#include<stdio.h>
 void main(){
    int front=0,pagefault=0,framecount,pagenumber,i,j,k,frame[30],pages[30];
    printf("Enter the number of frame");
    scanf("%d",&framecount);
    for(i=0;i<framecount;i++){
        frame[i]=-1;
    }
    printf("Enter the number of pages");
    scanf("%d",&pagenumber);
    for(j=0;j<pagenumber;j++){
        printf("Enter the data of each data");
        scanf("%d",&pages[j]);
    }
    for(i=0;i<pagenumber;i++){
        int page=pages[i];
        int found = 0;
        for(j=0;j<framecount;j++){
            if(frame[j]==page){
                found =1;
                break;
            }
        }
        if(found==0){
            frame[front]=page;
            front=(front+1)%framecount;
            pagefault++;
        }
        printf("\nPage %d -> ",page);
        for(k=0;k<framecount;k++){
            if(frame[k]==-1){
                printf(" - ");
            }
            else{
                printf("%d ", frame[k]);
            }
        }
    }
        printf("\n\nTotal Page Fault= %d\n",pagefault);
 }