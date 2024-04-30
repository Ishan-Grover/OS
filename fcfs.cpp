#include <iostream>
using namespace std;
int main() {
    int n, burst_time[20], arrival_time[20], wait_time[20], turn_around_time[20];
    float avg_wait_time = 0, avg_turnaround_time = 0;
    // Prompt user to input the total number of processes
    cout << "Enter the total number of processes(Maximum:20): ";
    cin >> n;
    // Get burst time and arrival time for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter Process Burst Time for P[" << i + 1 << "]: ";
        cin >> burst_time[i];
        cout << "Enter Process Arrival Time for P[" << i + 1 << "]: ";
        cin >> arrival_time[i];
    }
    // Sort processes based on arrival time using Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_time[j] > arrival_time[j + 1]) {
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]); // Maintain corresponding burst times
            }
        }
    }
    // Calculate wait time for each process
    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        int current_time = max(arrival_time[i], wait_time[i - 1] + burst_time[i - 1]);
        wait_time[i] = current_time - arrival_time[i];
    }
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = wait_time[i] + burst_time[i];
    }
    // Calculate average waiting time and average turnaround time
    for (int i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turn_around_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    // Print the results
    cout << "Process Burst Time  Arrival Time  Wait Time  Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]\t\t" << burst_time[i] << "\t\t" << arrival_time[i]
             << "\t\t" << wait_time[i] << "\t\t" << turn_around_time[i] << endl;
    }
    cout << "\nAverage Waiting Time: " << avg_wait_time;
    cout << "\nAverage Turnaround Time: " << avg_turnaround_time;
    return 0;
}
