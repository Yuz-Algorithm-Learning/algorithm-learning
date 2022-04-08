#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    vector<int> dp(n + 2);
    for(int i = n; i >= 1; i--) {
        if(i + t[i] > n + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
        }
    }

    cout << dp[1] << '\n';
}