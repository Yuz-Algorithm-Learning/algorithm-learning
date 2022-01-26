#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int house_cnt;
vector<vector<int>> map;
vector<vector<bool>> visit;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
    house_cnt++;
    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if (map[nx][ny] == 1 && !visit[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    map.resize(n, vector<int>(n));
    visit.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < n; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visit[i][j]) {
                house_cnt = 0;
                dfs(i, j);
                ans.push_back(house_cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

}
