#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
vector<vector<int>> room;
vector<vector<pair<int, int>>> cctv_info;
vector<int> cctv_num;
int cctv_idx = 0;
int ans = 987654321;

void make_cctv(int start_y, int start_x) {
    for(int i = 0; i < 4; i++) {    
        vector<vector<int>> tmp(n, vector<int>(m));
        int ny = start_y;
        int nx = start_x;

        while(1) {
            ny += dy[i];
            nx += dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 6)
                break;
            
            cctv_info[cctv_idx].emplace_back(ny, nx);
        }

        cctv_idx++;
    }
}

void dfs(int idx, vector<vector<int>> r) {
    if(idx == cctv_num.size()) {
        int tmp_ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(r[i][j] == 0)
                    tmp_ans++;
            }
        }
        ans = min(ans, tmp_ans);
        return;
    }

    int type = cctv_num[idx];
    vector<vector<int>> tmp = r;

    if(type == 1) {
        for(int i = 0; i < 4; i++) {
            for(int c = 0; c < cctv_info[4 * idx + i].size(); c++) {
                tmp[cctv_info[4 * idx + i][c].first][cctv_info[4 * idx + i][c].second] = 7;
            }
            dfs(idx + 1, tmp);
            tmp = r;
        }
    } else if(type == 2) {
        for(int i = 0; i < 2; i++) {
            for(int c = 0; c < cctv_info[4 * idx + i].size(); c++) {
                tmp[cctv_info[4 * idx + i][c].first][cctv_info[4 * idx + i][c].second] = 7;
            }
            for(int c = 0; c < cctv_info[4 * idx + i + 2].size(); c++) {
                tmp[cctv_info[4 * idx + i + 2][c].first][cctv_info[4 * idx + i + 2][c].second] = 7;
            }
            dfs(idx + 1, tmp);
            tmp = r;
        }
    } else if(type == 3) {
        for(int i = 0; i < 4; i++) {
            for(int c = 0; c < cctv_info[4 * idx + i].size(); c++) {
                tmp[cctv_info[4 * idx + i][c].first][cctv_info[4 * idx + i][c].second] = 7;
            }
            if(i != 3) {
                for(int c = 0; c < cctv_info[4 * idx + i + 1].size(); c++) {
                    tmp[cctv_info[4 * idx + i + 1][c].first][cctv_info[4 * idx + i + 1][c].second] = 7;
                }
            } else {
                for(int c = 0; c < cctv_info[4 * idx].size(); c++) {
                    tmp[cctv_info[4 * idx][c].first][cctv_info[4 * idx][c].second] = 7;
                }
            }
            dfs(idx + 1, tmp);
            tmp = r;
        }
    } else if(type == 4) {
        for(int i = 0; i < 4; i++) {
            for(int c = 0; c < cctv_info[4 * idx + i].size(); c++) {
                tmp[cctv_info[4 * idx + i][c].first][cctv_info[4 * idx + i][c].second] = 7;
            }
            if(i + 1 <= 3) {
                for(int c = 0; c < cctv_info[4 * idx + i + 1].size(); c++) {
                    tmp[cctv_info[4 * idx + i + 1][c].first][cctv_info[4 * idx + i + 1][c].second] = 7;
                } 
            } else {
                for(int c = 0; c < cctv_info[4 * idx + i + 1 - 4].size(); c++) {
                    tmp[cctv_info[4 * idx + i + 1 - 4][c].first][cctv_info[4 * idx + i + 1 - 4][c].second] = 7;
                } 
            }
            if(i + 2 <= 3) {
                for(int c = 0; c < cctv_info[4 * idx + i + 2].size(); c++) {
                    tmp[cctv_info[4 * idx + i + 2][c].first][cctv_info[4 * idx + i + 2][c].second] = 7;
                } 
            } else {
                for(int c = 0; c < cctv_info[4 * idx + i + 2 - 4].size(); c++) {
                    tmp[cctv_info[4 * idx + i + 2 - 4][c].first][cctv_info[4 * idx + i + 2 - 4][c].second] = 7;
                } 
            }
            dfs(idx + 1, tmp);
            tmp = r;
        }
    } else if(type == 5) {
        for(int i = 0; i < 4; i++) {
            for(int c = 0; c < cctv_info[4 * idx + i].size(); c++) {
                tmp[cctv_info[4 * idx + i][c].first][cctv_info[4 * idx + i][c].second] = 7;
            }
        }
        dfs(idx + 1, tmp);
        tmp = r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    room.resize(n, vector<int>(m));
    cctv_info.resize(33);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(room[i][j] != 0 && room[i][j] != 6) {
                cctv_num.push_back(room[i][j]);
                make_cctv(i, j);
            }
        }
    }

    dfs(0, room);
    cout << ans << '\n';
}