#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int id = 0;
vector<int> visit;
vector<bool> finished;
vector<vector<int>> graph;
vector<vector<int>> SCC;
stack<int> s;

int dfs(int v) {
    visit[v] = ++id; 
    s.push(v);      

    int parent = visit[v];
    for (int i = 0; i < graph[v].size(); i++) {
        int next_v = graph[v][i];

        if (visit[next_v] == 0)
            parent = min(parent, dfs(next_v));
        else if (!finished[next_v])
            parent = min(parent, visit[next_v]);
    }

    if (parent == visit[v]) {
        vector <int> scc;

        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = 1;

            if (t == v) break;
        }
        SCC.push_back(scc);
    }

    return parent; 
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    graph.resize(V + 1);
    visit.resize(V + 1);
    finished.resize(V + 1);

    int v1, v2;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
    }

    for (int i = 1; i <= V; i++) {
        if (visit[i] == 0)
            dfs(i);
    }

    printf("%d\n", SCC.size());
    
    for(int i = 0; i < SCC.size(); i++)
        sort(SCC[i].begin(), SCC[i].end());
    sort(SCC.begin(), SCC.end());

    for (int i = 0; i < SCC.size(); i++) {
        for (int j = 0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("-1\n");
    }
}