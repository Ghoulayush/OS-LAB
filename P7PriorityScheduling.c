#include <stdio.h>

typedef struct {
    int pid, at,bt,ct,wt,tat,rt,priority;
} Process;

void nonPreemptive(Process p[], int n) {
    int completed = 0, time = 0, done[n];
    for (int i = 0; i < n; i++) done[i] = 0;

    while (completed < n) {
        int idx = -1, bestPriority = 999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && !done[i] && p[i].priority < bestPriority) {
                bestPriority = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            done[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }
}

void preemptive(Process p[], int n) {
    int completed = 0, time = 0;

    while (completed < n) {
        int idx = -1, bestPriority = 999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].priority < bestPriority) {
                bestPriority = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            p[idx].rt--;
            time++;
            if (p[idx].rt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            time++;
        }
    }
}

int main() {
    int n, choice;
    printf("Name: Ayush Ramola | Section: C (G1) | Roll No : 17\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority (lower = higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].rt = p[i].bt;
    }

    printf("\nChoose Scheduling Type:\n");
    printf("1. Non-Preemptive Priority\n");
    printf("2. Preemptive Priority\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            nonPreemptive(p, n);
            printf("\nNon-Preemptive Priority Scheduling Results:\n");
            break;
        case 2:
            preemptive(p, n);
            printf("\nPreemptive Priority Scheduling Results:\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    // print results directly in main
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    return 0;
}
