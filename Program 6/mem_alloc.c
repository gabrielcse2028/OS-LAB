#include <stdio.h>
void firstFit(int blocks[], int b, int processes[], int p)
{
    int allocation[10];
    int used[10] = {0};
    int i, j;

    for(i = 0; i < p; i++)
        allocation[i] = -1;

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < b; j++)
        {
            // Check if block fits and is unused
            if(blocks[j] >= processes[i] && used[j] == 0)
            {
                allocation[i] = j;
                used[j] = 1;
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < p; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void bestFit(int blocks[], int b, int processes[], int p)
{
    int allocation[10];
    int used[10] = {0};
    int i, j;

    for(i = 0; i < p; i++)
        allocation[i] = -1;

    for(i = 0; i < p; i++)
    {
        int best = -1;

        for(j = 0; j < b; j++)
        {
            if(blocks[j] >= processes[i] && used[j] == 0)
            {
                if(best == -1 || blocks[j] < blocks[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            used[best] = 1;
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < p; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void worstFit(int blocks[], int b, int processes[], int p)
{
    int allocation[10];
    int used[10] = {0};
    int i, j;

    for(i = 0; i < p; i++)
        allocation[i] = -1;

    for(i = 0; i < p; i++)
    {
        int worst = -1;

        for(j = 0; j < b; j++)
        {
            if(blocks[j] >= processes[i] && used[j] == 0)
            {
                if(worst == -1 || blocks[j] > blocks[worst])
                {
                    worst = j;
                }
            }
        }

        if(worst != -1)
        {
            allocation[i] = worst;
            used[worst] = 1;
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < p; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    int blocks[10], processes[10];
    int b, p, i;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    // Input number of blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &b);

    // Input block sizes
    printf("Enter sizes of %d memory blocks:\n", b);

    for(i = 0; i < b; i++)
    {
        scanf("%d", &blocks[i]);
    }


    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter sizes of %d processes:\n", p);

    for(i = 0; i < p; i++)
    {
        scanf("%d", &processes[i]);
    }
    firstFit(blocks, b, processes, p);
    bestFit(blocks, b, processes, p);
    worstFit(blocks, b, processes, p);

    return 0;
}
