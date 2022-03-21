#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;
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

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    graph.resize(n + 1);
    for(int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]].emplace_back(fares[i][1], fares[i][2]);
        graph[fares[i][1]].emplace_back(fares[i][0], fares[i][2]);
    }
    
    vector<int> start = dijkstra(s, n + 1);
    vector<int> aa = dijkstra(a, n + 1);
    vector<int> bb = dijkstra(b, n + 1);
    
    for(int i = 1; i <= n; i++) {
        if(start[i] == INF || aa[i] == INF || bb[i] == INF)
            continue;
        
        answer = min(answer, start[i] + aa[i] + bb[i]);
    }

    return answer;
}