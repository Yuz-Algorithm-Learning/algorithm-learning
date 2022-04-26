#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, -1, 1};

int main() {
    int n, m, k;

    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    vector<pair<int, int>> shark_loc(m + 1);
    vector<vector<pair<int, int>>> board(n, vector<pair<int, int>>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].first;
            if(board[i][j].first) {
                board[i][j].second = k;
                shark_loc[board[i][j].first] = {i, j};
            }
        }
    }

    vector<int> shark_dir(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> shark_dir[i];
    }

    int shark_priority[m + 1][5][4];
    for(int s = 1; s <= m; s++) {
        for(int i = 1; i <= 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> shark_priority[s][i][j];
            }
        }
    }

    int time = 1;
    while(1) {
        if(time > 1000) {
            cout << "-1\n";
            return 0;
        }

        map<pair<int, int>, vector<int>> bomb;
        for(int i = 1; i <= m; i++) {
            int y = shark_loc[i].first;
            int x = shark_loc[i].second;
            int dir = shark_dir[i];
            if(y == -1)
                continue;

            bool is_move = false;
            for(int d = 0; d < 4; d++) {
                int dd = shark_priority[i][dir][d];

                int ny = y + dy[dd];
                int nx = x + dx[dd];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                if(!board[ny][nx].first && !board[ny][nx].second) {
                    is_move = true;
                    shark_loc[i] = {ny, nx};
                    shark_dir[i] = dd;
                    bomb[{ny, nx}].push_back(i);
                    break;
                }
            }

            // 아무 냄새가 없는 칸이 없을 때 -> 자신의 냄새가 있는 칸의 방향으로
            if(!is_move) {
                for(int d = 0; d < 4; d++) {
                    int dd = shark_priority[i][dir][d];

                    int ny = y + dy[dd];
                    int nx = x + dx[dd];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;

                    if(board[ny][nx].first == i) {
                        shark_loc[i] = {ny, nx};
                        shark_dir[i] = dd;
                        bomb[{ny, nx}].push_back(i);
                        break;
                    }
                }
            }
        }

        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                if(board[a][b].first) {
                    board[a][b].second--;

                    if(board[a][b].second == 0) {
                        board[a][b].first = 0;
                    }
                }
            }
        }

        // 상어 충돌한다면 최소 뽑아주고 나머지 죽이기
        for(auto b_info : bomb) {
            int min_shark_num = 987654321;
            
            if(b_info.second.size() != 1) {
                for(int b = 0; b < b_info.second.size(); b++) {
                    min_shark_num = min(min_shark_num, b_info.second[b]);
                }

                for(int b = 0; b < b_info.second.size(); b++) {
                    if(b_info.second[b] != min_shark_num) {
                        shark_loc[b_info.second[b]].first = -1;
                        shark_loc[b_info.second[b]].second = -1;
                    }
                }
            }
        }

        bool is_one = true;
        for(int s = 1; s <= m; s++) {
            if(shark_loc[s].first != -1) {
                if(s != 1) {
                    is_one = false;
                }
                board[shark_loc[s].first][shark_loc[s].second].first = s;
                board[shark_loc[s].first][shark_loc[s].second].second = k;
            }
        }

        if(is_one)
            break;

        time++;
   }

    cout << time << '\n';
    return 0;

}