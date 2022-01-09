#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, V;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		if (distance[cur] < dis)
			continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int neighbor = graph[cur][i].first;
			int neighbor_dis = graph[cur][i].second + dis;

			if (distance[neighbor] > neighbor_dis) {
				distance[neighbor] = neighbor_dis;
				pq.emplace(neighbor_dis, neighbor);
			}
		}
	}

	return distance;
}

int main()
{
	scanf("%d %d", &N, &V);

	graph.resize(N + 1);

	int start;
	scanf("%d", &start);

	int u, v, w;
	for (int i = 0; i < V; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].emplace_back(v, w);
	}

	vector<int> result = dijkstra(start, N + 1);

	for (int i = 1; i <= N; i++) {
		if (result[i] != INF)
			printf("%d\n", result[i]);
		else
			printf("INF\n");
	}

}
