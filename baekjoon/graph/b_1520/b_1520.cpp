#include <iostream>

using namespace std;

int M, N;
int map[500][500];
int dp[500][500];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 }; 

int dfs(int m, int n) {

    if (m == M - 1 && n == N - 1)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    dp[m][n] = 0;
    for (int i = 0; i < 4; i++) {
        int mm = m + dy[i];
        int nn = n + dx[i];

        if (mm >= 0 && nn >= 0 && mm < M && nn < N) {
            if (map[m][n] > map[mm][nn]) {
                dp[m][n] += dfs(mm, nn);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }

    printf("%d", dfs(0, 0));
}