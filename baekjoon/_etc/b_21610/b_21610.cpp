#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

const int cross_dy[] = {-1, -1, 1, 1};
const int cross_dx[] = {-1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n ;i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    } 

    vector<pair<int, int>> cloud = {{n, 1}, {n, 2}, {n-1, 1}, {n-1, 2}};

    while(m--) {
        int d, s;
        cin >> d >> s;
        int ss = s % n;

        // 1
        for(int i = 0; i < cloud.size(); i++) {
            int y = cloud[i].first;
            int x = cloud[i].second;
            int tmp_ss = ss;

            while(tmp_ss--) {
                y += dy[d];
                if(y < 1) y = n;
                if(y > n) y = 1;
                x += dx[d];
                if(x < 1) x = n;
                if(x > n) x = 1;
            }

            cloud[i].first = y;
            cloud[i].second = x;
        }

        vector<vector<bool>> cloud_loc(n + 1, vector<bool>(n + 1));
        for(int i = 0; i < cloud.size(); i++)
            cloud_loc[cloud[i].first][cloud[i].second] = true;

        // 2
        for(int i = 0; i < cloud.size(); i++)
            board[cloud[i].first][cloud[i].second]++;

        // 4
        for(int i = 0; i < cloud.size(); i++) {
            int y = cloud[i].first;
            int x = cloud[i].second;
            int num = 0;

            for(int c = 0; c < 4; c++) {
                int ny = y + cross_dy[c];
                int nx = x + cross_dx[c];

                if(ny <= 0 || ny > n || nx <= 0 || nx > n || !board[ny][nx])
                    continue;
                num++;
            }
            board[y][x] += num;
        }

        // 5
        cloud.clear();
        for(int i = 1; i <= n ;i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j] >= 2 && !cloud_loc[i][j]) {
                    cloud.emplace_back(i, j);
                    board[i][j] -= 2;
                }
            }
        }

    }

    int sum = 0;
    for(int i = 1; i <= n ;i++) {
        for(int j = 1; j <= n; j++) {
            sum += board[i][j];
        }
    }

    cout << sum << '\n';
    return 0;
}