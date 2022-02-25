#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num;
vector<vector<int>> dp;

void palindrome()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (num[i] == num[i + 1])
            dp[i][i + 1] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (num[j] == num[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
        }
    }
}

int main()
{
    scanf("%d", &n);

    num.resize(n + 1);
    dp.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }

    palindrome();

    int m, s, e;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}