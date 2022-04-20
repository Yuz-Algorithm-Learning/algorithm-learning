#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {1, 0, 0, -1};
const int dx[] = {0, 1, -1, 0};
const int INF = 987654321;

struct info {
    int yy, xx, dd;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int mirror[51][51][4];
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            for(int p = 0; p < 4; p++) {
                mirror[i][j][p] = INF;
            }
        }
    }

    int n;
    cin >> n;
    vector<vector<char>> home(n, vector<char>(n));
    vector<pair<int, int>> door;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < str.size(); j++) {
            home[i][j] = str[j];

            if(home[i][j] == '#')
                door.emplace_back(i, j);
        }
    }

    queue<info> q;
    for(int i = 0; i < 4; i++) {
        int ny = door[0].first + dy[i];
        int nx = door[0].second + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        
        if(home[ny][nx] != '*') {
            mirror[ny][nx][i] = 0;
            q.push({ny, nx, i});
        }
    }

    while(!q.empty()) {
        int y = q.front().yy;
        int x = q.front().xx;
        int dir = q.front().dd;
        q.pop();

        if(home[y][x] == '.') {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if(home[ny][nx] != '*' && mirror[y][x][dir] < mirror[ny][nx][dir]) {
                mirror[ny][nx][dir] = mirror[y][x][dir];
                q.push({ny, nx, dir});
            }
        } else if(home[y][x] == '!') {
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                if(dir == i) {
                    if(home[ny][nx] != '*' && mirror[y][x][dir] < mirror[ny][nx][i]) {
                        mirror[ny][nx][i] = mirror[y][x][dir];
                        q.push({ny, nx, i});
                    }
                } else if(i != (3 - dir)) {
                    if(home[ny][nx] != '*' && mirror[y][x][dir] + 1 < mirror[ny][nx][i]) {
                        mirror[ny][nx][i] = mirror[y][x][dir] + 1;
                        q.push({ny, nx, i});
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 4; i++) {
        ans = min(ans, mirror[door[1].first][door[1].second][i]);
    }
    cout << ans << '\n';

}