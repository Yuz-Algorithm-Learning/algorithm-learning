#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    
    vector<pair<long long, long long>> point;
    long long min_x = LLONG_MAX, min_y = LLONG_MAX, max_x = LLONG_MIN, max_y = LLONG_MIN;
    
    for(int i = 0; i < line.size() - 1; i++) {
        for(int j = 0; j < line.size(); j++) {
            long long adbc = (long long)line[i][0] * line[j][1] - line[i][1] * line[j][0];
            if(adbc == 0)
                continue;
            
            long long bfed = (long long)line[i][1] * line[j][2] - line[i][2] * line[j][1];
            long long ecaf = (long long)line[i][2] * line[j][0] - line[i][0] * line[j][2];
            
            if(!(bfed % adbc) && !(ecaf % adbc)) {
                long long x = bfed / adbc;
                long long y = ecaf / adbc;
                
                min_x = min(min_x, x); 
                min_y = min(min_y, y); 
                max_x = max(max_x, x); 
                max_y = max(max_y, y);

                point.emplace_back(x, y);
            }
        }
    }
    
    string row = string(max_x - min_x + 1, '.'); 
    vector<string> answer(max_y - min_y + 1, row);
    for (auto p : point) {
        answer[abs(p.second - max_y)][abs(p.first - min_x)] = '*';
    }
    
    return answer;
}