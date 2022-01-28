#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> info;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        info.emplace_back(a, b);
    }
    sort(info.begin(), info.end(), compare);

    int end = info[0].second;
    int cnt = 1;
    for (int i = 1; i < info.size(); i++) {
        if (end <= info[i].first) {
            cnt++;
            end = info[i].second;
        }
    }

    printf("%d", cnt);
}
