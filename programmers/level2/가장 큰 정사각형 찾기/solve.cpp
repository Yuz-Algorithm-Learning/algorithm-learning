#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{   
    int answer = min(board.size(), board[0].size());
    
    if(answer == 1)
        return 1;
    
    int max_board = 0;
    for(int i = 1; i < board.size(); i++) {
        for(int j = 1; j < board[0].size(); j++) {
            if(board[i][j]) {
                board[i][j] = 1 + min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]});
                max_board = max(max_board, board[i][j]);
            }
        }
    }

    return max_board * max_board;
}