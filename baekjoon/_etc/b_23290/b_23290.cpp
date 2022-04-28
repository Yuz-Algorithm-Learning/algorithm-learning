#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> board(5, vector<vector<int>>(5));
vector<vector<int>> smell(5, vector<int>(5));
int shark_y, shark_x;
const int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

const int sdy[] = {-1, 0, 1, 0};
const int sdx[] = {0, -1, 0, 1};

vector<pair<int, int>> loc;
vector<pair<int, int>> rst_loc;
int shark_max_eat = -1;

void sharkMove(int y, int x, int cnt) {
    if(cnt == 3) {
        int visited[5][5] = {0, };
        int tmp_sum = 0;
        vector<pair<int, int>> tmp_loc;

        for(int i = 0; i < loc.size(); i++) {
            if(!visited[loc[i].first][loc[i].second]) {
                tmp_loc.emplace_back(loc[i].first, loc[i].second);
                visited[loc[i].first][loc[i].second] = true;
                tmp_sum += board[loc[i].first][loc[i].second].size();
            }
        }

        if(shark_max_eat < tmp_sum) {
            shark_y = y;
            shark_x = x;
            rst_loc = tmp_loc;
            shark_max_eat = tmp_sum;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        int ny = y + sdy[i];
        int nx = x + sdx[i];

        if(ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
            continue;
        
        loc.emplace_back(ny, nx);
        sharkMove(ny, nx, cnt + 1);
        loc.pop_back();
    }
}

int main() {
    int m, s;
    cin >> m >> s;

    for(int i = 0; i < m; i++) {
        int fy, fx, d;
        cin >> fy >> fx >> d;
        board[fy][fx].push_back(d);
    }

    cin >> shark_y >> shark_x;

    while(s--) {
        // 1. 복제
        vector<vector<vector<int>>> copy_board = board;

        // 2. 물고기 이동
        vector<vector<vector<int>>> next_board(5, vector<vector<int>>(5));
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                for(int f = 0; f < board[i][j].size(); f++) {
                    int curr_dir = board[i][j][f];
                    bool is_move = false;

                    for(int r = 0; r < 8; r++) {
                        int next_dir = (curr_dir - r >= 1)? curr_dir - r : curr_dir - r + 8; 
                        int ny = i + dy[next_dir];
                        int nx = j + dx[next_dir];

                        if(ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
                            continue;

                        if(!(ny == shark_y && nx == shark_x) && smell[ny][nx] == 0) {
                            is_move = true;
                            next_board[ny][nx].push_back(next_dir);
                            break;
                        }
                    }

                    if(!is_move)
                        next_board[i][j].push_back(curr_dir);
                }
            }
        }
        board = next_board;

        // 3. 상어 이동
        loc.clear();
        rst_loc.clear();
        shark_max_eat = -1;
        sharkMove(shark_y, shark_x, 0);

        // 4. 물고기 냄새 제거
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                if(smell[i][j])
                    smell[i][j] -= 1;
            }
        }
        for(int i = 0; i < rst_loc.size(); i++) {
            if(!board[rst_loc[i].first][rst_loc[i].second].empty()) {
                board[rst_loc[i].first][rst_loc[i].second].clear();
                smell[rst_loc[i].first][rst_loc[i].second] = 2;
            }
        }

        // 5. 복제
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                for(int f = 0; f < copy_board[i][j].size(); f++) {
                    board[i][j].push_back(copy_board[i][j][f]);
                }
            }
        };
    } 

    int sum = 0;
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            sum += board[i][j].size();
        }
    }
    cout << sum << '\n';
    return 0;
}