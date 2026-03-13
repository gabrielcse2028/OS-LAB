#include <stdio.h>
struct process {
    int id, at, bt, ct, tat, wt;
};
int main() {
    int n;
    printf("Name : Gabriel E Nitin\n");
    printf("\nNumber of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Arrival Time of P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Burst Time of P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int timePassed = 0;
    int sumTAT = 0, sumWT = 0;
    for(int i = 0; i < n; i++) {
        if(timePassed < p[i].at)
            timePassed = p[i].at;
        p[i].ct = timePassed + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        timePassed += p[i].bt;
        sumTAT += p[i].tat;
        sumWT += p[i].wt;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].id,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }
    printf("\nAverage TAT: %.2f\n", (float)sumTAT/n);
    printf("Average WT: %.2f\n", (float)sumWT/n);
    return 0;
}
