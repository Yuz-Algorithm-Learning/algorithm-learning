#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool board[2001][2001];
bool visited[2001][2001];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.push({sy, sx});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= 2001 || nx < 0 || nx >= 2001)
                continue;
            
            if(board[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;

        for(int i = y1; i <= y2; i++) {
            board[i][x1] = true;
            board[i][x2] = true;
        }
        for(int j = x1; j <= x2; j++) {
            board[y1][j] = true;
            board[y2][j] = true;
        }
    }

    int rst = 0;
    for(int i = 0; i < 2001; i++) {
        for(int j = 0; j < 2001; j++) {
            if(board[i][j] && !visited[i][j]) {
                rst++;
                bfs(i, j);
            }
        }
    }
    
    if(board[1000][1000])
        rst--;

    cout << rst << '\n';
    return 0;
}