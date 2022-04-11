#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m;
int wall;
int min_cnt = 987654321;
int board[9][9];
vector<pair<int, int>> zero;
vector<pair<int, int>> virus;

void bfs() {
    int cnt = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));

    for(int i = 0; i < virus.size(); i++) {
        q.emplace(virus[i].first, virus[i].second);
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if(board[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.emplace(ny, nx);
                cnt++;
            }
        }
    }

    min_cnt = min(min_cnt, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int zero_num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == 0) zero.emplace_back(i, j);
            else if(board[i][j] == 1) wall++;
            else if(board[i][j] == 2) virus.emplace_back(i, j);
        }
    }

    vector<bool> select_zero(zero.size(), true);
    for(int i = 0; i < select_zero.size() - 3; i++) {
        select_zero[i] = false;
    }

    for(int i = 0; i < zero.size() - 2; i++) {
        board[zero[i].first][zero[i].second] = 1;
        for(int j = i + 1; j < zero.size() - 1; j++) {
            board[zero[j].first][zero[j].second] = 1;
            for(int k = j + 1; k < zero.size(); k++) {
                board[zero[k].first][zero[k].second] = 1;
                bfs();
                board[zero[k].first][zero[k].second] = 0;
            }
            board[zero[j].first][zero[j].second] = 0;
        }
        board[zero[i].first][zero[i].second] = 0;
    }

    cout << zero.size() - 3 - min_cnt << '\n';
    return 0;
}