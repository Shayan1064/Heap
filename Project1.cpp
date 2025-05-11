#include <iostream>
#include <vector>
using namespace std;

struct Patient {
    string name;
    int severity;
};

void heapify(vector<Patient> &pq, int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if(l < n && pq[l].severity > pq[largest].severity) largest = l;
    if(r < n && pq[r].severity > pq[largest].severity) largest = r;

    if(largest != i) {
        swap(pq[i], pq[largest]);
        heapify(pq, n, largest);
    }
}

void buildHeap(vector<Patient> &pq) {
    for(int i = pq.size()/2 - 1; i >= 0; i--)
        heapify(pq, pq.size(), i);
}

void insert(vector<Patient> &pq, Patient p) {
    pq.push_back(p);
    int i = pq.size() - 1;
    while(i != 0 && pq[(i-1)/2].severity < pq[i].severity) {
        swap(pq[i], pq[(i-1)/2]);
        i = (i-1)/2;
    }
}

void servePatient(vector<Patient> &pq) {
    if(pq.empty()) {
        cout << "No patients.\n";
        return;
    }
    cout << "Serving: " << pq[0].name << " (Severity: " << pq[0].severity << ")\n";
    pq[0] = pq.back();
    pq.pop_back();
    heapify(pq, pq.size(), 0);
}

int main() {
    vector<Patient> pq;
    insert(pq, {"Alice", 2});
    insert(pq, {"Bob", 5});
    insert(pq, {"Charlie", 1});
    insert(pq, {"David", 4});

    for(int i = 0; i < 4; i++)
        servePatient(pq);

    return 0;
}
