#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> lis;

    int tmp;
    scanf("%d", &tmp);
    lis.push_back(tmp);

    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        if (lis.back() < tmp) {
            lis.push_back(tmp);
            max_idx++;
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), tmp) - lis.begin();
            lis[idx] = tmp;
        }
    }

    printf("%d", max_idx + 1);
}