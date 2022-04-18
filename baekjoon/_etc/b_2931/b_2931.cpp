#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Dir {
    bool up, bottom, left, right;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;
    vector<vector<Dir>> board(r + 2, vector<Dir>(c + 2));
    int m_y, m_x, z_y, z_x;
    for(int i = 1; i <= r; i++) {
        string str;
        cin >> str;

        for(int j = 1; j <= c; j++) {
            if(str[j - 1] == '|') {
                board[i][j].up = true;
                board[i][j].bottom = true;
            } else if(str[j - 1] == '-') {
                board[i][j].left = true;
                board[i][j].right = true;
            } else if(str[j - 1] == '+') {
                board[i][j].up = true;
                board[i][j].bottom = true;
                board[i][j].left = true;
                board[i][j].right = true;
            } else if(str[j - 1] == '1') {
                board[i][j].right = true;
                board[i][j].bottom = true;
            } else if(str[j - 1] == '2') {
                board[i][j].up = true;
                board[i][j].right = true;
            } else if(str[j - 1] == '3') {
                board[i][j].left = true;
                board[i][j].up = true;
            } else if(str[j - 1] == '4') {
                board[i][j].left = true;
                board[i][j].bottom = true;
            } else if(str[j - 1] == 'M') {
                m_y = i;
                m_x = j;
            } else if(str[j - 1] == 'Z') {
                z_y = i;
                z_x = j;
            }
        }
    }

    int y = 0, x = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(i == z_y && j == z_x) continue;
            if(i == m_y && j == m_x) continue;

            if(board[i][j].up) {
                if(!((i - 1) == m_y && j == m_x) && !((i - 1) == z_y && j == z_x)) {
                    if(!board[i - 1][j].bottom) {
                        y = i - 1;
                        x = j;
                        break;
                    }
                }
            }
            if(board[i][j].bottom) {
                if(!((i + 1) == m_y && j == m_x) && !((i + 1) == z_y && j == z_x)) {
                    if(!board[i + 1][j].up) {
                        y = i + 1;
                        x = j;
                        break;
                    }
                }
            }
            if(board[i][j].left) {
                if(!(i == m_y && (j - 1) == m_x) && !(i == z_y && (j - 1) == z_x)) {
                    if(!board[i][j - 1].right) {
                        y = i;
                        x = j - 1;
                        break;
                    }
                }
            }
            if(board[i][j].right) {
                if(!(i == m_y && (j + 1) == m_x) && !(i == z_y && (j + 1) == z_x)) {
                    if(!board[i][j + 1].left) {
                        y = i;
                        x = j + 1;
                        break;
                    }
                }
            }
        }
    }

    if(board[y - 1][x].bottom)  board[y][x].up = true;
    if(board[y + 1][x].up)      board[y][x].bottom = true;
    if(board[y][x - 1].right)   board[y][x].left = true;
    if(board[y][x + 1].left)    board[y][x].right = true;

    if(board[y][x].up && board[y][x].bottom && board[y][x].left && board[y][x].right) {
        cout << y << " " << x << " +\n";
    } else if(board[y][x].up && board[y][x].bottom) {
        cout << y << " " << x << " |\n";
    } else if(board[y][x].left && board[y][x].right) {
        cout << y << " " << x << " -\n";
    } else if(board[y][x].bottom && board[y][x].right) {
        cout << y << " " << x << " 1\n";
    } else if(board[y][x].up && board[y][x].right) {
        cout << y << " " << x << " 2\n";
    } else if(board[y][x].up && board[y][x].left) {
        cout << y << " " << x << " 3\n";
    } else if(board[y][x].bottom && board[y][x].left) {
        cout << y << " " << x << " 4\n";
    }

    return 0;
}