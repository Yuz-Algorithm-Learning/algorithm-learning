#include <string>
#include <vector>
#include <cmath>

using namespace std;

int n;
int answer = 0;

void dfs(vector<int> &v, int col, int check) {
    if(check == n) {
        answer++;
        return;
    }
    
    for(int x = 1; x <= n; x++) {
        bool flag = true;
        
        for(int y = 1; y < col; y++) {
            if(v[y] == x || abs(x - v[y]) == abs(y - col)) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            v[col] = x;
            dfs(v, col + 1, check + 1);
            v[col] = 0;
        }
    }
}

int solution(int num) {
    n = num;
    
    vector<int> v(n + 1);
    
    dfs(v, 1, 0);
    return answer;
}