#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<vector<string>> relation;
vector<string> minimality;
int row, col;

bool check_uniqueness(string col_str) {
    map<string, bool> tp;
    
    for(int i = 0; i < row; i++) {
        string str = "";
        for(int j = 0; j < col_str.size(); j++) {
            str += (relation[i][col_str[j] - '0']);
        }

        if(tp[str])
            return false;
        else
            tp[str] = true;
    }
    
    return true;
}

bool check_minimality(string col_str) {
    if(col_str.size() == 1)
        return true;
    
    for(int i = 0; i < minimality.size(); i++) {
        int num = 0;
        for(int p = 0; p < minimality[i].size(); p++) {
            for(int q = 0; q < col_str.size(); q++) {
                if(minimality[i][p] == col_str[q]) {
                    num++;     
                }
            }
        }
        
        if(num == minimality[i].size())
            return false;
    }
    
    return true;
}

int solution(vector<vector<string>> re) {
    int answer = 0;
    
    relation = re;
    row = relation.size();
    col = relation[0].size();

    for(int idx = 1; idx <= col; idx++) {
        vector<bool> visit(col);
        for(int i = 0; i < idx; i++)
            visit[i] = true;
        
        do {
            string tmp = "";
            for(int i = 0; i < col; i++) {
                if(visit[i]) {
                    tmp += (i + '0');
                }
            }
            
            if(check_uniqueness(tmp) && check_minimality(tmp)) {
                minimality.push_back(tmp);
                answer++;
            }
            
        } while (prev_permutation(visit.begin(), visit.end()));
        
    }
        
    return answer;
}