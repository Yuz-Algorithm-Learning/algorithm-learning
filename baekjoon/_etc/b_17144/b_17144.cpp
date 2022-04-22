#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m;
vector<pair<int, int>> cleaner;
vector<vector<int>> board;

void back_rotate(int y, int x, int dir) {
    if(y == cleaner[0].first && x == cleaner[0].second + 1) {
        board[y][x] = 0;
        return;
    }

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(ny < 0 || ny > cleaner[0].first || nx < 0 || nx >= m) {
        dir = (dir == 3)? 0 : dir + 1;
        ny = y + dy[dir];
        nx = x + dx[dir];
    }

    board[y][x] = board[ny][nx];
    back_rotate(ny, nx, dir);
}

void go_rotate(int y, int x, int dir) {
    if(y == cleaner[1].first && x == cleaner[1].second + 1) {
        board[y][x] = 0;
        return;
    }

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(ny < cleaner[1].first || ny >= n || nx < 0 || nx >= m) {
        dir = (dir == 0)? 3 : dir - 1;
        ny = y + dy[dir];
        nx = x + dx[dir];
    }

    board[y][x] = board[ny][nx];
    go_rotate(ny, nx, dir);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> n >> m >> t;

    board.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];

            if(board[i][j] == -1) {
                cleaner.emplace_back(i, j);
            }
        }
    }

    while(t--) {
        vector<vector<int>> next_board(n, vector<int>(m));
        next_board[cleaner[0].first][cleaner[0].second] = -1;
        next_board[cleaner[1].first][cleaner[1].second] = -1;

        // 확산
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] > 0) {
                    int b_num = board[i][j];
                    int num = board[i][j] / 5;

                    for(int d = 0; d < 4; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];

                        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        
                        if(board[ny][nx] != -1) {
                            b_num -= num;
                            next_board[ny][nx] += num;
                        }
                    }

                    next_board[i][j] += b_num;
                }
            }
        }
        board = next_board;

        // 회전
        back_rotate(cleaner[0].first, cleaner[0].second, 3);
        board[cleaner[0].first][cleaner[0].second] = -1;

        go_rotate(cleaner[1].first, cleaner[1].second, 1);
        board[cleaner[1].first][cleaner[1].second] = -1;
    }

    // sum
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] > 0)
                sum += board[i][j];
        }
    }
    cout << sum << '\n';
}