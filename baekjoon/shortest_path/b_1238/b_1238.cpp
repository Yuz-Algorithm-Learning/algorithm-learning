#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, m, x;
vector<vector<pair<int, int>>> graph;
vector<int> dis;

vector<int> dijkstra(int start) {
	vector<int> distance(n + 1, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = pq.top().first;
		pq.pop();
		
		if (distance[cur] < dis)
			continue;

		for (auto neighbor : graph[cur]) {
			int next = neighbor.first;
			int next_dis = neighbor.second + dis;

			if (distance[next] > next_dis) {
				distance[next] = next_dis;
				pq.emplace(next_dis, next);
			}
		}
	}

	return distance;
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	graph.resize(n + 1);

	int a, b, d;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &d);
		graph[a].emplace_back(b, d);
	}

	vector<int> xx = dijkstra(x);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;

		vector<int> s = dijkstra(i);
		result = max(result, s[x] + xx[i]);
	}

	printf("%d", result);
}


