#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, m, idx = 1;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int board[1000][1000];
bool visited[1000][1000];
int zero_group_idx[1000][1000];
int zero_group_num[1000000];

void bfs(int sy, int sx) {
    int cnt = 1;
    queue<pair<int, int>> q;
    
    q.emplace(sy, sx);
    visited[sy][sx] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        zero_group_idx[y][x] = idx;
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

    zero_group_num[idx] = cnt;
    idx++;
}

int cnt_zero(int y, int x) {
    map<int, bool> flag;
    int sum = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        
        if(!flag[zero_group_idx[ny][nx]]) {
            flag[zero_group_idx[ny][nx]] = true;
            sum += zero_group_num[zero_group_idx[ny][nx]];
        }
    }

    return sum;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && !board[i][j]) {
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                printf("%d", cnt_zero(i, j) % 10);
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}