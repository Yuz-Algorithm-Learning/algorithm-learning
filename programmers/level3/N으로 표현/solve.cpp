#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/* add, sub, mul, div */
int cal(int a, int b, int type) {
    if(type == 0)
        return a + b;
    else if (type == 1)
        return a - b;
    else if (type == 2)
        return a * b;
    else {
        if(b != 0)
            return a / b;
    }
    return 0;
}

int solution(int N, int number) {
    int answer = 0;
    
    vector<vector<int>> dp(9);
    
    if(N == number)
        return 1;
    dp[1].push_back(N);

    dp[2].push_back(10 * N + N);
    for(int c = 0; c < 4; c++) {
        dp[2].push_back(cal(N, N, c));
    }
    for(int i = 0; i < dp[2].size(); i++) {
        if(dp[2][i] == number)
            return 2;
    }
    
    int idx = 3;
    while(idx < 9) {
        dp[idx].push_back(stoi(to_string(dp[1][0]) + to_string(dp[idx - 1][0])));
        if(dp[idx][0] == number)
            return idx;
        
        for(int i = 1; i < idx; i++) {
            
            for(int p = 0; p < dp[i].size(); p++) {
                int num1 = dp[i][p];
                unordered_map<int, bool> visit;
                for(int q = 0; q < dp[idx - i].size(); q++) {
                    
                    for(int c = 0; c < 4; c++) {
                        int tmp = cal(num1, dp[idx - i][q], c);
                        if(tmp == number)
                            return idx;
                        
                        if(!visit[tmp]) {
                            visit[tmp] = true;
                            dp[idx].push_back(tmp);
                        }
                    }

                }   
            }
        }
        
        idx++;
    }
    
    return -1;
}