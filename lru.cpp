#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int pageFaultsLRU(int pages[], int n, int capacity) {
    unordered_map<int, list<int>::iterator> pageMap;
    list<int> lruList;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (pageMap.find(pages[i]) != pageMap.end())
            lruList.erase(pageMap[pages[i]]);
        else {
            faults++;
            if (lruList.size() >= capacity) {
                pageMap.erase(lruList.back());
                lruList.pop_back();
            }
        }
        lruList.push_front(pages[i]);
        pageMap[pages[i]] = lruList.begin();
    }

    return faults;
}

int main() {
    int pages[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    cout << pageFaultsLRU(pages, 10, 3);
    return 0;
}
