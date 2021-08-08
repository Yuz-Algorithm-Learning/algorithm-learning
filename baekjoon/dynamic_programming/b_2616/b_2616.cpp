#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[4][50001];

int main()
{
    int N;
    scanf("%d", &N);

    int num;
    vector<int> acc(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);
        acc[i] = acc[i - 1] + num;
    }
    
    int M;
    scanf("%d", &M);

    for (int i = 1; i <= 3; i++) {
        for (int j = i * M; j <= N - M * (3 - i); j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + (acc[j] - acc[j - M]));
        }
    }

    printf("%d", dp[3][N]);
}
