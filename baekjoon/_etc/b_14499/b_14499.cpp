#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};
vector<vector<int>> dir_num;

struct point {
    int center, up, down, left, right;
};

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    dir_num.resize(7, vector<int>(8));
    dir_num[1] = {2, 4, 5, 3, 2, 4, 5, 3}, dir_num[6] = {2, 3, 5, 4, 2, 3, 5, 4};
    dir_num[2] = {1, 3, 6, 4, 1, 3, 6, 4}, dir_num[5] = {1, 4, 6, 3, 1, 4, 6, 3};
    dir_num[3] = {1, 5, 6, 2, 1, 5, 6, 2}, dir_num[4] = {1, 2, 6, 5, 1, 2, 6, 5};

    int cur_y = x, cur_x = y;
    point map_dir = {6, 2, 5, 4, 3};
    vector<int> num(7);
    for(int i = 0; i < k; i++) {
        int dir;
        cin >> dir;

        cur_y += dy[dir];
        cur_x += dx[dir];
        if(cur_y < 0 || cur_y >= n || cur_x < 0 || cur_x >= m) {
            cur_y -= dy[dir];
            cur_x -= dx[dir];
            continue;
        }

        if(dir == 1) {
            map_dir.left = map_dir.center;
            map_dir.center = map_dir.right;

            for(int i = 1; i < 5; i++) {
                if(map_dir.left == dir_num[map_dir.center][i]) {
                    map_dir = {map_dir.center, dir_num[map_dir.center][i + 1], dir_num[map_dir.center][i - 1], dir_num[map_dir.center][i], dir_num[map_dir.center][i + 2]};
                    break;
                }
            }
        } else if(dir == 2) {
            map_dir.right = map_dir.center;
            map_dir.center = map_dir.left;

            for(int i = 1; i < 5; i++) {
                if(map_dir.right == dir_num[map_dir.center][i]) {
                    map_dir = {map_dir.center, dir_num[map_dir.center][i - 1], dir_num[map_dir.center][i + 1], dir_num[map_dir.center][i + 2], dir_num[map_dir.center][i]};
                    break;
                }
            }
        } else if(dir == 3) {
            map_dir.down = map_dir.center;
            map_dir.center = map_dir.up;

            for(int i = 1; i < 5; i++) {
                if(map_dir.down == dir_num[map_dir.center][i]) {
                    map_dir = {map_dir.center, dir_num[map_dir.center][i + 2], dir_num[map_dir.center][i], dir_num[map_dir.center][i + 1], dir_num[map_dir.center][i - 1]};
                    break;
                }
            }
        } else {
            map_dir.up = map_dir.center;
            map_dir.center = map_dir.down;

            for(int i = 1; i < 5; i++) {
                if(map_dir.up == dir_num[map_dir.center][i]) {
                    map_dir = {map_dir.center, dir_num[map_dir.center][i], dir_num[map_dir.center][i + 2], dir_num[map_dir.center][i - 1], dir_num[map_dir.center][i + 1]};
                    break;
                }
            }
        }

        if(map[cur_y][cur_x]) {
            num[map_dir.center] = map[cur_y][cur_x];
            map[cur_y][cur_x] = 0;
        } else {
            map[cur_y][cur_x] = num[map_dir.center];
        }

        cout << num[7 - map_dir.center] << '\n';
    }
}