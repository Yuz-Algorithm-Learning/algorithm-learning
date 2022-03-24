#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

struct point {
    int yy;
    int xx;
    int dis;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> map(102, vector<int>(102));

    // 모든 직사각형 표시
    for(int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        
        for(int p = y1 * 2; p <= y2 * 2; p++) {
            for(int q = x1 * 2; q <= x2 * 2; q++) {
                map[p][q] = 1;
            }
        }
    }

    // 만들어진 도형의 내부 삭제
    for(int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        
        for(int p = y1 * 2 + 1; p < y2 * 2; p++) {
            for(int q = x1 * 2 + 1; q < x2 * 2; q++) {
                map[p][q] = 0;
            }
        }
    }

    vector<vector<int>> map_dis(102, vector<int>(102, 987654321));
    queue<point> q;
    q.push({characterY * 2, characterX * 2, 0});
    
    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int d = q.front().dis;
        q.pop();
        
        if(y == (itemY * 2) && x == (itemX * 2)) {
            answer = d;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny <= 0 || ny > 100 || nx <= 0 || ny > 100)
                continue;
            
            if(map[ny][nx] == 1 && d + 1 < map_dis[ny][nx]) {
                map_dis[ny][nx] = d + 1;
                q.push({ny, nx, d + 1});
            }
            
        }
    }
    
    return answer / 2;
}