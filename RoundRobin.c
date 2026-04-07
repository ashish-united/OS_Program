// Round Robin Scheduling Algorithm in C
#include <stdio.h>

void main() {
    int at[10], bt[10], p[10], rt[10], tat[10], wt[10], ct[10];
    int n, i, time = 0, completed = 0, tq;
    float atat = 0.0, awt = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the p[%d],Enter the at[%d],Enter the bt[%d]: ",i+1,i+1,i+1);
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
        rt[i] = bt[i]; // Remaining time starts as burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Logic
    while(completed < n) {
        int done_something = 0; 

        for(i = 0; i < n; i++) {
            // Check if process has arrived and still has remaining time
            if(at[i] <= time && rt[i] > 0) {
                done_something = 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    // Process will finish in this time slice
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    // Calculations
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    atat += tat[i];
                    awt += wt[i];
                }
            }
        }
    }

    atat /= n;
    awt /= n;

    printf("\nPNo.\tAT\tBT\tCT\tWT\tTAT");
    for(i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}