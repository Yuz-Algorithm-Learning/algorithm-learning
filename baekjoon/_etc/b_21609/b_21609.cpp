#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
vector<vector<int>> board;
vector<vector<bool>> visited;

pair<int, int> bfs(int sy, int sx, int num, vector<vector<bool>> &tmp_block) {
    vector<vector<bool>> tmp_visited(n, vector<bool>(n));
    queue<pair<int, int>> q;
    q.push({sy, sx});
    tmp_visited[sy][sx] = true;
    visited[sy][sx] = true;
    int cnt = 1;
    int um_color = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            
            if(!tmp_visited[ny][nx]) {
                if(board[ny][nx] == 0) {
                    tmp_visited[ny][nx] = true;
                    q.emplace(ny, nx);
                    cnt++;
                    um_color++;
                } else if(board[ny][nx] == num) {
                    visited[ny][nx] = true;
                    tmp_visited[ny][nx] = true;
                    q.emplace(ny, nx);
                    cnt++;
                }
            }
        }
    }

    tmp_block = tmp_visited;
    return {cnt, um_color};
}

void down() {
    vector<vector<int>> tmp(n, vector<int>(n, -2));

    int curr_y, curr_x;
    for(int j = 0; j < n; j++) {
        curr_x = j, curr_y = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(board[i][j] == -1) {
                tmp[i][j] = board[i][j];
                curr_y = i - 1;
            } else if(board[i][j] != -2) {
                tmp[curr_y--][curr_x] = board[i][j];
            }
        }
    }

    board = tmp;
}

void rotate() {
    vector<vector<int>> tmp_board(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp_board[n - 1 - j][i] = board[i][j];
        }
    }

    board = tmp_board;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int score = 0;
    board.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while(1) {
        // 1
        visited.clear();
        visited.resize(n, vector<bool>(n));
        vector<vector<bool>> max_block;
        int max_cnt = 0, max_um = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > 0 && !visited[i][j]) {
                    vector<vector<bool>> tmp_block;
                    pair<int, int> tmp_cnt = bfs(i, j, board[i][j], tmp_block);
                    if(max_cnt < tmp_cnt.first) {
                        max_cnt = tmp_cnt.first;
                        max_um = tmp_cnt.second;
                        max_block = tmp_block;
                    } else if(max_cnt == tmp_cnt.first) {
                        if(max_um <= tmp_cnt.second) {
                            max_cnt = tmp_cnt.first;
                            max_um = tmp_cnt.second;
                            max_block = tmp_block;
                        }
                    }
                }
            }
        }
        if(max_cnt < 2){
            break;
        }

        // 2
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(max_block[i][j]) {
                    board[i][j] = -2;
                }
            }
        }
        score += pow(max_cnt, 2);

        // 3
        down();

        // 4
        rotate();

        // 5
        down();
    }

    cout << score << '\n';
}