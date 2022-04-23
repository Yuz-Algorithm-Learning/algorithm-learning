#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(n));
    vector<pair<int, int>> virus;
    int zero_num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];

            if(board[i][j] == 2) {
                virus.emplace_back(i, j);
            } else if(board[i][j] == 0) {
                zero_num++;
            }
        }
    }

    if(zero_num == 0) {
        cout << "0\n";
        return 0;
    }

    vector<bool> visited(virus.size());
    for(int i = 0; i < m; i++) {
        visited[i] = true;
    }

    int ans = 987654321;
    do {
        queue<pair<int, int>> q;
        vector<vector<int>> tmp_board = board;
        vector<vector<bool>> tmp_visited(n, vector<bool>(n));
        for(int i = 0; i < virus.size(); i++) {
            if(visited[i]) {
                q.emplace(virus[i].first, virus[i].second);
                tmp_visited[virus[i].first][virus[i].second] = true;
            }
        }

        int tmp_time = 1;
        int tmp_zero_num = 0;
        while(!q.empty()) {
            int q_size = q.size();
            
            while(q_size--) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;

                    if(board[ny][nx] != 1 && !tmp_visited[ny][nx]) {
                        if(board[ny][nx] == 0)
                            tmp_zero_num++;
                        tmp_visited[ny][nx] = true;
                        q.emplace(ny, nx);
                    }
                }
            }

            if(zero_num == tmp_zero_num)
                break;

            tmp_time++;
        }

        if(zero_num == tmp_zero_num)
            ans = min(ans, tmp_time);

    } while(prev_permutation(visited.begin(), visited.end()));

    if(ans != 987654321)
        cout << ans << '\n';
    else
        cout << "-1\n";

    return 0;

}