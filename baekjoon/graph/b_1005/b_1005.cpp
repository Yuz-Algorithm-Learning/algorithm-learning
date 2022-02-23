#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> b_time;
vector<vector<int>> info;
queue<int> build;

int bfs(int start) {
    vector<int> rst(n + 1);
    build.push(start);
    rst[start] = b_time[start];

    while(!build.empty()){
        int curr = build.front();
        build.pop();

        for(int next : info[curr]) {
            if(rst[next] < rst[curr] + b_time[next]) {
                rst[next] = rst[curr] + b_time[next];
                build.push(next);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ans < rst[i])
            ans = rst[i];
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        b_time.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &b_time[i]);
        }

        info.resize(n + 1);
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            info[b].push_back(a);
        }

        int end;
        scanf("%d", &end);

        printf("%d\n", bfs(end));

        b_time.clear();
        info.clear();
    }
}