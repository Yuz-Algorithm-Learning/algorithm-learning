#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<bool> visited;
vector<vector<int>> com;

void dfs(int num) {
    visited[num] = true;
    
    for(auto c : com[num]) {
        if(!visited[c]) {
            dfs(c);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    if(computers.size() == 1)
        return 1;
    
    visited.resize(computers.size());
    com.resize(computers.size());
    for(int i = 0; i < computers.size(); i++) {
        for(int j = i + 1; j < computers[i].size(); j++) {
            if(computers[i][j]) {
                com[i].push_back(j);
                com[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < com.size(); i++) {
        if(!visited[i]) {
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}