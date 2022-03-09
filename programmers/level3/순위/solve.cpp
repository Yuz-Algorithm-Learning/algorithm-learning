#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> player(n + 1, vector<bool>(n + 1, 0));
    for(int i = 0; i < results.size(); i++) {
        player[results[i][0]][results[i][1]] = true;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(i == k)
                continue;
            
            for(int j = 1; j <= n; j++) {
                if(j == k || i == j)
                    continue;
                
                if(player[i][k] && player[k][j])
                    player[i][j] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(player[i][j] || player[j][i]) {
                cnt++;
            }
        }
        
        if(cnt == n - 1)
            answer++;
    }
    return answer;
}