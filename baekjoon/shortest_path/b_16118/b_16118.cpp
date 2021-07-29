#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX = 4001;
const int INF = 2000000000;

vector<pair<int, int>> graph[MAX];
int d_fox[MAX];
double d_wolf[MAX][2];

struct f_comp {   /* second 기준으로 오름차순 정렬 */
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
struct w_comp {
    bool operator()(tuple<int, double, bool> a, tuple<int, double, bool> b) {
        return get<1>(a) > get<1>(b);
    }
};

void fox_dijkstra(int start) {
    d_fox[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, f_comp> fox_pq;
    fox_pq.emplace(start, 0);

    while (!fox_pq.empty()) {
        int curr = fox_pq.top().first;
        int dis = fox_pq.top().second;
        fox_pq.pop();

        if (d_fox[curr] < dis)
            continue;

        for (int i = 0; i < graph[curr].size(); i++) {
            int neighbor = graph[curr][i].first;
            int neighbor_dis = graph[curr][i].second + dis;

            if (neighbor_dis < d_fox[neighbor]) {
                d_fox[neighbor] = neighbor_dis;
                fox_pq.emplace(neighbor, neighbor_dis);
            }
        }
    }
}

void wolf_dijkstra(int start) {
    d_wolf[start][0] = 0;
    //d_wolf[start][1] = 0;  /* 요놈때문에 애먹음,, */

    priority_queue<tuple<int, double, bool>, vector<tuple<int, double, bool>>, w_comp> wolf_pq;
    wolf_pq.emplace(start, 0, 0);

    while (!wolf_pq.empty()) {
        int curr = get<0>(wolf_pq.top());
        double dis = get<1>(wolf_pq.top());
        bool typ = get<2>(wolf_pq.top());
        wolf_pq.pop();

        if (d_wolf[curr][typ] < dis)
            continue;

        for (int i = 0; i < graph[curr].size(); i++) {
            int neighbor;
            double neighbor_dis;
            bool type;

            if (typ == 0) {
                neighbor = graph[curr][i].first;
                neighbor_dis = (double)graph[curr][i].second / 2 + dis;
                type = 1;
            }
            else {
                neighbor = graph[curr][i].first;
                neighbor_dis = (double)graph[curr][i].second * 2 + dis;
                type = 0;
            }

            if (neighbor_dis < d_wolf[neighbor][type]) {
                d_wolf[neighbor][type] = neighbor_dis;
                wolf_pq.emplace(neighbor, neighbor_dis, type);
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int a, b, d;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &d);

        graph[a].emplace_back(b, d);
        graph[b].emplace_back(a, d);
    }

    fill(d_fox, d_fox + MAX, INF);
    fill(&d_wolf[0][0], &d_wolf[MAX - 1][2], INF);

    fox_dijkstra(1);
    wolf_dijkstra(1);

    int rst = 0;
    for (int i = 1; i <= N; i++) {
        if (d_fox[i] < min(d_wolf[i][0], d_wolf[i][1]))
            rst++;
    }

    printf("%d", rst);
}