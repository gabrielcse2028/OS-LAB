// EARLIEST DEADLINE FIRST (EDF)

#include<stdio.h>
#include<math.h>

struct process
{
    int pid, burst, deadline, period;
    int remaining_burst, absolute_deadline;
};

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n, hyperperiod = 1;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter the no of process: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("\nProcess %d - Enter Burst, Deadline, Period: ",
               i + 1);

        scanf("%d %d %d",
              &p[i].burst,
              &p[i].deadline,
              &p[i].period);

        p[i].remaining_burst = 0;

        hyperperiod = lcm(hyperperiod, p[i].period);
    }

    printf("\nPID\tBurst\tDeadline\tPeriod\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t\t%d\n",
               p[i].pid,
               p[i].burst,
               p[i].deadline,
               p[i].period);
    }

    printf("\nScheduling occurs for %d ms\n\n",
           hyperperiod);

    for(int time = 0; time < hyperperiod; time++)
    {
        for(int i = 0; i < n; i++)
        {
            if(time % p[i].period == 0)
            {
                p[i].remaining_burst = p[i].burst;

                p[i].absolute_deadline =
                    time + p[i].deadline;
            }
        }

        int min_deadline = 99999;
        int selected = -1;

        for(int i = 0; i < n; i++)
        {
            if(p[i].remaining_burst > 0)
            {
                if(p[i].absolute_deadline < min_deadline)
                {
                    min_deadline =
                        p[i].absolute_deadline;

                    selected = i;
                }
            }
        }

        if(selected == -1)
        {
            printf("%d ms : CPU is idle\n",
                   time);
        }
        else
        {
            printf("%d ms : Task %d is running\n",
                   time,
                   p[selected].pid);

            p[selected].remaining_burst--;
        }
    }

    return 0;
}
