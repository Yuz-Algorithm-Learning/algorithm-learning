#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

struct info {
    int y, x, k;
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<vector<int>> board(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    int dis = 0;
    bool is_end = false;
    queue<info> q;
    vector<vector<int>> k_num(n + 1, vector<int>(m + 1, -1));
    q.push({1, 1, k});

    while(!q.empty()) {
        int q_size = q.size();

        while(q_size--) {
            int y = q.front().y;
            int x = q.front().x;
            int kk = q.front().k;
            q.pop();

            if(y == n && x == m) {
                is_end = true;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny <= 0 || ny > n || nx <= 0 || nx > m || (board[ny][nx] == 1 && kk <= 0))
                    continue;
                
                if(board[ny][nx] == 1) {
                    if(k_num[ny][nx] < kk - 1) {
                        k_num[ny][nx] = kk - 1;
                        q.push({ny, nx, kk - 1});
                    }
                } else {
                    if(k_num[ny][nx] < kk) {
                        k_num[ny][nx] = kk;
                        q.push({ny, nx, kk});
                    }
                }
            }
        }

        dis++;
        if(is_end) break;  
    }

    if(is_end)
        printf("%d\n", dis);
    else
        printf("-1\n");

    return 0;
}