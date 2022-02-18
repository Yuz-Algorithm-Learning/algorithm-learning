#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int min_result = 987654321;      

    vector<bool> visit(100001, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, n);
    visit[n] = true;

    while (!q.empty()) {
        int cnt = q.top().first;
        int curr = q.top().second;
        q.pop();

        if (curr == k) {
            min_result = cnt;
            break;
        }

        if (curr * 2 <= 100000 && !visit[curr * 2]) {
            q.emplace(cnt, curr * 2);
            visit[curr * 2] = true;
        }
        if (curr + 1 <= 100000 && !visit[curr + 1]) {
            q.emplace(cnt + 1, curr + 1);
            visit[curr + 1] = true;
        }
        if (curr - 1 >= 0 && !visit[curr - 1]) {
            q.emplace(cnt + 1, curr - 1);
            visit[curr - 1] = true;
        }

    }

    printf("%d", min_result);

}