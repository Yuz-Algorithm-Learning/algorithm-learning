#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
 
vector<string> user;
vector<string> banned;
vector<bool> visited(9);
set<string> s;
 
void dfs(int index) {
 
    if (index == banned.size()) {
        string tmp = "";
        for (int i = 0; i < user.size(); i++) {
            if (visited[i]) {
                tmp += user[i];
            }
        }
        
        s.insert(tmp);
        return;
    }
 
    for (int i = 0; i < user.size(); i++) {
        if (visited[i])
            continue;
 
        if (user[i].length() != banned[index].length())
            continue;

        bool is_able = true;
        for (int j = 0; j < user[i].length(); j++) {
            if (banned[index][j] == '*') {
                continue;
            }
            if (banned[index][j] != user[i][j]) {
                is_able = false;
                break;
            }
        }
 
        if (is_able) {
            visited[i] = true;
            dfs(index + 1);
            visited[i] = false;
        }
    }
    
    return;
}
 
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
 
    user = user_id;
    banned = banned_id;
 
    dfs(0);
    answer = s.size();
 
    return answer;
}