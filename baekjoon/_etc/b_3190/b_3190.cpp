#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> map(n + 1, vector<int>(n + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }

    int l;
    cin >> l;
    queue<pair<int, char>> info_q;
    for(int i = 0; i < l; i++) {
        int t;
        char type;
        cin >> t >> type;

        info_q.emplace(t, type);
    }

    int time = 1;
    int dir = 0;
    int cur_y = 1, cur_x = 1;
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    visited[1][1] = true;
    while(1) {
        cur_y += dy[dir];
        cur_x += dx[dir];   
        if(cur_y <= 0 || cur_y > n || cur_x <= 0 || cur_x > n) break;
        if(visited[cur_y][cur_x]) break;

        q.emplace(cur_y, cur_x);
        visited[cur_y][cur_x] = true;

        if(!map[cur_y][cur_x]) {
            visited[q.front().first][q.front().second] = false;
            q.pop();
        } else {
            map[cur_y][cur_x] = 0;
        }

        if(!info_q.empty()) {
            if(info_q.front().first == time) {
                if(info_q.front().second == 'D') {
                    dir = (dir == 3)? 0 : dir + 1;
                } else {
                    dir = (dir == 0)? 3 : dir - 1;
                }

                info_q.pop();
            }
        }

        time++;
    }

    cout << time << '\n';
}