#include<stdio.h>
#define NUM_PROCESSES 4

void swap(int *a, int *b);
void sort(int arr[], int n);
void compute_waiting_time(int wt[], int bt[], int n);
void compute_turnaround_time(int tt[], int wt[], int bt[], int n);
void print_results(int wt[], int tt[], int n);

int main() {
    int bt[NUM_PROCESSES] = {6, 8, 7, 3};
    int wt[NUM_PROCESSES];
    int tt[NUM_PROCESSES];

    // sort the burst times in ascending order
    sort(bt, NUM_PROCESSES);

    // calculate waiting time and turnaround time
    compute_waiting_time(wt, bt, NUM_PROCESSES);
    compute_turnaround_time(tt, wt, bt, NUM_PROCESSES);

    // print results
    print_results(wt, tt, NUM_PROCESSES);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void compute_waiting_time(int wt[], int bt[], int n) {
    wt[0] = 0;
    int total_wt = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];
        total_wt += wt[i];
    }
}

void compute_turnaround_time(int tt[], int wt[], int bt[], int n) {
    for (int i = 0; i < n; i++) {
        tt[i] = bt[i] + wt[i];
    }
}

void print_results(int wt[], int tt[], int n,int bt[]) {
    float avg_wt = 0.0, avg_tt = 0.0;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tt[i]);
        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nAverage waiting time = %f", avg_wt);
    printf("\nAverage turnaround time = %f\n", avg_tt);
}
