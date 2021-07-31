#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> order(N + 1);
    vector<int> entry(N + 1);
    int before, after;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &before, &after);
        order[before].push_back(after);
        entry[after]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (!entry[i])
            pq.push(i);
    }
	while (!pq.empty()) {
		int curr = pq.top();
		printf("%d ", curr);
        pq.pop();

        for (int i = 0; i < order[curr].size(); i++) {
            int next = order[curr][i];

            if (--entry[next] == 0)
                pq.push(next);
        }
	}
}