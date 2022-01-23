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
    int min_num = 0;            

    vector<bool> visit(100001, false);
    queue<pair<int, int>> q;
    q.emplace(n, 0);

    while (!q.empty()) {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (min_result < cnt)
            break;

        visit[curr] = true;

        if (curr == k) {
            min_result = min(min_result, cnt);
            min_num++;
            continue;
        }

        if (curr - 1 >= 0 && !visit[curr - 1])
            q.emplace(curr - 1, cnt + 1);
        if (curr + 1 <= 100000 && !visit[curr + 1])
            q.emplace(curr + 1, cnt + 1);
        if (curr * 2 <= 100000 && !visit[curr * 2])
            q.emplace(curr * 2, cnt + 1);

    }

    printf("%d\n%d", min_result, min_num);

}
