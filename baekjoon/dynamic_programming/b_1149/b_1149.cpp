#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int main()
{
    int n;
    vector<vector<int>> rgb;
    vector<vector<int>> sum;

    scanf("%d", &n);

    rgb.resize(n, vector<int>(3, 0));
    sum.resize(n, vector<int>(3, INF));

    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);


    sum[0][0] = rgb[0][0], sum[0][1] = rgb[0][1], sum[0][2] = rgb[0][2];
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    sum[i + 1][k] = min(sum[i][j] + rgb[i + 1][k], sum[i + 1][k]);
                }
            }
        }
    }

    printf("%d", min({ sum[n - 1][0], sum[n - 1][1], sum[n - 1][2] }));
}
