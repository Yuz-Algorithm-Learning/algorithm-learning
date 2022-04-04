#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

struct point {
    int yy;
    int xx;
    int dir;
};

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int w, h;
    cin >> w >> h;

    vector<string> map(h);
    vector<pair<int, int>> dir_c;
    for(int i = 0; i < h; i++) {
        cin >> map[i];
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 'C') {
                dir_c.emplace_back(i, j);
                map[i][j] = '.';
            }
        }
    }

    vector<vector<pair<int, int>>> mirr(h, vector<pair<int, int>>(w, {987654321, 987654321})); // 0: -, 1: |
    mirr[dir_c[0].first][dir_c[0].second].first = 0;
    mirr[dir_c[0].first][dir_c[0].second].second = 0;
    queue<point> q;
    for(int i = 0; i < 4; i++) {
        int ny = dir_c[0].first + dy[i];
        int nx = dir_c[0].second + dx[i];

        if(ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;

        if(map[ny][nx] == '.') {
            q.push({ny, nx, i});
            if(i == 0 || i == 2)
                mirr[ny][nx].first = 0;
            else
                mirr[ny][nx].second = 0;
        }
    }

    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int d = q.front().dir;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            
            if(map[ny][nx] == '.') {
                if(d == 0 || d == 2) {
                    if(i == 0 || i == 2) {
                        if(mirr[y][x].first < mirr[ny][nx].first) {
                            mirr[ny][nx].first = mirr[y][x].first;
                            q.push({ny, nx, i});
                        }
                    } else {
                        if(mirr[y][x].first + 1 < mirr[ny][nx].second) {
                            mirr[ny][nx].second = mirr[y][x].first + 1;
                            q.push({ny, nx, i});
                        }
                    }
                } else {
                    if(i == 0 || i == 2) {
                        if(mirr[y][x].second + 1 < mirr[ny][nx].first) {
                            mirr[ny][nx].first = mirr[y][x].second + 1;
                            q.push({ny, nx, i});
                        }
                    } else {
                        if(mirr[y][x].second < mirr[ny][nx].second) {
                            mirr[ny][nx].second = mirr[y][x].second;
                            q.push({ny, nx, i});
                        }
                    }
                }
            }

        }
    }

    cout << min(mirr[dir_c[1].first][dir_c[1].second].first, mirr[dir_c[1].first][dir_c[1].second].second) << '\n';
    return 0;
    
}