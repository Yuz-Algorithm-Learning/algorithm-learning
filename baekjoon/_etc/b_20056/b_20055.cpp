#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct Info {
    int m, s, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<Info>>> board(n + 1, vector<vector<Info>>(n + 1));
    for(int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({m, s, d});
    }

    while(k--) {
        // 1번
        vector<vector<vector<Info>>> next_board(n + 1, vector<vector<Info>>(n + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int b = 0; b < board[i][j].size(); b++) {
                    int mm = board[i][j][b].m;
                    int ss = board[i][j][b].s;
                    int dd = board[i][j][b].d;

                    int ny = i, nx = j, si = ss;
                    si = si % n;
                    while(si--) {
                        ny += dy[dd];
                        if(ny <= 0)
                            ny = n;
                        else if(ny > n)
                            ny = 1;

                        nx += dx[dd];
                        if(nx <= 0)
                            nx = n;
                        else if(nx > n)
                            nx = 1;
                    }

                    next_board[ny][nx].push_back({mm, ss, dd});
                }
            }
        }
        board = next_board;

        // 2번
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j].size() >= 2) {
                    int sum_m = 0, sum_s = 0;
                    bool is_same = true;
                    int dir = board[i][j][0].d % 2;
                    for(int b = 0; b < board[i][j].size(); b++) {
                        int mm = board[i][j][b].m;
                        int ss = board[i][j][b].s;
                        int dd = board[i][j][b].d;

                        sum_m += mm;
                        sum_s += ss;

                        if(dir != (dd % 2))
                            is_same = false;
                    }

                    int new_m = sum_m / 5;
                    int new_s = sum_s / board[i][j].size();
                    
                    board[i][j].clear();
                    if(new_m != 0) {
                        if(is_same) {
                            board[i][j].push_back({new_m, new_s, 0});   
                            board[i][j].push_back({new_m, new_s, 2});   
                            board[i][j].push_back({new_m, new_s, 4});   
                            board[i][j].push_back({new_m, new_s, 6});   
                        } else {
                            board[i][j].push_back({new_m, new_s, 1});   
                            board[i][j].push_back({new_m, new_s, 3});   
                            board[i][j].push_back({new_m, new_s, 5});   
                            board[i][j].push_back({new_m, new_s, 7}); 
                        }
                    }
                }
            }
        }
    }

    int total_m = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int b = 0; b < board[i][j].size(); b++) {
                total_m += board[i][j][b].m;
            }
        }
    }
    
    cout << total_m << '\n';

}