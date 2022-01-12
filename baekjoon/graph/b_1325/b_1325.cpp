#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

int dfs(int node) {

    int depth = 0;
    visit[node] = true;

    for (int next : graph[node]) {
        if (visit[next])
            continue;

        depth += dfs(next);
    }

    return depth + 1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    graph.resize(n + 1);
    visit.resize(n + 1);
    
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);

        graph[b].push_back(a);
    }

    int max_num = 0;
    vector<int> result;
    for (int i = 1; i <= n; i++) {

        fill(visit.begin(), visit.end(), false);
        int tmp = dfs(i);

        if (max_num == tmp)
            result.push_back(i);
        else if (max_num < tmp) {
            max_num = tmp;
            result.clear();
            result.push_back(i);
        }

    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        printf("%d ", result[i]);
    
}
