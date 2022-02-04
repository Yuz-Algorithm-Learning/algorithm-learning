#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int tmp;
        scanf("%d", &tmp);

        vector<pair<int, int>> f;
        f.emplace_back(1, 0);
        f.emplace_back(0, 1);
        
        for (int j = 2; j <= tmp; j++) {
            f.emplace_back(f[j - 1].first + f[j - 2].first,  f[j - 1].second + f[j - 2].second);
        }

        printf("%d %d\n", f[tmp].first, f[tmp].second);
    }
}
