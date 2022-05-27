#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

struct info {
    int y, x;
    int k_num;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    string lines;
    vector<vector<char>> board(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        cin >> lines;

        for(int j = 0; j < m; j++) {
            board[i][j] = lines[j];
        }
    }

    queue<info> q;
    q.push({0, 0, k});
    int day = 1;
    bool is_push = true;
    bool is_ans = false;

    vector<vector<int>> visited(n, vector<int>(m, -1));
    visited[0][0] = k;

    while(!q.empty()) {
        int q_size = q.size();

        while(q_size--) {
            int y = q.front().y;
            int x = q.front().x;
            int k_num = q.front().k_num;
            q.pop();
            
            if(y == (n - 1) && x == (m - 1)) {
                is_ans = true;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
            
                if(board[ny][nx] == '1' && k_num > 0) {
                    if(is_push && visited[ny][nx] < (k_num - 1)) {
                        visited[ny][nx] = k_num - 1;
                        q.push({ny, nx, k_num - 1});
                    } else if(!is_push && visited[ny][nx] < k_num) {
                        q.push({y, x, k_num});
                    }
                } else if(board[ny][nx] == '0') {
                    if(is_push && visited[ny][nx] < k_num) {
                        visited[ny][nx] = k_num;
                        q.push({ny, nx, k_num});
                    } else if(!is_push && visited[ny][nx] < k_num) {
                        visited[ny][nx] = k_num;
                        q.push({ny, nx, k_num});
                    }
                }
            }
        }

        if(is_ans) break;

        day++;
        is_push = !is_push;
    }

    if(is_ans) {
        cout << day << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}