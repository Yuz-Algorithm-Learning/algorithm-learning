#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct coord {
    int sy, sx;
    int ey, ex;
};

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int by, bx;

int bfs(coord a, coord b) {
    vector<vector<int>> visited(by + 1, vector<int>(bx + 1, -1));
    queue<pair<int, int>> q;
    q.emplace(a.sy, a.sx);

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == a.ey && x == a.ex)
            break;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny > by || nx < 0 || nx > bx 
            || (ny == a.sy && nx == a.sx) || (ny == b.sy && nx == b.sx) || (ny == b.ey && nx == b.ex))
                continue;
            
            if(visited[ny][nx] == -1) {
                visited[ny][nx] = i;
                q.emplace(ny, nx);
            }
        }
    }

    vector<vector<int>> lines(by + 1, vector<int>(bx + 1));
    int y = a.ey, x = a.ex, dir = visited[y][x];
    lines[y][x] = 1;

    int cnt = 0;
    while(1) {
        if(y == a.sy && x == a.sx) break;

        if(dir == 0) x--;
        else if(dir == 1) y--;
        else if(dir == 2) x++;
        else y++;

        dir = visited[y][x];
        lines[y][x] = 1;
        cnt++;
    }

    queue<pair<int, int>> q2;
    q2.emplace(b.sy, b.sx);

    bool is_line = false;
    while(!q2.empty()) {
        int y = q2.front().first;
        int x = q2.front().second;
        q2.pop();

        if(y == b.ey && x == b.ex) {
            is_line = true;
            cnt += lines[y][x];
            break;
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny > by || nx < 0 || nx > bx || (ny == b.sy && nx == b.sx))
                continue;
            
            if(!lines[ny][nx]) {
                lines[ny][nx] = lines[y][x] + 1;
                q2.emplace(ny, nx);
            }
        }
    } 

    return (is_line)? cnt : INF; 
}

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> bx >> by;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    int ans1 = bfs({y1, x1, y2, x2}, {y3, x3, y4, x4});
    int ans2 = bfs({y3, x3, y4, x4}, {y1, x1, y2, x2});

    if(ans1 == INF && ans2 == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << min(ans1, ans2) << '\n';

    return 0;
}