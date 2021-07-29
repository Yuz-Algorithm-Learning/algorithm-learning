#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int g[MAX];

int main()
{
    int n;
    scanf("%d", &n);

    g[1] = 1;
    
    int idx = 1;
    int sum = 1;

    while (sum < n) {
        idx++;
        g[idx] = 1 + g[idx - g[g[idx - 1]]];
        sum += g[idx];
    }

    printf("%d", idx);
}
