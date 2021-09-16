#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> parent;

int same_root(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = same_root(parent[node]);
}

void union_root(int node1, int node2) {
    node1 = same_root(node1);
    node2 = same_root(node2);

    if (node1 != node2)
        parent[node2] = node1;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    parent.resize(V + 1);
    int a, b, cost;
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &cost);
        graph.push_back({ cost, {a, b} });
    }
    sort(graph.begin(), graph.end());

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    vector<pair<int, pair<int, int>>> mst;
    for (int i = 0; i < E; i++) {
        int v1 = graph[i].second.first;
        int v2 = graph[i].second.second;

        if (same_root(v1) == same_root(v2))
            continue;

        mst.push_back(graph[i]);
        union_root(v1, v2);

        if (mst.size() == V - 1)
            break;
    }

    int sum = 0;
    for (int i = 0; i < mst.size(); i++)
        sum += mst[i].first;

    printf("%d", sum);
}
