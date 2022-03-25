#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> v(n, vector<int>(n));
    int dir = 0;
    int y = 0, x = 0;
    int cnt = n;
    int num = 1;
    while(cnt) {
        int tmp_cnt = cnt;
        
        while(tmp_cnt--) {
            if(dir == 0) {
                v[y][x] = num++;
                (tmp_cnt != 0)? y++ : x++;
            } else if(dir == 1) {
                v[y][x] = num++;
                if(tmp_cnt != 0)
                    x++;
                else {
                    y--, x--;
                }
            } else {
                v[y][x] = num++;
                if(tmp_cnt != 0) {
                    y--, x--;
                } else 
                    y++;
            }
        }
        
        dir = (dir == 2)? 0 : dir + 1;
        cnt--;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}