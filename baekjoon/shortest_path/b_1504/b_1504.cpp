#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 801;
const int INF = 987654321;

int N, M;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int dis = pq.top().second;
		pq.pop();

		if (distance[cur] < dis) {
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int neighbor = graph[cur][i].first;
			int neighbor_distance = graph[cur][i].second + dis;

			if (distance[neighbor] > neighbor_distance) {
				distance[neighbor] = neighbor_distance;
				pq.push({ neighbor, neighbor_distance });
			}
		}
	}

	return distance;
}

int main() {
	
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		// 양방향
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int node1, node2;
	cin >> node1 >> node2;

	vector<int> result = dijkstra(1, N+1);
	vector<int> tmp1 = dijkstra(node1, N + 1);
	vector<int> tmp2 = dijkstra(node2, N + 1);

	int answer = min(result[node1] + tmp1[node2] + tmp2[N], result[node2] + tmp2[node1] + tmp1[N]);

	if (answer >= INF || answer < 0)
		cout << -1;
	else
		cout << answer;

	return 0;
}
