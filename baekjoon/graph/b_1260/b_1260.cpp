#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

void dfs(int node) {
    visit[node] = true;
    printf("%d ", node);

    for (int next : graph[node]) {
        if (visit[next])
            continue;

        dfs(next);
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visit[node] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        printf("%d ", curr);

        for (int next : graph[curr]) {
            if (visit[next])
                continue;

            q.push(next);
            visit[next] = true;
        }

    }
}

int main()
{
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);

    visit.resize(n + 1);
    graph.resize(n + 1);

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 방문할 수 있는 정점이 여러 개인 경우, 정점 번호가 작은 것을 먼저 방문하기 위해 오름차순 정렬
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(start);
    printf("\n");

    fill(visit.begin(), visit.end(), false);
    bfs(start);
}
