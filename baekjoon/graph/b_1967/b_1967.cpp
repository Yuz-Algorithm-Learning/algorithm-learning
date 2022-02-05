#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visit;
int result = 0;
int point = 0;

void dfs(int x, int len) {
    visit[x] = true;

    if (result < len) {
        result = len;
        point = x;
    }

    for (auto neighbor : tree[x]) {
        if(!visit[neighbor.first])
            dfs(neighbor.first, len + neighbor.second);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    tree.resize(n + 1);
    visit.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);

        tree[a].emplace_back(b, d);
        tree[b].emplace_back(a, d);
    }

    dfs(1, 0);

    result = 0;
    fill(visit.begin(), visit.end(), false);
    dfs(point, 0);
    printf("%d", result);
}
