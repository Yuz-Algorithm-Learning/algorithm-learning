#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cstring>

#define MAX 987654321
#define TRASH 10

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int w, h;
int robot_y, robot_x, idx;
vector<string> room;
bool visited[20][20][1 << TRASH];
map<pair<int, int>, int> dirty;

struct point {
    int yy, xx, visit, dis;
};

int bfs() {
    int all_visit = (1 << dirty.size()) - 1;
    memset(visited, 0, sizeof(visited));

    queue<point> q;
    q.push({robot_y, robot_x, 0, 0});
    visited[robot_y][robot_x][0] = true;

    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int v = q.front().visit;
        int d = q.front().dis;
        q.pop();

        if(v == all_visit)
            return d;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nv = v;

            if(ny < 0 || ny >= h || nx < 0 || nx >= w || room[ny][nx] == 'x') continue;

            if(room[ny][nx] == '*') {
                nv = v | (1 << dirty[{ny, nx}]);
            }
            if(!visited[ny][nx][nv]) {
                visited[ny][nx][nv] = true;
                q.push({ny, nx, nv, d + 1});
            }

        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> w >> h;

        if(w == 0 && h == 0) break;

        room.resize(h);
        idx = 0;
        for(int i = 0; i < h; i++) {
            cin >> room[i];
            for(int j = 0; j < w; j++) {
                if(room[i][j] == 'o') {
                    robot_y = i;
                    robot_x = j;
                } else if(room[i][j] == '*') {
                    dirty[{i, j}] = idx++;
                }
            }
        }

        cout << bfs() << '\n';

        room.clear();
        dirty.clear();
    }
}