#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> ori(n);
    vector<int> map(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ori[i]);
    }

    map = ori;
    sort(map.begin(), map.end());
    map.erase(unique(map.begin(), map.end()), map.end());

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(map.begin(), map.end(), ori[i]) - map.begin();
        printf("%d ", idx);
    }

}
