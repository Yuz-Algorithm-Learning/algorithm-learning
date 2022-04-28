#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
vector<vector<int>> board;
vector<int> dice = {6, 5, 1, 2, 4, 3};    /* 아래(0), 앞(1), 위(2), 뒤(3), 왼쪽(4), 오른쪽(5) */
int n, m, k;

void dice_rotate(int type) {
    vector<int> tmp_dice = dice;

    if(type == 0) {         // 오른쪽으로
        tmp_dice[0] = dice[5];
        tmp_dice[4] = dice[0];
        tmp_dice[2] = 7 - tmp_dice[0];
        tmp_dice[5] = 7 - tmp_dice[4];
    } else if(type == 1) {  // 앞으로
        tmp_dice[0] = dice[1];
        tmp_dice[3] = dice[0];
        tmp_dice[2] = 7 - tmp_dice[0];
        tmp_dice[1] = 7 - tmp_dice[3]; 
    } else if(type == 2) {  // 왼쪽으로
        tmp_dice[0] = dice[4];
        tmp_dice[5] = dice[0];
        tmp_dice[2] = 7 - tmp_dice[0];
        tmp_dice[4] = 7 - tmp_dice[5];
    } else {                // 뒤로
        tmp_dice[0] = dice[3];
        tmp_dice[1] = dice[0];
        tmp_dice[2] = 7 - tmp_dice[0];
        tmp_dice[3] = 7 - tmp_dice[1];
    }

    dice = tmp_dice;
}

int bfs(int sy, int sx, int num) {
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    int cnt = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) 
                continue;

            if(board[ny][nx] == num && !visited[ny][nx]) {
                cnt++;
                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    board.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int score = 0;
    int dir = 0;
    int cur_y = 0, cur_x = 0;
    while(k--) {

        // 1 주사위 이동
        int ny = cur_y + dy[dir];
        int nx = cur_x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
            dir += 2;
            if(dir > 3) dir -= 4;
        }
        cur_y += dy[dir];
        cur_x += dx[dir];
        dice_rotate(dir);

        // 2 점수 획득
        int c = bfs(cur_y, cur_x, board[cur_y][cur_x]);
        score += c * board[cur_y][cur_x];

        // 3
        if(dice[0] > board[cur_y][cur_x]) {
            dir = (dir == 3)? 0 : dir + 1;
        } else if (dice[0] < board[cur_y][cur_x]) {
            dir = (dir == 0)? 3 : dir - 1;
        }
    
    }

    cout << score << '\n';
    return 0;
}