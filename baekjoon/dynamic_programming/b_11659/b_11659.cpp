#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> sum(n + 1);
    int s = 0;
    for(int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        s += tmp;
        sum[i] = s;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
}