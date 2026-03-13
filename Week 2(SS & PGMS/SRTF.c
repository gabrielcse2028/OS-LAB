#include <stdio.h>

struct process {
    int id, at, bt, ct, tat, wt;
};

int main() {

    printf("GabrieL E Nitin\n");
    int n, current_time = 0, completed = 0;
    float sumTAT = 0, sumWT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    int remaining[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival time and Burst time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        remaining[i] = p[i].bt;
    }

    while (completed < n) {
        int idx = -1;
        int min = 9999;


        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && remaining[i] > 0) {
                if (remaining[i] < min) {
                    min = remaining[i];
                    idx = i;
                }

                if (remaining[i] == min) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            remaining[idx]--;
            current_time++;

            if (remaining[idx] == 0) {
                completed++;
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                sumTAT += p[idx].tat;
                sumWT += p[idx].wt;
            }
        } else {

            current_time++;
        }
    }

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage TAT: %.2f", sumTAT / n);
    printf("\nAverage WT: %.2f\n", sumWT / n);

    return 0;
}
