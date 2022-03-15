#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 1;
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    
    // 길이 1
    for(int i = 0; i < s.size(); i++)
        dp[i][i] = 1;
    
    // 길이 2
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            answer = 2;
        }
    }
    
    // 길이 3 이상
    for(int k = 2; k < s.size(); k++) {
        for(int i = 0; i < s.size() - k; i++) {
            if(s[i] == s[i + k] && dp[i + 1][i + k - 1])  {
                dp[i][i + k] = 1;
                answer = max(answer, k + 1);
            }
        }
    }
    
    return answer;
}