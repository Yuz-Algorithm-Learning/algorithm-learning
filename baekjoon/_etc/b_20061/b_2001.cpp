#include <iostream>
#include <vector>

using namespace std;

bool board[10][10];

int blue_move(int y, int x) {
    int b_ny = y, b_nx = x;
    while(1) {
        if(b_nx + 1 >= 10 || board[b_ny][b_nx + 1]) 
            break;
        b_nx++;
    }
    return b_nx;
}

int green_move(int y, int x) {
    int g_ny = y, g_nx = x;
    while(1) {
        if(g_ny + 1 >= 10 || board[g_ny + 1][g_nx])
            break;
        g_ny++;
    }
    return g_ny;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int t, y, x;
        cin >> t >> y >> x;
        
        int blue_x, green_y;
        if(t == 1) {
            blue_x = blue_move(y, x);
            green_y = green_move(y, x);
            board[y][blue_x] = true;
            board[green_y][x] = true;
        } else if(t == 2) {
            blue_x = blue_move(y, x + 1);
            green_y = min(green_move(y, x), green_move(y, x + 1));
            board[y][blue_x - 1] = true;
            board[y][blue_x] = true;
            board[green_y][x] = true;
            board[green_y][x + 1] = true;
        } else {
            blue_x = min(blue_move(y, x), blue_move(y + 1, x));
            green_y = green_move(y + 1, x);
            board[y][blue_x] = true;
            board[y + 1][blue_x] = true;
            board[green_y - 1][x] = true;
            board[green_y][x] = true;
        }

        // 파란색: 열이 타일로 가득 차 있으면 타일 모두 삭제 -> 오른쪽으로
        int blue_erase = 0;
        vector<vector<bool>> b_line(4, vector<bool>(6));
        int b_idx = 0;
        for(int j = 9; j > 5; j--) {
            int num = 0;
            for(int i = 0; i < 4; i++) {
                if(board[i][j]) 
                    num++;
            }
            if(num == 4) {
                blue_erase++;
                ans++;
            } else {
                for(int i = 0; i < 4; i++) {
                    b_line[i][b_idx] = board[i][j];
                }
                b_idx++;
            }
        }

        if(blue_erase) {
            for(int j = 0; j < 4; j++) {
                for(int i = 0; i < 4; i++) {
                    board[i][9 - j] = b_line[i][j];
                }
            }

            if(board[0][5] || board[1][5] || board[2][5] || board[3][5]) {
                for(int i = 0; i < 4; i++) {
                    board[i][5 + blue_erase] = board[i][5];
                    board[i][5] = false;
                }
            }
            if(board[0][4] || board[1][4] || board[2][4] || board[3][4]) {
                for(int i = 0; i < 4; i++) {
                    board[i][4 + blue_erase] = board[i][4];
                    board[i][4] = false;
                }
            }
        }

        blue_erase = 0;
        if(board[0][5] || board[1][5] || board[2][5] || board[3][5]) {
            blue_erase++;
        }
        if(board[0][4] || board[1][4] || board[2][4] || board[3][4]) {
            blue_erase++;
        }

        if(blue_erase) {
            for(int j = 9; j > 5; j--) {
                for(int i = 0; i < 4; i++) {
                    board[i][j] = board[i][j - blue_erase];
                }
            }
            for(int j = 4; j <= 5; j++) {
                for(int i = 0; i < 4; i++) {
                    board[i][j] = false;
                }
            }
        }

        // 초록색: 행이 타일로 가득 차 있으면 타일 모두 삭제 -> 아래로
        int green_erase = 0;
        vector<vector<bool>> g_line(6, vector<bool>(4));
        int g_idx = 0;
        for(int i = 9; i > 5; i--) {
            int num = 0;
            for(int j = 0; j < 4; j++) {
                if(board[i][j])
                    num++;
            }
            if(num == 4) {
                green_erase++;
                ans++;
            } else {
                for(int j = 0; j < 4; j++) {
                    g_line[g_idx][j] = board[i][j];
                }
                g_idx++;
            }
        }
        if(green_erase) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    board[9 - i][j] = g_line[i][j];
                }
            }

            if(board[5][0] || board[5][1] || board[5][2] || board[5][3]) {
                for(int j = 0; j < 4; j++) {
                    board[5 + green_erase][j] = board[5][j];
                    board[5][j] = false;
                }
            }
            if(board[4][0] || board[4][1] || board[4][2] || board[4][3]) {
                for(int j = 0; j < 4; j++) {
                    board[4 + green_erase][j] = board[4][j];
                    board[4][j] = false;
                }
            }
        }

        green_erase = 0;
        if(board[5][0] || board[5][1] || board[5][2] || board[5][3]) {
            green_erase++;
        }
        if(board[4][0] || board[4][1] || board[4][2] || board[4][3]) {
            green_erase++;
        }

        if(green_erase) {
            for(int i = 9; i > 5; i--) {
                for(int j = 0; j < 4; j++) {
                    board[i][j] = board[i - green_erase][j];
                }
            }
            for(int i = 4; i <= 5; i++) {
                for(int j = 0; j < 4; j++) {
                    board[i][j] = false;
                }
            }
        }

    }

    int blue_green_num = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 6; j < 10; j++) {
            if(board[i][j])
                blue_green_num++;
        }
    }
    for(int i = 6; i < 10; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j])
                blue_green_num++;
        }
    }

    cout << ans << '\n' << blue_green_num << '\n';
}