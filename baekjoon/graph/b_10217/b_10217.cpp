#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 987654321;

struct point {
    int dd, cc, vv;
};

vector<vector<point>> graph;
int n, m, k;
int ans;

struct comp {
    bool operator()(point a, point b) {
        return a.dd > b.dd;
    }
};

void dijkstra(int start, int vertex) {
    vector<vector<int>> v_time(vertex, vector<int>(10001, INF));  /* 정점 번호, 사용한 비용 */
    priority_queue<point, vector<point>, comp> pq;
    pq.push({0, 0, start});
    v_time[1][0] = 0;

    while(!pq.empty()) {
        int cur = pq.top().vv;
        int cost = pq.top().cc;
        int time = pq.top().dd;
        pq.pop();

        if(cur == n) {
            ans = time;
            return;
        }

        if(v_time[cur][cost] < time)
            continue;
        
        for(auto next : graph[cur]) {
            int next_v = next.vv;
            int next_time = time + next.dd;
            int next_cost = cost + next.cc;

            if(next_cost > m)
                continue;

            if(next_time < v_time[next_v][next_cost]) {
                v_time[next_v][next_cost] = next_time;
                pq.push({next_time, next_cost, next_v});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while(t--) {
        cin >> n >> m >> k;
        ans = INF;
        graph.resize(n + 1);

        for(int i = 0; i < k; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            graph[u].push_back({d, c, v});
        }

        dijkstra(1, n + 1);

        if(ans == INF)
            cout << "Poor KCM\n";
        else
            cout << ans << '\n';
        
        graph.clear();
    }
}