#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int tmp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        pq.push(tmp);
    }

    int ans = 0;
    while (pq.size() != 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        ans += first + second;

        pq.push(first + second);
    }

    printf("%d", ans);
}