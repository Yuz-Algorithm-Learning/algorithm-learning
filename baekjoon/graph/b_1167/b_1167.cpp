#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, start, _end;
int max_dis;
vector<vector<pair<int, int>>> tree;
vector<bool> visit;

void dfs(int node, int dis) {
    visit[node] = true;

    if (max_dis < dis) {
        max_dis = dis;
        _end = node;
    }

    for (auto next : tree[node]) {
        int next_node = next.first;
        int next_dis = next.second;

        if (visit[next_node])
            continue;

        dfs(next_node, dis + next_dis);
    }

}

int main()
{
    scanf("%d", &n);
    tree.resize(n + 1);
    visit.resize(n + 1);

    for (int i = 0; i < n; i++) {
        int v1;

        scanf("%d", &v1);
        while (1) {
            int v2, d;
            scanf("%d", &v2);
            
            if (v2 == -1)
                break;

            scanf("%d", &d);
            tree[v1].emplace_back(v2, d);
        }

        if (tree[v1].size() == 1)
            start = v1;

    }

    dfs(start, 0);
    fill(visit.begin(), visit.end(), false);
    dfs(_end, 0);

    printf("%d", max_dis);
}
