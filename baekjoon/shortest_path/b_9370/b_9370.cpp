#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, t;
int s, g, h;

vector<vector<pair<int, int>>> graph;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        graph.clear();
        graph.resize(n + 1);
        int gh_line = 0;
        for(int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            
            graph[a].emplace_back(b, d);
            graph[b].emplace_back(a, d);

            if((a == g && b == h) || (a == h && b == g))
                gh_line = d;
        }

        vector<int> start_to_end = dijkstra(s);
        vector<int> g_to_vertex = dijkstra(g);
        vector<int> h_to_vertex = dijkstra(h);

        vector<int> rst;
        for(int i = 0; i < t; i++) {
            int dest;
            cin >> dest;

            int sghd = min(g_to_vertex[s] + h_to_vertex[dest], g_to_vertex[dest] + h_to_vertex[s]);
            if(sghd + gh_line <= start_to_end[dest]) {
                rst.push_back(dest);
            }
        }

        sort(rst.begin(), rst.end());
        for(int i = 0; i < rst.size(); i++) {
            cout << rst[i] << " ";
        }
        cout << '\n';


    }
    
    return 0;
}