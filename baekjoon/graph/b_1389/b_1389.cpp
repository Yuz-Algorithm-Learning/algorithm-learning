#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        map[a][b] = 1;
        map[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                map[i][j] = 0;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;

            for (int j = 1; j <= n; j++) {
                if (k == j || i == j)
                    continue;

                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }

    int ans_min = INF;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;

        for (int j = 1; j <= n; j++) {
            tmp += map[i][j];
        }

        if (ans_min > tmp) {
            ans_min = tmp;
            ans = i;
        }
    }

    printf("%d", ans);
}
