#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 1001

int map[MAX][MAX];
int rst[MAX][MAX];
bool visit[MAX][MAX][2];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<tuple<int, int, bool>> q;
    q.emplace(1, 1, false);
    visit[1][1][0] = visit[1][1][1] = true;
    rst[1][1] = 1;

    while(!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int wall = get<2>(q.front());
        q.pop();

        if(y == n && x == m) {
            printf("%d\n", rst[y][x]);
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
                if(map[ny][nx] == 1 && wall == 0 && !visit[ny][nx][1]) {
                    visit[ny][nx][1] = true;
                    rst[ny][nx] = rst[y][x] + 1;
                    q.emplace(ny, nx, 1);
                } else if(map[ny][nx] == 0 && !visit[ny][nx][wall]) {
                    visit[ny][nx][wall] = true;
                    rst[ny][nx] = rst[y][x] + 1;
                    q.emplace(ny, nx, wall);
                }
            }
        }
    }

    printf("-1\n");
    return 0;

}