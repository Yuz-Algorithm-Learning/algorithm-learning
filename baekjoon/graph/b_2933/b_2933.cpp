#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C;
string cave[101];
bool visit[101][101] = { 0 };
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

bool is_levitation() {
    queue<pair<int, int>> q;
    memset(visit, 0, sizeof(visit));

    visit[R][0] = 1;
    q.emplace(R, 0);

    while(!q.empty()) {
        int curr_x = q.front().second;
        int curr_y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int _x = curr_x + dx[i];
            int _y = curr_y + dy[i];

            if (_x >= 0 && _x < C && _y >= 0 && _y <= R) {
                if (cave[_y][_x] == 'x' && !visit[_y][_x]) {
                    q.emplace(_y, _x);
                    visit[_y][_x] = 1;
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cave[i][j] == 'x' && !visit[i][j]) {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        cin >> cave[i];
    for (int i = 0; i < C; i++)
        cave[R].push_back('x');

    int count;
    cin >> count;

    int height;
    for (int i = 1; i <= count; i++) {
        cin >> height;

        // 미네랄 제거
        bool mineral = 0;
        if (i % 2) {    // 홀수
            for (int j = 0; j < C; j++) {
                if (cave[R - height][j] == 'x') {
                    mineral = 1;
                    cave[R - height][j] = '.';
                    break;
                }
            }
        }
        else {          // 짝수
            for (int j = C - 1; j >= 0; j--) {
                if (cave[R - height][j] == 'x') {
                    mineral = 1;
                    cave[R - height][j] = '.';
                    break;
                }
            }
        }

        // 공중에 떠있는 미네랄 클러스터가 있는지 확인
        if (mineral) {
            if (is_levitation()) {
                // 중력에 의해서 바닥으로 떨어짐
                int drop = R;
                for (int c = 0; c < C; c++) {
                    for (int r = 0; r < R; r++) {
                        if (cave[r][c] == 'x' && !visit[r][c]) {
                            int h = 0;

                            for (int _r = r + 1; _r <= R; _r++) {
                                if (cave[_r][c] == 'x' && visit[_r][c]) {
                                    drop = min(drop, h);
                                    break;
                                }
                                else
                                    h++;
                            }
                        }
                    }
                }

                for (int c = 0; c < C; c++) {
                    for (int r = R - 1; r >= 0; r--) {
                        if (cave[r][c] == 'x' && !visit[r][c]) {
                            cave[r + drop][c] = 'x';
                            cave[r][c] = '.';
                        }
                    }
                }
            
            }
        }

    }

    for (int r = 0; r < R; r++)
        cout << cave[r] << "\n";
}
 
