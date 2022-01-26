#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> move(101, 0);
    vector<int> cnt(101, -1);

    for (int i = 0; i < n + m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        move[a] = b;
    }

    queue<int> loc;
    loc.push(1);
    cnt[1] = 0;

    while (!loc.empty()) {
        int curr = loc.front();
        loc.pop();

        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next > 100)
                continue;

            if (move[next])
                next = move[next];

            if (cnt[next] == -1) {
                cnt[next] = cnt[curr] + 1;
                loc.push(next);
            }
        }
    }

    printf("%d", cnt[100]);
    return 0;
}
