// Preemptive Priority Scheduling Algorithm in C
#include <stdio.h>

void main() {
    int at[10], bt[10], p[10], pr[10], tat[10], wt[10], rt[10], ct[10];
    int n, i, time = 0, completed = 0, pos;
    float atat = 0.0, awt = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter process id p[%d]: ", i+1);
        scanf("%d", &p[i]);
        printf("Enter arrival time at[%d]: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time bt[%d]: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter priority pr[%d] (smaller = higher priority): ", i+1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i]; // remaining time initially = burst time
    }

    while(completed < n) {
        pos = -1;
        int minPriority = 9999;

        // find process with highest priority among arrived and not finished
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < minPriority) {
                    minPriority = pr[i];
                    pos = i;
                }
            }
        }

        if(pos != -1) {
            rt[pos]--; // run process for 1 unit
            time++;

            if(rt[pos] == 0) { // process finished
                completed++;
                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];
                atat += tat[pos];
                awt += wt[pos];
            }
        } else {
            time++; // idle if no process available
        }
    }

    atat /= n;
    awt /= n;

    printf("\nPNo.\tAT\tBT\tPR\tCT\tWT\tTAT");
    for(i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}