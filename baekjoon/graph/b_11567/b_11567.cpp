#include <iostream>
#include <queue>
using namespace std;

char map[501][501];
int n, m;
int start_y, start_x, end_y, end_x;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(start_y, start_x);

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy > 0 && xx > 0 && yy <= n && xx <= m) {
                if (yy == end_y && xx == end_x) {
                    if (map[end_y][end_x] == 'X') {
                        printf("YES\n");
                        return;
                    }
                    else {
                        map[end_y][end_x] = 'X';
                        q.emplace(end_y, end_x);
                    }
                }
                else if(map[yy][xx] == '.') {
                    map[yy][xx] = 'X';
                    q.emplace(yy, xx);
                }
            }
        }
    }

    printf("NO\n");

}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("\n%c", &map[i][j]);
            
    scanf("%d %d", &start_y, &start_x);
    scanf("%d %d", &end_y, &end_x);

    bfs();

}