// ROUND ROBIN

#include<stdio.h>

struct process
{
    int id, at, bt, remaining, completion, wt, tat;
};

int main()
{
    int n, tq;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter No. of Process: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    struct process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nProcess P%d\n", p[i].id);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].remaining = p[i].bt;
        p[i].completion = 0;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    int current = 0, completed = 0;

    while(completed < n)
    {
        int executed = 0;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= current && p[i].remaining > 0)
            {
                executed = 1;

                if(p[i].remaining > tq)
                {
                    current += tq;
                    p[i].remaining -= tq;
                }
                else
                {
                    current += p[i].remaining;

                    p[i].remaining = 0;

                    p[i].completion = current;

                    p[i].tat = p[i].completion - p[i].at;

                    p[i].wt = p[i].tat - p[i].bt;

                    completed++;
                }
            }
        }

        if(executed == 0)
        {
            current++;
        }
    }

    float avgTAT = 0, avgWT = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].at,
               p[i].bt,
               p[i].completion,
               p[i].tat,
               p[i].wt);

        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;

    printf("\nAverage TAT : %.2f\n", avgTAT);
    printf("Average WT  : %.2f\n", avgWT);

    return 0;
}

