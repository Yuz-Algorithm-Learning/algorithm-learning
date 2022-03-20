#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int line_size;

void dfs(int num) {
    visited[num] = true;
    line_size++;
    
    for(auto node : tree[num]) {
        if(!visited[node])
            dfs(node);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    for(int i = 0; i < wires.size(); i++) {
        line_size = 0;
        tree.resize(n + 1);
        visited.resize(n + 1);
        int r1, r2;
        
        for(int j = 0; j < wires.size(); j++) {
            if(j == i) {
                r1 = wires[j][0];
                r2 = wires[j][1];
                continue;
            }
            
            tree[wires[j][0]].push_back(wires[j][1]);
            tree[wires[j][1]].push_back(wires[j][0]);
        }
        
        if(tree[r1].size() == 0) {
            dfs(r2);
        } else if(tree[r2].size() == 0) {
            dfs(r1);
        } else {
            dfs(r1);
        }
        
        answer = min(answer, abs(abs(n - line_size) - line_size));
        tree.clear();
        visited.clear();
    }
    
    return answer;
}