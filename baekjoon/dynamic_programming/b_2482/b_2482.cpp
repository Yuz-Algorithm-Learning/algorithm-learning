#include <iostream>
#include <vector>
#define MOD 1000000003

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for(int i = 4; i <= n; i++) {
        for(int j = 2; j <= i / 2; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[n][k] % MOD << '\n';
    return 0;
}