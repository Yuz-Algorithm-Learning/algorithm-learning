#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

vector<vector<int>> board;

struct point {
    int yy;
    int xx;
    int dis;
};

point bfs(int y1, int x1, int type) {
    
    queue<point> q;
    q.push({y1, x1, 0});
    
    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int d = q.front().dis;
        q.pop();
        
        if(board[y][x] == type) {
            return {y, x, d};
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
                continue;
            q.push({ny, nx, d + 1});
            
            while(1) {
                if(ny >= 0 && nx >= 0 && ny < 4 && nx < 4) {
                    if(board[ny][nx] != 0)
                        break;

                    ny += dy[i];
                    nx += dx[i];

                    if(ny < 0 || nx < 0 || ny > 3 || nx > 3) {
                        ny -= dy[i];
                        nx -= dx[i];
                        break;
                    }
                }

            }
            q.push({ny, nx, d + 1});

        }
        
    }
    
}

int solution(vector<vector<int>> b, int r, int c) {
    int answer = 987654321;
    board = b;
    
    int max_num = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(max_num < board[i][j])
                max_num = board[i][j];
        }
    }
    
    vector<int> ch;
    for(int i = 1; i <= max_num; i++)
        ch.push_back(i);
    
    do {
        
        board = b;
        int curr_y = r;
        int curr_x = c;
        int ans = 0;
        
        for(int i = 0; i < ch.size(); i++) {
            point p1 = bfs(curr_y, curr_x, ch[i]);
            curr_y = p1.yy, curr_x = p1.xx;
            board[curr_y][curr_x] = 0;

            point p2 = bfs(curr_y, curr_x, ch[i]);
            curr_y = p2.yy, curr_x = p2.xx;
            board[curr_y][curr_x] = 0;
            
            ans += p1.dis + p2.dis + 2;
        }
        
        answer = min(answer, ans);
        
    } while(next_permutation(ch.begin(), ch.end()));
    
    return answer;
}