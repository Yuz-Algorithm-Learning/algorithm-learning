#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        vector<vector<int>> dp(k + 1, vector<int>(k + 1));
        vector<int> data(k + 1);
        vector<int> sum(k + 1);
        for(int i = 1; i <= k; i++) {
            cin >> data[i];
            sum[i] = sum[i - 1] + data[i];
        }

        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= k - i; j++) {
                dp[j][j + i] = 987654321;
                for(int m = j; m < i + j; m++) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][m] + dp[m + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][k] << '\n';

    }
}