#include <stdio.h>
int main() {
    int available[] = {3, 2, 1};  // Available resources
    int request[] = {1, 0, 2};   // Resource request
    int need[2][3] = {  // Process needs (assuming 2 processes)
        {2, 1, 1},
        {1, 0, 2}
    };
    int allocation[2][3] = {  // Currently allocated resources
        {1, 0, 0},
        {0, 1, 1}
    };
    // Check if request is valid (within Need)
    for (int i = 0; i < 3; i++) {
        if (request[i] > need[1][i]) {  // Assuming request for process 1 (index 1)
            printf("Error: Process exceeds its maximum claim.\n");
            return 1; // Error
        }
    }
    // Check if resources are available
    for (int i = 0; i < 3; i++) {
        if (request[i] > available[i]) {
            printf("Process must wait, resources are not available.\n");
            return 1; // Wait
        }
    }
    // Simulate allocation (assuming safety check is not required for simplicity)
    for (int i = 0; i < 3; i++) {
        available[i] -= request[i];
        allocation[1][i] += request[i];
    }
    printf("Resources allocated successfully.\n");
    return 0; // Success
}
