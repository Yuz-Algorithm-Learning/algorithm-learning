#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {-1, 0};
const int dx[] = {0, -1};
vector<vector<int>> board;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    board.resize(s2.size() + 1, vector<int>(s1.size() + 1));
    for(int i = 1; i <= s2.size(); i++) {
        for(int j = 1; j <= s1.size(); j++) {
            if(s2[i - 1] != s1[j - 1]) {
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
            } else {
                board[i][j] = board[i - 1][j - 1] + 1;
            }
        }
    }


    // LCS 역추적
    int y = s2.size();
    int x = s1.size();
    string rst;
    while(board[y][x] != 0) {
        if(board[y][x] == board[y - 1][x])
            y--;
        else if(board[y][x] == board[y][x - 1])
            x--;
        else {
            rst += s1[x - 1];
            y--, x--;
        }
    }

    reverse(rst.begin(), rst.end());
    cout << rst.size() << '\n' << rst << '\n';
    return 0;
}