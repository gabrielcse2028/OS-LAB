#include<stdio.h>

struct process
{
    int id, at, bt, ct, tat, wt;
};

int main()
{
    int n, current_time = 0;
    int sumTAT = 0, sumWT = 0;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter No. of Process: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("Enter AT for Process P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter BT for Process P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    // Sorting based on Arrival Time
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(p[i].at > p[j].at)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(current_time < p[i].at)
        {
            current_time = p[i].at;
        }

        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        current_time = p[i].ct;

        sumTAT += p[i].tat;
        sumWT += p[i].wt;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    float avgTAT = (float)sumTAT / n;
    float avgWT = (float)sumWT / n;

    printf("\nAverage TAT : %.2f\n", avgTAT);
    printf("Average WT  : %.2f\n", avgWT);

    return 0;
}
