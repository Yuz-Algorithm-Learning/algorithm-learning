#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<vector<int>> dp(money.size(), vector<int>(n + 1));
    
    for(int i = 0; i < n + 1; i++)
        dp[0][i] = (i % money[0] == 0)? 1 : 0;
    
    for(int i = 1; i < money.size(); i++) {
        for(int j = 0; j < n + 1; j++) {
            if(j - money[i] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - money[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[money.size() - 1][n] % 1000000007;
}