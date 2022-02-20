#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> map(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    vector<vector<int>> rst(n + 1, vector<int>(m + 1));
    rst[1][1] = 1;
    queue<pair<int, int>> q;
    q.emplace(1, 1);

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
                if(map[ny][nx] == 1 && !rst[ny][nx]) {
                    rst[ny][nx] = rst[y][x] + 1;
                    q.emplace(ny, nx);
                }
            }
        }
    }

    printf("%d\n", rst[n][m]);
}