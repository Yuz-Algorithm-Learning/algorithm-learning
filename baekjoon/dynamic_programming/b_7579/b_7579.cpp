#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> mm(n + 1);
    vector<int> cc(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> mm[i];
    for(int i = 1; i <= n; i++)
        cin >> cc[i];
    
    int ans = 987654321;
    vector<vector<int>> dp(n + 1, vector<int>(100 * n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 100 * n; j++) {
            if(j < cc[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cc[i]] + mm[i]);
            }

            if(dp[i][j] >= m)
                ans = min(ans, j);
        } 
    }

    cout << ans << '\n';
    return 0;
}