#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> city(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (city[a][b] > c)
            city[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;

            for (int j = 1; j <= n; j++) {
                if (k == j || i == j)
                    continue;

                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", city[i][j]);
        }
        printf("\n");
    }

    return 0;
}
