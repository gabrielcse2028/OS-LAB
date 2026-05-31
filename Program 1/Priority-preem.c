// PRIORITY PREEMPTIVE SCHEDULING

#include<stdio.h>

struct process
{
    int id, at, bt, pr, ct, tat, wt;
};

int main()
{
    int n, current_time = 0, completed = 0;
    float avgTAT = 0, avgWT = 0;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter No. of Process: ");
    scanf("%d", &n);

    struct process p[n];
    int remaining[n];

    for(int i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);

        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &p[i].pr);

        remaining[i] = p[i].bt;
    }

    printf("\nAssuming lower number = higher priority\n");

    while(completed < n)
    {
        int idx = -1;
        int highest = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= current_time && remaining[i] > 0)
            {
                // Select higher priority process
                if(p[i].pr < highest)
                {
                    highest = p[i].pr;
                    idx = i;
                }

                // Tie-breaking using arrival time
                else if(p[i].pr == highest)
                {
                    if(p[i].at < p[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }

        // If process found
        if(idx != -1)
        {
            remaining[idx]--;
            current_time++;

            // Process completed
            if(remaining[idx] == 0)
            {
                completed++;

                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                avgTAT += p[idx].tat;
                avgWT += p[idx].wt;
            }
        }
        else
        {
            // CPU Idle
            current_time++;
        }
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].at,
               p[i].bt,
               p[i].pr,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage TAT : %.2f\n", avgTAT);
    printf("Average WT  : %.2f\n", avgWT);

    return 0;
}
