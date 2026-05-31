// MULTILEVEL QUEUE SCHEDULING

#include<stdio.h>

#define MAX 10

struct process
{
    int pid, at, bt, rt, ct, tat, wt, queue;
};

int main()
{
    struct process p[MAX];

    int n, i, time = 0, completed = 0;
    int tq = 2;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter number of Process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of P%d\n", i + 1);

        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Queue (1-System, 2-User): ");
        scanf("%d", &p[i].queue);

        p[i].rt = p[i].bt;
    }

    printf("\nEnter Time Quantum (for system process): ");
    scanf("%d", &tq);

    printf("\nGANTT CHART:\n");

    while(completed < n)
    {
        int executed = 0;

        // Queue 1 -> Round Robin
        for(i = 0; i < n; i++)
        {
            if(p[i].queue == 1 && p[i].rt > 0 && p[i].at <= time)
            {
                executed = 1;

                if(p[i].rt > tq)
                {
                    printf("P%d ", p[i].pid);

                    time += tq;

                    p[i].rt -= tq;
                }
                else
                {
                    printf("P%d ", p[i].pid);

                    time += p[i].rt;

                    p[i].rt = 0;

                    p[i].ct = time;

                    completed++;
                }
            }
        }

        // Queue 2 -> FCFS
        if(!executed)
        {
            for(i = 0; i < n; i++)
            {
                if(p[i].queue == 2 && p[i].rt > 0 && p[i].at <= time)
                {
                    executed = 1;

                    printf("P%d ", p[i].pid);

                    time += p[i].rt;

                    p[i].rt = 0;

                    p[i].ct = time;

                    completed++;

                    break;
                }
            }
        }

        if(!executed)
        {
            time++;
        }
    }

    float total_tat = 0, total_wt = 0;

    printf("\n\nPID\tAT\tBT\tType\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;

        p[i].wt = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt += p[i].wt;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].queue,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f",
           total_tat / n);

    printf("\nAverage Waiting Time = %.2f\n",
           total_wt / n);

    return 0;
}
