#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<bool>> water(n + 1, vector<bool>(m + 1));
    for(int i = 0; i < puddles.size(); i++) {
        water[puddles[i][1]][puddles[i][0]] = true;
    }
    
    if(n < 2 || m < 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(water[i][j])
                    return 0;
            }
        }
        return 1;
    } 

    vector<vector<int>> dis(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        if(!water[i][1])
            dis[i][1] = 1;
        else
            break;
    }
    for(int i = 1; i <= m; i++) {
        if(!water[1][i])
            dis[1][i] = 1;
        else
            break;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(!water[i][j]) {
                int up = (!water[i - 1][j])? dis[i - 1][j] : 0;
                int left = (!water[i][j -1])? dis[i][j - 1] : 0;

                dis[i][j] = (up + left) % 1000000007;
            }
        }
    }
  
    return dis[n][m] % 1000000007;
}