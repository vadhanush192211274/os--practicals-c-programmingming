#include <stdio.h>
#define P 3 // Number of processes
#define R 3 // Number of resource instances

// Function to check if a process can finish or not
int canFinish(int process, int allocation[][R], int need[][R], int available[]) {
    for (int i = 0; i < R; i++) {
        if (need[process][i] > available[i])
            return 0;
    }
    return 1;
}

// Function to detect if there is deadlock or not
void detectDeadlock(int max[][R], int allocation[][R], int available[]) {
    int need[P][R], finish[P];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
        finish[i] = 0; // Initialize finish array to 0
    }
    int work[R];
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }
    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0 && canFinish(i, allocation, need, work)) {
                for (int j = 0; j < R; j++) {
                    work[j] += allocation[i][j];
                }
                finish[i] = 1;
                found = 1;
                count++;
                printf("Process %d can finish.\n", i);
            }
        }
        if (found == 0) {
            printf("Deadlock detected.\n");
            return;
        }
    }
    printf("No deadlock detected.\n");
}

int main() {
    int max[P][R] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[P][R] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[R] = {3, 3, 4};
    detectDeadlock(max, allocation, available);
    return 0;
}
