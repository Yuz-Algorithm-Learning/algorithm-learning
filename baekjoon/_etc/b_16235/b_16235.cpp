#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> old(n + 1, vector<vector<int>>(n + 1));
    vector<vector<int>> food(n + 1, vector<int>(n + 1, 5));
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int r, c, z;
        cin >> r >> c >> z;
        old[r][c].push_back(z);
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sort(old[i][j].begin(), old[i][j].end());
        }
    }

    while(k--) {
        // Spring, Summer
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(!old[i][j].empty()) {
                    
                    int idx = 0;
                    while(idx < old[i][j].size()) {
                        if(old[i][j][idx] <= food[i][j]) {
                            food[i][j] -= old[i][j][idx];
                            old[i][j][idx] += 1;
                            idx++;
                        } else {
                            break;
                        }
                    }

                    int erase_num = old[i][j].size() - idx;
                    while(erase_num--) {
                        food[i][j] += old[i][j][idx] / 2;
                        old[i][j].erase(old[i][j].begin() + idx);
                    }

                }
            }
        }

        // Autumn, Winter
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                
                for(int o = 0; o < old[i][j].size(); o++) {
                    if((old[i][j][o] % 5) == 0) {
                        for(int t = 0; t < 8; t++) {
                            int ny = i + dy[t];
                            int nx = j + dx[t];

                            if(ny < 1 || ny > n || nx < 1 || nx > n)
                                continue;
                            
                            old[ny][nx].insert(old[ny][nx].begin(), 1);
                        }
                    }
                }

                food[i][j] += a[i][j];
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans += old[i][j].size();
        }
    }

    cout << ans << '\n';
    return 0;
}