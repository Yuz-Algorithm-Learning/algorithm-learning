#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> map(n + 1, vector<int>(n + 1));
    
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tmp);
            map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + tmp;
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", map[x2][y2] - (map[x2][y1 - 1] + map[x1 - 1][y2] - map[x1 - 1][y1 - 1]));
    }
}
