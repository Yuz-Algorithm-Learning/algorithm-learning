#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp)
                graph[i][j] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == i)
                continue;

            for (int j = 1; j <= n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }

}
