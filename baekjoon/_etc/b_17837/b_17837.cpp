#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct myDir {
    int num, dd;        /* 말 번호, 방향 */
};

struct point {
    int yy, xx, index;  /* 말 좌표, 해당 좌표의 말 번호(deque의 idx) */
};

const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};
int n, k;
vector<vector<deque<myDir>>> moved;

point currFind(int cur) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int m = 0; m < moved[i][j].size(); m++) {
                if(moved[i][j][m].num == cur) {
                    return {i, j, m};
                }
            }
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    vector<vector<int>> board(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    moved.resize(n + 1, vector<deque<myDir>>(n + 1));
    for(int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        moved[a][b].push_back({i, c});
    }

    int ans = 0;
    bool game_over = false;
    while(1) {
        ans++;
        
        for(int r = 1; r <= k; r++) {
            point curr = currFind(r);
            int y = curr.yy;
            int x = curr.xx;
            int idx = curr.index;
            int dir = moved[y][x][idx].dd;

            // 다음칸 알아보기
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 범위 넘어가면 이동 방향 바꾸고 한 칸 이동
            // 한 칸 이동했을 때 파랑 or 맵 바깥 -> 정지
            //               빨강 -> 역으로 쌓기
            //               하양 -> 정방향으로 쌓기
            if(ny <= 0 || ny > n || nx <= 0 || nx > n) {
                if(dir == 1) dir = 2;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 4;
                else dir = 3;

                ny = y + dy[dir];
                nx = x + dx[dir];

                // 방향 바꾸기
                moved[y][x][idx].dd = dir;

                // 이동
                if(board[ny][nx] == 2) {
                    continue;
                } else {
                    if(board[ny][nx] == 0) {        // 흰색이면 정방향으로
                        for(int i = idx; i >= 0; i--) {
                            moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                        }
                    } else if(board[ny][nx] == 1) { // 빨간색이면 역으로
                        for(int i = 0; i <= idx; i++) {
                            moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                        }
                    }
                }
                // 이전 내역 삭제
                for(int i = 0; i <= idx; i++) {
                    moved[y][x].pop_front();
                }
                
            } 
            // 파랑일 때
            else if(board[ny][nx] == 2) {
                if(dir == 1) dir = 2;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 4;
                else dir = 3;

                ny = y + dy[dir];
                nx = x + dx[dir];

                // 방향 바꾸기
                moved[y][x][idx].dd = dir;
                
                // 범위 넘어가면 그대로 위치
                if(ny <= 0 || ny > n || nx <= 0 || nx > n) {
                    continue;
                }

                // 이동
                if(board[ny][nx] == 2) {
                    continue;
                } else {
                    if(board[ny][nx] == 0) {        // 흰색이면 정방향으로
                        for(int i = idx; i >= 0; i--) {
                            moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                        }
                    } else if(board[ny][nx] == 1) { // 빨간색이면 역으로
                        for(int i = 0; i <= idx; i++) {
                            moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                        }
                    }
                }

                // 이전 내역 삭제
                for(int i = 0; i <= idx; i++) {
                    moved[y][x].pop_front();
                }
            }
            // 흰색일 때
            else if(board[ny][nx] == 0) {
                
                // 정방향 이동
                for(int i = idx; i >= 0; i--) {
                    moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                }
                // 이전 내역 삭제
                for(int i = 0; i <= idx; i++) {
                    moved[y][x].pop_front();
                }
                
            }
            // 빨간색일 때
            else if(board[ny][nx] == 1) {
                // 역방향 이동
                for(int i = 0; i <= idx; i++) {
                    moved[ny][nx].push_front({moved[y][x][i].num, moved[y][x][i].dd});
                }
                // 이전 내역 삭제
                for(int i = 0; i <= idx; i++) {
                    moved[y][x].pop_front();
                }
            }

            if(moved[ny][nx].size() >= 4) {
                game_over = true;
                break;
            }

        }

        if(game_over || ans >= 1000) break;
    }

    if(ans != 1000)
        cout << ans << '\n';
    else
        cout << "-1\n";
    return 0;
}