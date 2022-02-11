#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<int>> map(n, vector<int>(m));
    
    int num = 0;
    queue<pair<int, int>> tomato;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == -1)
                num++;
            else if (map[i][j] == 1) {
                num++;
                tomato.emplace(i, j);
            }
        }
    }

    int dy[4] = { 0, 0, -1, 1 };
    int dx[4] = { -1, 1, 0, 0 };
    int max_result = 0;

    while (!tomato.empty()) {
        int y = tomato.front().first;
        int x = tomato.front().second;
        tomato.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (map[ny][nx] == 0) {
                    num++;
                    map[ny][nx] = map[y][x] + 1;
                    tomato.emplace(ny, nx);

                    if (max_result < map[ny][nx])
                        max_result = map[ny][nx];

                }
            }
        }

    }

    if (num == m * n) {
        if (max_result == 0)
            printf("0");
        else
            printf("%d", max_result - 1);
    }
    else
        printf("-1");
}
