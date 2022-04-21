#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
int n;
int shark_y, shark_x;
int shark_size = 2;
int space[21][21];
bool is_eat[21][21];

int bfs(int sy, int sx) {
    int time = 1;
    bool visited[21][21] = {0, };
    queue<pair<int, int>> q;
    q.emplace(sy, sx);
    visited[sy][sx] = true;

    while(!q.empty()) {
        int q_size = q.size();
        vector<pair<int, int>> v;

        while(q_size--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;
                
                if(space[ny][nx] <= shark_size && !visited[ny][nx]) {
                    if(space[ny][nx] && (space[ny][nx] < shark_size) && !is_eat[ny][nx]) {
                        v.emplace_back(ny, nx);
                    } else {
                        visited[ny][nx] = true;
                        q.emplace(ny, nx);
                    }
                }

            }
        }

        if(!v.empty()) {
            sort(v.begin(), v.end());
            is_eat[v[0].first][v[0].second] = true;
            shark_y = v[0].first;
            shark_x = v[0].second;
            return time;
        }

        time++;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> space[i][j];

            if(space[i][j] == 9) {
                shark_y = i;
                shark_x = j;
                space[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    int total_time = 0;
    while(1) {
        int tmp_time = bfs(shark_y, shark_x);
        if(tmp_time) {
            cnt++;
            total_time += tmp_time;
        } else
            break;

        if(cnt == shark_size) {
            shark_size++;
            cnt = 0;
        }
    }
        
    cout << total_time << '\n';
    return 0;

}