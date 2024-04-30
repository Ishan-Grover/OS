#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> // Include the <algorithm> header

using namespace std;

int pageFaultsOptimal(int pages[], int n, int capacity) {
    unordered_map<int, int> nextUse;
    vector<int> memory;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        if (nextUse.find(pages[i]) == nextUse.end()) {
            // Page not in memory
            page_faults++;
            if (memory.size() >= capacity) {
                // Memory is full, evict page with the farthest next use
                int page_to_evict = -1;
                int farthest_next_use = -1;
                for (int j = 0; j < memory.size(); j++) {
                    if (nextUse.find(memory[j]) == nextUse.end()) {
                        // Page not used again, evict it
                        page_to_evict = memory[j];
                        break;
                    }
                    if (nextUse[memory[j]] > farthest_next_use) {
                        farthest_next_use = nextUse[memory[j]];
                        page_to_evict = memory[j];
                    }
                }
                // Remove the evicted page from memory
                memory.erase(std::remove_if(memory.begin(), memory.end(), [&](int page){ return page == page_to_evict; }), memory.end());
            }
            // Add new page to memory
            memory.push_back(pages[i]);
        }
        // Update next use of current page
        nextUse[pages[i]] = -1;
        for (int j = i + 1; j < n; j++) {
            if (pages[j] == pages[i]) {
                nextUse[pages[i]] = j;
                break;
            }
        }
    }

    return page_faults;
}

int main() {
    int pages[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    cout << pageFaultsOptimal(pages, n, capacity);
    return 0;
}
