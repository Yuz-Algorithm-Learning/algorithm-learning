#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1) {
        vector<vector<bool>> visit(m, vector<bool>(n));
        bool erase = false;
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(board[i][j] != ' ' && board[i][j] == board[i][j + 1] 
                   && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
                    erase = true;
                    visit[i][j] = visit[i][j + 1] = visit[i + 1][j] = visit[i + 1][j + 1] = true;
                }
            }
        }
        
        if(erase) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(visit[i][j])
                        board[i][j] = ' ';
                }
            }

            for(int j = 0; j < n; j++) {
                string tmp = "", tmp1 = "";
                for(int i = m - 1; i >= 0; i--) {
                    tmp += board[i][j];
                }
                for(int i = 0; i < m; i++) {
                    if(tmp[i] != ' ')
                        tmp1 += tmp[i];
                }

                int idx = 0;
                for(int i = m - 1; i >= 0; i--) {
                    if(idx < tmp1.size()){
                        board[i][j] = tmp1[idx];
                        idx++;
                    } else {
                        board[i][j] = ' ';
                    }
                }
            }
            
        } else {
            break;
        }
        
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == ' ')
                answer++;
        }
    }
    
    return answer;
}