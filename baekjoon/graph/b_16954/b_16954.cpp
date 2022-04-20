#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char board[8][8];
bool visited[8][8];
const int dx[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    int cur_y = 7, cur_x = 0;
    visited[7][0] = true;
    queue<pair<int, int>> q;
    q.emplace(7, 0);
    int line = 7;
    while(!q.empty()) {
        int q_size = q.size();

        while(q_size--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i = 0; i < 9; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
            
                if(ny < 0 || ny > line || nx < 0 || nx >= 8)
                    continue;

                if(board[ny][nx] == '.') {
                    if(ny - 1 < 0) {
                        cout << "1\n";
                        return 0;
                    }

                    if(board[ny - 1][nx] == '.' && !visited[ny - 1][nx]) {
                        if(ny - 1 == 0) {
                            cout << "1\n";
                            return 0;
                        }
                        visited[ny - 1][nx] = true;
                        q.emplace(ny - 1, nx);
                    }
                }
            }
        }

        line--;
    }

    cout << "0\n";
    return 0;

}