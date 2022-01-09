#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, m;
int start, _end;
vector<vector<pair<int, int>>> graph;
vector<int> store;
vector<int> point;

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
                store[neighbor] = cur;
            }
        }
    }

    return distance;

}

void point_vertex(int p) {
    point.push_back(p);

    if (p != start)
        point_vertex(store[p]);
}

int main()
{
    scanf("%d %d", &n, &m);
    graph.resize(n + 1);
    store.resize(n + 1, INF);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c); 
        graph[a].emplace_back(b, c);
    }

    scanf("%d %d", &start, &_end);

    vector<int> result = dijkstra(start, n + 1);
    
    point_vertex(_end);

    printf("%d\n", result[_end]);
    printf("%d\n", point.size());
    for (int i = point.size() - 1; i >= 0; i--)
        printf("%d ", point[i]);

}
