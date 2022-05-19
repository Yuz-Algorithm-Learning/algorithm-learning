#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

int dis[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dis, -1, sizeof(dis));
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});

    dis[n] = 0;
    int ans_cur = -1, ans_cnt = -1;
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == k) {
            ans_cur = cur;
            ans_cnt = cnt;
            break;
        }

        if(cur + 1 <= 100000 && dis[cur + 1] == -1) {
            q.emplace(cur + 1, cnt + 1);
            dis[cur + 1] = cur;
        } 
        if(cur - 1 >= 0 && dis[cur - 1] == -1) {
            q.emplace(cur - 1, cnt + 1);
            dis[cur - 1] = cur;
        }
        if(cur * 2 <= 100000 && dis[cur * 2] == -1) {
            q.emplace(cur * 2, cnt + 1);
            dis[cur * 2] = cur;
        }
            
    }

    vector<int> rst;
    while(1) {
        if(ans_cur == n) break;

        rst.push_back(ans_cur);
        ans_cur = dis[ans_cur];
    }
    rst.push_back(n);
    reverse(rst.begin(), rst.end());

    cout << ans_cnt << '\n';
    for(auto re : rst)
        cout << re << " ";

    return 0;
}