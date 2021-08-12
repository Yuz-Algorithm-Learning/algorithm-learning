#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>

#define INF 987654321

using namespace std;

struct comp {
    bool operator()(tuple<int, int, double> a, tuple<int, int, double> b) {
        return get<2>(a) > get<2>(b);
    }
};

bool comp_x(pair<int, double> a, pair<int, double> b) {
    return a.first < b.first;
}

int main()
{
    int N, F;
    scanf("%d %d", &N, &F);

    vector<vector<pair<int, double>>> map(F + 1);

    int x, y;
    map[0].emplace_back(0, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        map[y].emplace_back(x, INF);
    }
    for (int i = 0; i <= F; i++)
        sort(map[i].begin(), map[i].end());
    
    priority_queue<tuple<int, int, double>, vector<tuple<int, int, double>>, comp> pq;
    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        int curr_x = get<0>(pq.top());
        int curr_y = get<1>(pq.top());
        double dis = get<2>(pq.top());
        pq.pop();

        int idx = lower_bound(map[curr_y].begin(), map[curr_y].end(), make_pair( curr_x, dis ), comp_x) - map[curr_y].begin();
        if (dis < map[curr_y][idx].second)
            continue;

        for (int y = curr_y - 2; y <= curr_y + 2; y++) {
            if (y < 0 || y > F)
                continue;

            int min_idx = lower_bound(map[y].begin(), map[y].end(), pair<int, double>(curr_x - 2, 0)) - map[y].begin();
            int max_idx = upper_bound(map[y].begin(), map[y].end(), pair<int, double>(curr_x + 2, INF)) - map[y].begin();

            for (int x = min_idx; x < max_idx; x++) {
                if (map[y][x].first == curr_x && y == curr_y)
                    continue;

                double next_dis = sqrt(pow(curr_x - map[y][x].first, 2) + pow(curr_y - y, 2)) + dis;
                if (next_dis < map[y][x].second) {
                    map[y][x].second = next_dis;
                    pq.emplace(map[y][x].first, y, next_dis);
                }
            }
        }
    }

    double answer = INF;
    for (int i = 0; i < map[F].size(); i++) {
        if (answer > map[F][i].second)
            answer = map[F][i].second;
    }

    if (answer != INF)
        cout << round(answer);
    else
        cout << -1;
}