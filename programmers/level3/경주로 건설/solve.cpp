#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct point {
    int yy;
    int xx;
    int tt;
};

int solution(vector<vector<int>> board) {   // 0: -, 1: |
    int answer = 0;
    int n = board.size();
    vector<vector<pair<int, int>>> dis(n, vector<pair<int, int>>(n, {987654321, 987654321}));
    
    queue<point> q;
    dis[0][0].first = 0, dis[0][0].second = 0;
    q.push({0, 0, 0});
    q.push({0, 0, 1});
    
    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int type = q.front().tt;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            
            if(!board[ny][nx]) {
                if(!type) {
                   if(i == 0 || i == 2) {
                       if(dis[y][x].first + 100 < dis[ny][nx].first) {
                           dis[ny][nx].first = dis[y][x].first + 100; 
                           q.push({ny, nx, 0});
                       }
                   } else {
                       if(dis[y][x].first + 600 < dis[ny][nx].second) {
                           dis[ny][nx].second = dis[y][x].first + 600;
                           q.push({ny, nx, 1}); 
                       }
                   }
                } else {
                    if(i == 0 || i == 2) {
                        if(dis[y][x].second + 600 < dis[ny][nx].first) {
                            dis[ny][nx].first = dis[y][x].second + 600;
                            q.push({ny, nx, 0});
                        }
                    } else {
                        if(dis[y][x].second + 100 < dis[ny][nx].second) {
                            dis[ny][nx].second = dis[y][x].second + 100; 
                            q.push({ny, nx, 1});
                        }
                    } 
                }
                
            }
        }
    }
    
    answer = min(dis[n - 1][n - 1].first, dis[n - 1][n - 1].second);
    
    return answer;
}