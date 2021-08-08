#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int milk[1001][1001];

int main()
{
    int N;
    scanf("%d", &N);

    int m;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &milk[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (dp[i - 1][j] == 0 && dp[i][j - 1] == 0) {
                if (!milk[i][j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    if ((milk[i - 1][j] + 1) % 3 == milk[i][j]) {
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                    else {
                        milk[i][j] = milk[i - 1][j];
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else {
                    if ((milk[i][j - 1] + 1) % 3 == milk[i][j]) {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                    else {
                        milk[i][j] = milk[i][j - 1];
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
    }

    printf("%d", dp[N][N]);
}

