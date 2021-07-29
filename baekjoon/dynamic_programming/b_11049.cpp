#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int mat[500][2] = { 0 };
int dp[500][500] = { 0 };

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &mat[i][0], &mat[i][1]);

    for (int j = 1; j < N; j++) {
        for (int i = 0; i < N - j; i++) {
            dp[i][i + j] = INT_MAX;

            for (int k = i; k < i + j; k++) {
                dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k + 1][i + j] + mat[i][0] * mat[k][1] * mat[i + j][1]);
            }
        }
    }
    
    printf("%d", dp[0][N-1]);
}