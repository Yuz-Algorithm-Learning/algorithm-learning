#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int n, l, r;
vector<vector<int>> board;
vector<vector<bool>> visited;

bool bfs(int sy, int sx) {
    int sum = 0;
    vector<pair<int, int>> tmp;
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.emplace(sy, sx);
    tmp.emplace_back(sy, sx);
    sum += board[sy][sx];

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            
            if(!visited[ny][nx]) {
                int diff = abs(board[ny][nx] - board[y][x]);
                if(l <= diff && diff <= r) {
                    visited[ny][nx] = true;
                    q.emplace(ny, nx);
                    tmp.emplace_back(ny, nx);
                    sum += board[ny][nx];
                }
            }
        }
    }

    int change_num = sum / tmp.size();
    for(int i = 0; i < tmp.size(); i++) {
        board[tmp[i].first][tmp[i].second] = change_num;
    }

    if(tmp.size() > 1) return true;
    else return false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    board.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    while(1) {
        int is_change = false;

        visited.resize(n, vector<bool>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(bfs(i, j))
                        is_change = true;
                }
            }
        }

        visited.clear();
        if(is_change)
            cnt++;
        else
            break;
    }

    cout << cnt << '\n';
    
}