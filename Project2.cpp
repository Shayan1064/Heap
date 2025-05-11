#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++) {
        minHeap.push(a[i]);
        if(minHeap.size() > k)
            minHeap.pop();
    }

    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
