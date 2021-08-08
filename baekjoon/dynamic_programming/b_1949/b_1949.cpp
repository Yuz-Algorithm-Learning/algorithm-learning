#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> residents;
vector<int> visit;
vector<vector<int>> path;
int dp[10001][2];

void best_village(int node) {
    visit[node] = true;
    dp[node][0] = 0;
    dp[node][1] = residents[node];

    for (int next : path[node]) {
        if (visit[next])
            continue;

        best_village(next);

        dp[node][0] += max(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    residents.resize(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%d", &residents[i]);
    
    visit.resize(N + 1);

    int a, b;
    path.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a, &b);
        
        path[a].push_back(b);
        path[b].push_back(a);
    }

    best_village(1);

    printf("%d", max(dp[1][0], dp[1][1]));
}