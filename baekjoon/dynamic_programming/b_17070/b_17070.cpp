#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> not_move(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &not_move[i][j]);
        }
    }

    /* 가로: 0, 대각선: 1, 세로: 2 */
    vector<vector<tuple<int, int, int>>> map(n, vector<tuple<int, int, int>>(n));
    get<0>(map[0][1]) = 1;
    get<0>(map[0][0]) = 1;

    for(int y = 0; y < n; y++) {
        for(int x = 2; x < n; x++) {
            if(not_move[y][x])
                continue;
            
            for(int d = 0; d < 3; d++) {
                int by = y - dy[d];
                int bx = x - dx[d];

                if(by < 0 || by >= n || bx < 0 || bx >= n)
                    continue;
                
                if(d == 0) {
                    get<0>(map[y][x]) = get<0>(map[by][bx]) + get<1>(map[by][bx]);
                } else if (d == 1) {
                    if(not_move[by][bx + 1] || not_move[by + 1][bx])
                        get<1>(map[y][x]) = 0;
                    else
                        get<1>(map[y][x]) = get<0>(map[by][bx]) + get<1>(map[by][bx]) + get<2>(map[by][bx]);
                } else {
                    get<2>(map[y][x]) = get<1>(map[by][bx]) + get<2>(map[by][bx]);
                }
            }

        }
    }

    int ans = get<0>(map[n - 1][n - 1]) + get<1>(map[n - 1][n - 1]) + get<2>(map[n - 1][n - 1]);
    printf("%d\n", ans);

}