#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

const int half_idx[] = { 2, 1, 0, 3 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int time = 0;
    while (1) {

        // 1. 가장 적은 어항에 물고기 한마리 넣음
        int min_num = *min_element(board.begin(), board.end());
        for (int i = 0; i < n; i++) {
            if (board[i] == min_num) {
                board[i] += 1;
            }
        }

        // 2. 공중 부양
        int sq = sqrt(n);
        int h, w;

        if (sq * sq == n) {
            h = sq, w = sq;
        }
        if (sq * (sq + 1) == n) {
            h = sq + 1, w = sq;
        }
        else if (n < sq * (sq + 1)) {
            int add = n % (sq * sq);
            h = sq, w = sq + add;
        }
        else if (sq * (sq + 1) < n) {
            int add = n % (sq * (sq + 1));
            h = sq + 1, w = sq + add;
        }

        vector<vector<int>> next_board(h, vector<int>(w));
        int dir = 0;
        int idx = n - 1;
        int cur_y = h - 1, cur_x = sq - 1;
        int center_y, center_x, center_dir;
        for (int i = w - 1; i >= sq - 1; i--) {
            next_board[h - 1][i] = board[idx--];
        }
        while (idx >= 0) {
            int ny = cur_y + dy[dir];
            int nx = cur_x + dx[dir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= sq || next_board[ny][nx])
                dir = (dir == 3) ? 0 : dir + 1;

            cur_y += dy[dir];
            cur_x += dx[dir];
            if (idx == 0)
                center_y = cur_y, center_x = cur_x, center_dir = dir;
            next_board[cur_y][cur_x] = board[idx--];
        }


        // 3. 물고기 수 조절
        vector<vector<int>> fish_board(h, vector<int>(w));
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < sq - 1; j++) {
                int diff = abs(next_board[i][j] - next_board[i][j + 1]) / 5;
                if (diff > 0) {
                    if (next_board[i][j] < next_board[i][j + 1]) {
                        fish_board[i][j] += diff;
                        fish_board[i][j + 1] -= diff;
                    }
                    else {
                        fish_board[i][j + 1] += diff;
                        fish_board[i][j] -= diff;
                    }
                }
            }
        }
        for (int j = 0; j < w - 1; j++) {
            int diff = abs(next_board[h - 1][j] - next_board[h - 1][j + 1]) / 5;
            if (diff > 0) {
                if (next_board[h - 1][j] < next_board[h - 1][j + 1]) {
                    fish_board[h - 1][j] += diff;
                    fish_board[h - 1][j + 1] -= diff;
                }
                else {
                    fish_board[h - 1][j + 1] += diff;
                    fish_board[h - 1][j] -= diff;
                }
            }
        }
        for (int j = 0; j < sq; j++) {
            for (int i = 0; i < h - 1; i++) {
                int diff = abs(next_board[i][j] - next_board[i + 1][j]) / 5;
                if (diff > 0) {
                    if (next_board[i][j] < next_board[i + 1][j]) {
                        fish_board[i][j] += diff;
                        fish_board[i + 1][j] -= diff;
                    }
                    else {
                        fish_board[i + 1][j] += diff;
                        fish_board[i][j] -= diff;
                    }
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                next_board[i][j] += fish_board[i][j];
            }
        }

        // 4. 일렬로
        vector<int> tmp_board(n);
        idx = 0;
        for (int j = 0; j < sq; j++) {
            for (int i = h - 1; i >= 0; i--) {
                tmp_board[idx++] = next_board[i][j];
            }
        }
        for (int j = sq; j < w; j++)
            tmp_board[idx++] = next_board[h - 1][j];

        board = tmp_board;

        // 5. 반으로
        int half_half = n / 4;
        int tmp_idx = 0;
        vector<vector<int>> half_board(4, vector<int>(half_half));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < half_half; j++) {
                if (i == 1 || i == 3) {
                    half_board[half_idx[i]][j] = board[tmp_idx++];
                }
                else {
                    half_board[half_idx[i]][half_half - 1 - j] = board[tmp_idx++];
                }

            }
        }

        // 6. 물고기 조율
        vector<vector<int>> tmp_half_board(4, vector<int>(half_half));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < half_half - 1; j++) {
                int diff = abs(half_board[i][j] - half_board[i][j + 1]) / 5;
                if (diff > 0) {
                    if (half_board[i][j] < half_board[i][j + 1]) {
                        tmp_half_board[i][j] += diff;
                        tmp_half_board[i][j + 1] -= diff;
                    }
                    else {
                        tmp_half_board[i][j + 1] += diff;
                        tmp_half_board[i][j] -= diff;
                    }
                }
            }
        }
        for (int j = 0; j < half_half; j++) {
            for (int i = 0; i < 3; i++) {
                int diff = abs(half_board[i][j] - half_board[i + 1][j]) / 5;
                if (diff > 0) {
                    if (half_board[i][j] < half_board[i + 1][j]) {
                        tmp_half_board[i][j] += diff;
                        tmp_half_board[i + 1][j] -= diff;
                    }
                    else {
                        tmp_half_board[i + 1][j] += diff;
                        tmp_half_board[i][j] -= diff;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < half_half; j++) {
                half_board[i][j] += tmp_half_board[i][j];
            }
        }


        // 7. 일렬로
        idx = 0;
        vector<int> half_tmp(n);
        for (int j = 0; j < half_half; j++) {
            for (int i = 3; i >= 0; i--) {
                half_tmp[idx++] = half_board[i][j];
            }
        }
        board = half_tmp;

        int max_value = *max_element(board.begin(), board.end());
        int min_value = *min_element(board.begin(), board.end());

        time++;
        if (max_value - min_value <= k)
            break;
    }

    cout << time << '\n';
    return 0;

}