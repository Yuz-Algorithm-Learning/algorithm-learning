#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_dun = 0;
vector<vector<int>> dun;
vector<bool> visit;

void dfs(int tired, int cnt) {
    for(int i = 0; i < dun.size(); i++) {
        if(!visit[i] && dun[i][0] <= tired) {
            visit[i] = true;
            dfs(tired - dun[i][1], cnt + 1);
            visit[i] = false;
        }
    }
    max_dun = max(max_dun, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    dun = dungeons;
    visit.resize(dungeons.size());
    
    dfs(k, 0);
    
    return max_dun;
}