#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> board(n + 1, vector<int>(m));
    vector<int> top_idx(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while(t--) {
        int x, d, k;
        cin >> x >> d >> k;

        // 원판 회전
        int num = 1;
        while(1) {
            int circle_num = x * num;
            if(circle_num > n)
                break;
        
            int x_top = top_idx[circle_num];
            int type = (d == 0)? -1 : 1;
            for(int i = 0; i < k; i++) {
                x_top += type;

                if(x_top < 0) 
                    x_top = m - 1;
                else if (x_top >= m)
                    x_top = 0;
            }
            top_idx[circle_num] = x_top;
            num++;
        }
    
        // 인접수 제거
        vector<vector<bool>> board_erase(n + 1, vector<bool>(m));
        int erase_num = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m - 1; j++) {
                if(board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
                    erase_num++;
                    board_erase[i][j] = board_erase[i][j + 1] = true;
                }
            }
            if(board[i][0] != 0 && board[i][0] == board[i][m - 1]) {
                erase_num++;
                board_erase[i][0] = board_erase[i][m - 1] = true;
            }
        }
        for(int j = 0; j < m; j++) {
            for(int i = 1; i < n; i++) {
                int idx1 = top_idx[i] + j;
                if(idx1 >= m) idx1 -= m;
                int idx2 = top_idx[i + 1] + j;
                if(idx2 >= m) idx2 -= m;

                if(board[i][idx1] != 0 && board[i][idx1] == board[i + 1][idx2]) {
                    erase_num++;
                    board_erase[i][idx1] = board_erase[i + 1][idx2] = true;
                }
            }
        }

        int tmp_sum = 0;
        int tmp_num = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                if(board_erase[i][j]) {
                    board[i][j] = 0;
                } else {
                    if(board[i][j] != 0) {
                        tmp_sum += board[i][j];
                        tmp_num++;
                    }
                }
            }
        }

        // 인접하면서 수가 같은 것이 없을 때
        if(erase_num == 0) {
            double standard = tmp_sum / (double)tmp_num;
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j] != 0) {
                        if(board[i][j] < standard) {
                            board[i][j] += 1;
                        } else if(board[i][j] > standard) {
                            board[i][j] -= 1;
                        }

                    }
                }
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            sum += board[i][j];
        }
    }

    cout << sum << '\n';
}