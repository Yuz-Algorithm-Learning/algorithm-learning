#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<string> ws;
string tg;
int answer = 987654321;

bool is_change(string s1, string s2) {
    int diff = 0;
    
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i])
            diff++;
    }
    
    return (diff == 1)? true : false;
}

void dfs(string word, int num) {
    if(word == tg) {
        answer = min(answer, num);
        return;
    }
    
    for(int i = 0; i < ws.size(); i++) {
        if(!visited[i]) {
            if(is_change(word, ws[i])) {
                visited[i] = true;
                dfs(ws[i], num + 1);
                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    ws = words;
    tg = target;
    visited.resize(ws.size());
    
    bool is_target = false;
    for(int i = 0; i < ws.size(); i++) {
        if(ws[i] == target) {
            is_target = true;
        }
    }
    if(!is_target)
        return 0;
        
    dfs(begin, 0);
    return answer;
}