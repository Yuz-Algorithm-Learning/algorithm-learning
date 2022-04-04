#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m;
vector<string> board;
bool visited[10][10][10][10] = {0,};

struct point {
    int ry, rx, by, bx, mv;
};

bool move(int &y, int &x, int dir) {
    int ny = y, nx = x;
    
    while(1) {
        ny += dy[dir];
        nx += dx[dir];

        if(board[ny][nx] != '.') {
            if(board[ny][nx] == 'O') {
                return true;
            }
            ny -= dy[dir];
            nx -= dx[dir];
            break;
        }
    }

    y = ny, x = nx;
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n >> m;

    board.resize(n);
    pair<int, int> r, b, o;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'R') {
                r.first = i, r.second = j;
                board[i][j] = '.';
            } else if(board[i][j] == 'B') {
                b.first = i, b.second = j;
                board[i][j] = '.';
            } else if(board[i][j] == 'O')
                o.first = i, o.second = j;
        }
    }

    queue<point> q;
    q.push({r.first, r.second, b.first, b.second, 0});
    visited[r.first][r.second][b.first][b.second] = 1;

    while(!q.empty()) {
        int r_y = q.front().ry;
        int r_x = q.front().rx;
        int b_y = q.front().by;
        int b_x = q.front().bx;
        int num = q.front().mv;
        q.pop();

        if(num == 10) {
            cout << -1 << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int r_ny = r_y;
            int r_nx = r_x;
            int b_ny = b_y;
            int b_nx = b_x;
            
            if(move(b_ny, b_nx, i)) continue;
            if(move(r_ny, r_nx, i)) {
                cout << num + 1 << '\n';
                return 0;
            }

            if(i == 0 || i == 2) {
                if(r_y == b_y) {
                    if((i == 0 && r_x < b_x) || (i == 2 && r_x > b_x)) {
                        if(r_nx == b_nx)
                            r_nx -= dx[i];
                    } else {
                        if(r_nx == b_nx)
                            b_nx -= dx[i];
                    }
                }
            } else {
                if(r_x == b_x) {
                    if((i == 1 && r_y < b_y) || (i == 3 && r_y > b_y)) {
                        if(r_ny == b_ny)
                            r_ny -= dy[i];
                    } else {
                        if(r_ny == b_ny)
                            b_ny -= dy[i];
                    }
                }
            }
            
            if(!visited[r_ny][r_nx][b_ny][b_nx]) {
                visited[r_ny][r_nx][b_ny][b_nx] = true;
                q.push({r_ny, r_nx, b_ny, b_nx, num + 1});
            }

        }
    }

    cout << -1 << '\n';
}