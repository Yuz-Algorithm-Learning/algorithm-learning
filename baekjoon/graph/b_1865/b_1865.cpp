#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int tc, n, m, w;

struct edge {
    int start, end, time;
};

vector<edge> edges;

bool bellman_ford() {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {

        /* 간선 전체 탐색 */
        for (auto edge : edges) {

            if (dist[edge.end] > dist[edge.start] + edge.time) {
                dist[edge.end] = dist[edge.start] + edge.time;

                /* n번 째 라운드에서 값이 갱신된다면 음수 순환 존재 */
                if (i == n - 1)
                    return true;
            }


        }
    }

    return false;
}

int main()
{
    scanf("%d", &tc);

    while (tc--) {
        scanf("%d %d %d", &n, &m, &w);

        int s, e, t;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }
        for (int i = 0; i < w; i++) {
            scanf("%d %d %d", &s, &e, &t);
            edges.push_back({ s, e, -t });
        }

        (bellman_ford())? printf("YES\n") : printf("NO\n");

        edges.clear();
    }
}

