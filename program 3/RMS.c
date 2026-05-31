// RATE MONOTONIC SCHEDULING

#include<stdio.h>
#include<math.h>

struct process
{
    int pid, bt, period, remaining_burst;
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
    int n;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter the no of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter CPU Burst Time:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }

    printf("Enter Time Period:\n");

    int hyperperiod = 1;
    double utilization = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].period);

        p[i].remaining_burst = 0;

        hyperperiod = lcm(hyperperiod, p[i].period);

        utilization += (double)p[i].bt / p[i].period;
    }

    // Sort according to period (smaller period = higher priority)
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(p[i].period > p[j].period)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nHyperperiod (LCM) = %d\n", hyperperiod);

    printf("\nRate Monotonic Scheduling\n");

    printf("PID\tBT\tPeriod\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].period);
    }

    double bound = n * (pow(2.0, 1.0 / n) - 1.0);

    printf("\nUtilization = %.3lf\n", utilization);
    printf("Bound       = %.3lf\n", bound);

    if(utilization <= 1)
    {
        printf("\nSchedulable\n");

        printf("\nScheduling for %d ms:\n\n", hyperperiod);

        int current_process = -1;

        for(int time = 0; time < hyperperiod; time++)
        {
            // Process release
            for(int i = 0; i < n; i++)
            {
                if(time % p[i].period == 0)
                {
                    // Deadline miss check
                    if(p[i].remaining_burst > 0)
                    {
                        printf("Deadline Miss for Process P%d at time %d\n",
                               p[i].pid, time);
                    }

                    p[i].remaining_burst += p[i].bt;
                }
            }

            int next_process = -1;

            // Highest priority ready process
            for(int i = 0; i < n; i++)
            {
                if(p[i].remaining_burst > 0)
                {
                    next_process = i;
                    break;
                }
            }

            // Context switch display
            if(next_process != current_process)
            {
                if(next_process == -1)
                {
                    printf("%d ms onwards : CPU Idle\n", time);
                }
                else
                {
                    printf("%d ms onwards : Process P%d running\n",
                           time,
                           p[next_process].pid);
                }

                current_process = next_process;
            }

            // Execute process
            if(current_process != -1)
            {
                p[current_process].remaining_burst--;
            }
        }
    }
    else
    {
        printf("\nNot Schedulable\n");
    }

    return 0;
}
