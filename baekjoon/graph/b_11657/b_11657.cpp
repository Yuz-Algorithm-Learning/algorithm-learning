#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int n, m;

struct info {
    int start, end, time;
};
vector<info> edges;
vector<long long> dis;

bool bellmanFord() {
    dis.resize(n + 1, INF);
    dis[1] = 0;

    for(int i = 0; i < n; i++) {

        /* 간선 전체 탐색 */
        for(auto edge : edges) {
            if(dis[edge.start] == INF) continue;

            if(dis[edge.end] > dis[edge.start] + edge.time) {
                dis[edge.end] = dis[edge.start] + edge.time;

                /* n번 째 라운드에서 값이 갱신된다면 음수 순환 존재 */
                if(i == n - 1)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int s, e, t;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
    }

    if(bellmanFord())
        cout << "-1\n";
    else {
        for(int i = 2; i <= n; i++) {
            if(dis[i] == INF)
                cout << "-1\n";
            else
                cout << dis[i] << '\n';
        }
    }

    return 0;
}
