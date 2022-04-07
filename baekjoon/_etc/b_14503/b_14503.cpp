#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main() {
    int n, m;
    cin >> n >> m;

    int robot_y, robot_x, dir;
    cin >> robot_y >> robot_x >> dir;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int idx = 0;
    int ans = 1;
    board[robot_y][robot_x] = 2;
    while(1) {
        if(dir == 0) {
            idx = 3;
        } else if(dir == 1) {
            idx = 0;
        } else if(dir == 2) {
            idx = 1;
        } else {
            idx = 2;
        }

        int tm = 0;
        while(tm < 4) {
            if(board[robot_y + dy[idx]][robot_x + dx[idx]] == 0) {
                robot_y += dy[idx];
                robot_x += dx[idx];
                board[robot_y][robot_x] = 2;
                dir = idx;
                ans++;
                break;
            }

            idx--;
            if(idx < 0) idx = 3;
            tm++;
        }

        if(tm == 4) {
            if(board[robot_y - dy[dir]][robot_x - dx[dir]] == 1) {
                break;
            } else {
                robot_y -= dy[dir];
                robot_x -= dx[dir];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}