#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1000001][2];         /* 0: 얼리 아답터가 아님, 1: 얼리 아답터 */
bool visited[1000001];
vector<int> tree[1000001];

void select(int x) {
    visited[x] = true;
    dp[x][1] = 1;

    for(auto child : tree[x]) {
        if(visited[child])
            continue;
        
        select(child);

        dp[x][0] += dp[child][1];
        dp[x][1] += min(dp[child][0], dp[child][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    select(1);
    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}