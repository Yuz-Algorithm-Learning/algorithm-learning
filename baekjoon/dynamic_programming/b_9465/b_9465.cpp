#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<vector<int>> sticker(2, vector<int>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &sticker[i][j]);
            }
        }

        vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(n));
        dp[0][0].first = dp[1][0].first = 0;
        dp[0][0].second = sticker[0][0];
        dp[1][0].second = sticker[1][0];

        for (int i = 1; i < n; i++) {
            int max_zero = max(dp[0][i - 1].first, dp[0][i - 1].second);
            int max_one = max(dp[1][i - 1].first, dp[1][i - 1].second);

            dp[0][i].first = dp[1][i].first = max(max_zero, max_one);
            dp[0][i].second = max(dp[0][i - 1].first, max_one) + sticker[0][i];
            dp[1][i].second = max(dp[1][i - 1].first, max_zero) + sticker[1][i];
        }

        int result = max({ dp[0][n - 1].first, dp[0][n - 1].second, dp[1][n - 1].first, dp[1][n - 1].second });
        printf("%d\n", result);

    }
}
