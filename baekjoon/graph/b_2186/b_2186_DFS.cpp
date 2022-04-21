#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int n, m, k;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int dp[100][100][80];
vector<string> board;
string word;

int dfs(int y, int x, int idx) {
    if(idx == word.size())
        return 1;
    if(dp[y][x][idx - 1] != -1)
        return dp[y][x][idx - 1];

    dp[y][x][idx - 1] = 0;
    for(int d = 1; d <= k; d++) {
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i] * d;
            int nx = x + dx[i] * d;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if(word[idx] == board[ny][nx]) {
                dp[y][x][idx - 1] += dfs(ny, nx, idx + 1);
            }
        }
    }

    return dp[y][x][idx - 1]; 
}

int main() {
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));
    board.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    cin >> word;

    int path = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == word[0]) {
                path += dfs(i, j, 1);
            }
        }
    }

    cout << path << '\n';
    return 0;
    
}