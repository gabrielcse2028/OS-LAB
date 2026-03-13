#include<stdio.h>
struct Process {
    int id, at, bt, pr, ct, tat, wt;
};

int main() {
    printf("Gabriel E Nitin 1BM25CS442\n");
    int n, current_time=0, completed=0;
    float avgTat=0, avgWt=0;

    printf("Enter no. of process: ");
    scanf("%d",&n);
    struct Process P[n];
    int visited[n];

    for(int i=0; i<n; i++) {
        P[i].id=i+1;
        printf("Enter arrival  and burst time for P%d: ",i+1);
        scanf("%d %d",&P[i].at, &P[i].bt);
        printf("Enter priority for P%d: ",i+1);
        scanf("%d",&P[i].pr);
        visited[i]=0;
    }

    printf("Assuming lowest no as highest priority\n");
    while(completed<n) {
        int idx=-1;
        int highest=999;
        for(int i=0; i<n; i++) {
            if(P[i].at<=current_time && visited[i]==0) {
                if(P[i].pr < highest) {
                    highest=P[i].pr;
                    idx=i;
                }
            }
        }

        if(idx!=-1) {
            current_time += P[idx].bt;
            P[idx].ct =current_time;
            P[idx].tat = P[idx].ct-P[idx].at;
            P[idx].wt = P[idx].tat-P[idx].bt;
            avgTat += P[idx].tat;
            avgWt += P[idx].wt;

            visited[idx]=1;
            completed++;
        }
        else {
            current_time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].bt, P[i].pr, P[i].ct, P[i].tat, P[i].wt);
    }

    avgTat = avgTat/n;
    avgWt = avgWt/n;
    printf("\nAverage TAT: %f", avgTat);
    printf("\nAverage WT: %f",avgWt);

    return 0;
}
