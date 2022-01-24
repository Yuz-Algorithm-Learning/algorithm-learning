#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> stairs(n + 1);
    vector<vector<int>> sum(n + 1, vector<int>(2, 0)); /* 0: 이전 포함, 1: 이전 포함 X */

    for (int i = 1; i <= n; i++)
        scanf("%d", &stairs[i]);

    sum[1][0] = stairs[1];
    sum[1][1] = stairs[1];

    for (int i = 2; i <= n; i++) {
        sum[i][0] = stairs[i] + max(sum[i - 2][0], sum[i - 2][1]);
        sum[i][1] = stairs[i] + sum[i - 1][0];
    }

    if (sum[n][0] > sum[n][1])
        printf("%d", sum[n][0]);
    else
        printf("%d", sum[n][1]);

}
