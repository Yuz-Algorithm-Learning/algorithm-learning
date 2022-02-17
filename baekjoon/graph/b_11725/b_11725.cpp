#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> tree(n + 1);
    vector<int> root(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    root[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : tree[curr]) {
            if (root[next])
                continue;

            q.push(next);
            root[next] = curr;
        }
        
    }

    for (int i = 2; i <= n; i++)
        printf("%d\n", root[i]);
}
