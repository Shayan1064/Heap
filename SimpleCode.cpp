#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &heap, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && heap[l] > heap[largest])
        largest = l;
    if(r < n && heap[r] > heap[largest])
        largest = r;

    if(largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void buildHeap(vector<int> &heap) {
    int n = heap.size();
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

void printHeap(const vector<int> &heap) {
    for(int x : heap)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> heap(n);
    for(int i = 0; i < n; i++) cin >> heap[i];

    buildHeap(heap);
    printHeap(heap);
    return 0;
}
