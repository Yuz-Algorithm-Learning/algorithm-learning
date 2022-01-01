#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<long long> vec;
    vector<long long> ans(3, 0);
    long long result = 3000000001;
    
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%lld", &vec[i]);
    sort(vec.begin(), vec.end());

    for (int i = 0; i < (n - 2); i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            long long tmp = vec[i] + vec[l] + vec[r];
            if (abs(tmp) < result) {
                result = abs(tmp);
                ans[0] = vec[i], ans[1] = vec[l], ans[2] = vec[r];
            }

            (tmp < 0) ? l++ : r--;
        }

    }

    printf("%lld %lld %lld", ans[0], ans[1], ans[2]);
    return 0;
}
