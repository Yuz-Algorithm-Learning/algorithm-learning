#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    int n;
    cin >> n;

    int w = n * 2;
    vector<vector<int>> board(n, vector<int>(w));
    vector<vector<int>> idx_board(n, vector<int>(w));
    int idx = 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2 != 0) {
            for(int j = 0; j < n * 2; j += 2) {
                cin >> board[i - 1][j] >> board[i - 1][j + 1];
                idx_board[i - 1][j] = idx_board[i - 1][j + 1] = idx;
                idx++;
            }
        } else {
            for(int j = 1; j < n * 2 - 1; j += 2) {
                cin >> board[i - 1][j] >> board[i - 1][j + 1];
                idx_board[i - 1][j] = idx_board[i - 1][j + 1] = idx;
                idx++;
            }
        }
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    q.emplace(0, 1);
    vector<vector<int>> dist(n, vector<int>(w));
    dist[0][0] = 1;
    dist[0][1] = 1;
    
    int max_idx = 1;
    int last_idx = n * n - n / 2;
    vector<int> before_idx(last_idx + 1);
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= w)
                continue;

            if(board[y][x] == board[ny][nx] && dist[ny][nx] == 0) {
                dist[ny][nx] = dist[y][x] + 1;
                q.emplace(ny, nx);

                bool left = (nx - 1 >= 0 && idx_board[ny][nx] == idx_board[ny][nx - 1])? true : false;
                if(left) {
                    dist[ny][nx - 1] = dist[y][x] + 1;
                    q.emplace(ny, nx - 1);
                } else {
                    dist[ny][nx + 1] = dist[y][x] + 1;
                    q.emplace(ny, nx + 1);
                }

                before_idx[idx_board[ny][nx]] = idx_board[y][x];
                max_idx = max(max_idx, idx_board[ny][nx]);
            }
        }
    }

    vector<int> rst;
    rst.push_back(max_idx);
    while(before_idx[max_idx] != 0) {
        max_idx = before_idx[max_idx];
        rst.push_back(max_idx);
    }

    cout << rst.size() << '\n';
    for(int i = rst.size() - 1; i >= 0; i--) {
        cout << rst[i] << " ";
    }
    cout << '\n';

    return 0;
}
