#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visit[100001] = { 0 }, root[100001] = { 0 };

int dfs(vector<vector<int>> &path, int node) {

    int depth = 0;
    visit[node] = 1;

    for (int next : path[node]) {
        if (visit[next])
            continue;

        depth = dfs(path, next);
        root[node] = max(root[node], depth);
    }

    return max(root[node], depth) + 1;
}

int main()
{
    int N, S, D;
    int x, y;

    scanf("%d %d %d", &N, &S, &D);

    vector<vector<int>> path(N + 1);

    for (int i = 1; i < N; i++) {
        scanf("%d %d", &x, &y);

        path[x].push_back(y);
        path[y].push_back(x);
    }

    dfs(path, S);

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (i != S && root[i] >= D)
            result += 1;
    }

    cout << result * 2;
}
