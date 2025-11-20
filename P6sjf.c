#include <stdio.h>

typedef struct {
    int pid, at, bt, ct, tat, wt, rt;
} Process;

void sjfNonPreemptive(Process p[], int n) {
    int completed = 0, curr_time = 0, done[n];
    for (int i = 0; i < n; i++) done[i] = 0;

    while (completed < n) {
        int idx = -1, min_bt = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && !done[i] && p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
            }
        }
        if (idx != -1) {
            curr_time += p[idx].bt;
            p[idx].ct = curr_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            done[idx] = 1;
            completed++;
        } else {
            curr_time++;
        }
    }
}

void sjfPreemptive(Process p[], int n) {
    int completed = 0, curr_time = 0;
    while (completed < n) {
        int idx = -1, min_rt = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && p[i].rt > 0 && p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    idx = i;
            }
        }
        if (idx != -1) {
            p[idx].rt--;
            curr_time++;
            if (p[idx].rt == 0) {
                p[idx].ct = curr_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            curr_time++;
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
        printf("\nProcess %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;  // remaining time initially = burst time
    }

    printf("\nChoose Scheduling Type:\n");
    printf("1. SJF Non-Preemptive\n");
    printf("2. SJF Preemptive\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sjfNonPreemptive(p, n);
            printf("\n--- SJF Non-Preemptive Results ---\n");
            break;
        case 2:
            sjfPreemptive(p, n);
            printf("\n--- SJF Preemptive (SRTF) Results ---\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    // Print results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid, p[i].at, p[i].bt,p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    return 0;
}
