#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int total_len;
vector<vector<int>> board;
vector<vector<bool>> visited;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void rotate(vector<vector<int>> &tmp, int len) {
    vector<vector<int>> next_tmp(len, vector<int>(len));

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            next_tmp[j][len - 1 - i] = tmp[i][j];
        }
    }

    tmp = next_tmp;
    return;
}

void share(int len) {
    int sy = 0, sx = 0;

    if(len != 1) {
        while(1) {
            int by = 0, bx = 0;
            vector<vector<int>> block(len, vector<int>(len));
            for(int i = sy; i < sy + len; i++) {
                for(int j = sx; j < sx + len; j++) {
                    block[by][bx] = board[i][j];
                    bx++;
                }
                bx = 0;
                by++;
            }

            rotate(block, len);
            by = 0, bx = 0;
            for(int i = sy; i < sy + len; i++) {
                for(int j = sx; j < sx + len; j++) {
                    board[i][j] = block[by][bx];
                    bx++;
                }
                bx = 0;
                by++;
            }

            sx += len;
            if(sx >= total_len) {
                sx = 0;
                sy += len;
            }
            if(sy >= total_len)
                break;
        }
    }

    // 얼음 지우기
    vector<vector<int>> next_board = board;
    for(int i = 0; i < total_len; i++) {
        for(int j = 0; j < total_len; j++) {

            int num = 0;
            for(int r = 0; r < 4; r++) {
                int ny = i + dy[r];
                int nx = j + dx[r];

                if(ny < 0 || ny >= total_len || nx < 0 || nx >= total_len || !board[ny][nx]) {
                    num++;
                }
            }

            if(num >= 2) {
                if(board[i][j] != 0)
                    next_board[i][j]--;
            }
        }
    }
    board = next_board;
}

int iceZip(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    int tmp_num = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= total_len || nx < 0 || nx >= total_len)
                continue;

            if(board[ny][nx] && !visited[ny][nx]) {
                tmp_num++;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    return tmp_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    total_len = pow(2, n); 
    board.resize(total_len, vector<int>(total_len));
    for(int i = 0; i < total_len; i++) {
        for(int j = 0; j < total_len; j++) {
            cin >> board[i][j];
        }
    }

    int len;
    while(q--) {
        int l;
        cin >> l;
        len = pow(2, l);
        share(len);
    }

    int sum = 0, max_value = 0;
    for(int i = 0; i < total_len; i++) {
        for(int j = 0; j < total_len; j++) {
            sum += board[i][j];
        }
    }

    // 최대 덩어리
    visited.resize(total_len, vector<bool>(total_len));
    for(int i = 0; i < total_len; i++) {
        for(int j = 0; j < total_len; j++) {
            if(!visited[i][j] && board[i][j]) {
                max_value = max(max_value, iceZip(i, j));
            }
        }
    }

    cout << sum << '\n' << max_value << '\n';
    return 0;
}