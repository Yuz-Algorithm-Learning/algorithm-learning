#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> tt(n + 1);
    tt[1] = 1, tt[2] = 3;

    for (int i = 3; i <= n; i++) {
        tt[i] = (tt[i - 1] + tt[i - 2] * 2) % 10007;
    }

    printf("%d", tt[n]);
}
