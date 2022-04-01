#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        (i % 2)? pq1.push(tmp) : pq2.push(tmp);
        int pq1_top = pq1.top();
        if(!pq2.empty()) {
            int pq2_top = pq2.top();
            if(pq1_top > pq2_top) {
                pq1.pop();
                pq2.pop();

                pq1.push(pq2_top);
                pq2.push(pq1_top);
            }
        }

        cout << pq1.top() << "\n";
    }
}