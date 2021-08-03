#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    vector<pair<long long, long long>> carrot_info(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &carrot_info[i].second, &carrot_info[i].first);

    sort(carrot_info.begin(), carrot_info.end());

    long long carrot = 0;
    for (int i = 0; i < N; i++)
        carrot += carrot_info[i].second + carrot_info[i].first * ((long long)T - N + i);

    printf("%lld", carrot);
}