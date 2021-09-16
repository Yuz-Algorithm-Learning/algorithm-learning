#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int I, T;
    vector<vector<int>> v(K + 1, vector<int>(N + 1));
    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &I, &T);

        for (int j = 1; j < N + 1; j++)
            v[i][j] = (T <= j) ? max(v[i - 1][j], I + v[i - 1][j - T]) : v[i - 1][j];
    }

    printf("%d", v[K][N]);
} 
