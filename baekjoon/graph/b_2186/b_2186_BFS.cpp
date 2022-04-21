#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int visited[100][100][80];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    string word;
    cin >> word;

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == word[0]) {
                q.emplace(i, j);
                visited[i][j][0]++;
            }
        }
    }

    int num = 1;
    while(!q.empty()) {
        if(num == word.size())
            break;
        int q_size = q.size();

        while(q_size--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int d = 1; d <= k; d++) {
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i] * d;
                    int nx = x + dx[i] * d;

                    if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;

                    if(board[ny][nx] == word[num]) {
                        if(!visited[ny][nx][num]) {
                            q.emplace(ny, nx);
                        }
                        visited[ny][nx][num] += visited[y][x][num - 1];
                    }
                }
            }
        }

        num++;
    }

    int sum = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        sum += visited[y][x][word.size() - 1];
    }

    cout << sum << '\n';
    
}