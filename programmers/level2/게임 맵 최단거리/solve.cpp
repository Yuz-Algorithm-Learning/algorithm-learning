#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int solution(vector<vector<int>> maps)
{   
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dis(n, vector<int>(m));
    dis[0][0] = 1;
    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if(maps[ny][nx] == 1 && !dis[ny][nx]) {
                dis[ny][nx] = dis[y][x] + 1;
                q.emplace(ny, nx);
            }

            if(ny == n - 1 && nx == m - 1) {
                return dis[ny][nx];
            }
        }
    }

    return -1;
}