#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF -987654321

using namespace std;

vector<pair<int, int>> transportation[101];
vector<int> n_info;
long long dist[101];
bool last_vertex[101];
bool visit[101];
int n, s, e, m;

void bellman_ford() {
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (dist[j] == INF)
                continue;

            for (auto child : transportation[j]) {
                if (dist[child.first] < dist[j] - child.second + n_info[child.first]) {
                    dist[child.first] = dist[j] - child.second + n_info[child.first];
                    
                    if (i == n - 1) {
                        last_vertex[j] = 1;
                    }
                }
            }

        }
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &s, &e, &m);

    int v1, v2, price;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &price);
        transportation[v1].emplace_back(v2, price);
    }
    fill(dist, dist + n, INF);
    
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        n_info.push_back(tmp);
    }
    dist[s] = n_info[s];

    bellman_ford();

    if (dist[e] == INF)
        printf("gg");
    else {
        
        /* 음의 사이클이 도착점을 포함해야 Gee */
        bool minus_cycle = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (last_vertex[i]) {
                visit[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == e) {
                minus_cycle = 1;
                break;
            }

            for (auto child : transportation[curr]) {
                if (!visit[child.first]) {
                    visit[child.first] = 1;
                    q.push(child.first);
                }
            }
        }

        if (minus_cycle)
            printf("Gee");
        else
            printf("%lld", dist[e]);
    }
        
}