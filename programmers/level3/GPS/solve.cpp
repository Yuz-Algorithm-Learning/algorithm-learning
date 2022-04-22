#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 987654321;
    
    vector<vector<int>> connected(n + 1);
    for(int i = 0; i < edge_list.size(); i++) {
        connected[edge_list[i][0]].push_back(edge_list[i][1]);
        connected[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    
    vector<vector<int>> dp(k, vector<int>(n + 1, 987654321));
    for(int num = 1; num <= n; num++) {
        if(num == gps_log[0]) {
            dp[0][num] = 0;
            break;
        }
    }
    
    for(int i = 1; i < k; i++) {
        for(int num = 1; num <= n; num++) {
            int curr = (num == gps_log[i])? 0 : 1;
            
            dp[i][num] = min(dp[i][num], dp[i - 1][num]);
            for(auto before : connected[num]) {
                dp[i][num] = min(dp[i][num], dp[i - 1][before]);
            }
            dp[i][num] += curr;
            
        }
    }
    
    if(dp[k - 1][gps_log[k - 1]] == 987654321) 
        return -1;
    else 
        return dp[k - 1][gps_log[k - 1]];
    
}