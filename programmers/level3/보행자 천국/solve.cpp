#include <vector>
#include <algorithm>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    vector<vector<pair<int, int>>> v(m, vector<pair<int, int>>(n));
    
    for(int j = 1; j < n; j++) {
        if(city_map[0][j] == 1)
            break;
        v[0][j].first = 1;
    }
    for(int i = 1; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        v[i][0].second = 1;
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(city_map[i][j] != 1) {
                v[i][j].first += v[i][j - 1].first;
                v[i][j].second += v[i - 1][j].second;
                
                if(city_map[i][j - 1] == 0) v[i][j].first += v[i][j - 1].second;
                if(city_map[i - 1][j] == 0) v[i][j].second += v[i - 1][j].first;
            
                v[i][j].first %= MOD;
                v[i][j].second %= MOD;
            }
        }
    }

    return (v[m - 1][n - 1].first + v[m - 1][n - 1].second) % MOD;
}