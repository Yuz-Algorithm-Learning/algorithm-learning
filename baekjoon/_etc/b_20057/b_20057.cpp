#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
int n;
vector<vector<int>> board;
int total = 0;

int r_dy[4][9] = {
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {1, 1, 0, 0, 0, 0, -1, -1, -2}
};

int r_dx[4][9] = {
    {1, 1, 0, 0, 0, 0, -1, -1, -2},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0}
};

int p[] = {1, 1, 7, 7, 2, 2, 10, 10, 5};

// y 기준
void spread(int sy, int sx, int dir) {
    int use = 0;
    
    for(int i = 0; i < 9; i++) {
        int ny = sy + r_dy[dir][i];
        int nx = sx + r_dx[dir][i];
        int sp = board[sy][sx] * p[i] / 100;

        use += sp;

        if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
            total += sp;
            continue;
        }

        board[ny][nx] += sp;
    }

    int ny = sy + dy[dir];
    int nx = sx + dx[dir];
    if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
        total += (board[sy][sx] - use);
        return;
    }

    board[ny][nx] += (board[sy][sx] - use);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    board.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int curr_y = n / 2, curr_x = n / 2;
    int num = 1, cnt = 0; 
    int dir = 0;
    
    while(1) {
        if(curr_x < 0) break;
        if(cnt == 2) {
            num++;
            cnt = 0;
        }

        int line = num;
        while(line--) {
            curr_y += dy[dir];
            curr_x += dx[dir];
            spread(curr_y, curr_x, dir);
        }

        dir = (dir == 3)? 0 : dir + 1;
        cnt++;
    }

    cout << total << '\n';
    return 0;

}