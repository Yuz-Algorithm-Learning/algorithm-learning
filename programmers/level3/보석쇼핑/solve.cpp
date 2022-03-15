#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, bool> g;
    map<string, int> gg_info;
    
    for(int i = 0; i < gems.size(); i++)
        g[gems[i]] = true;
    int gem_num = g.size();
    
    int tmp_l = 0, tmp_r = 0;
    int left = 0, right = gems.size();
    queue<string> q;
    
    while(tmp_r < gems.size()) {
        q.push(gems[tmp_r]);
        gg_info[gems[tmp_r]]++;
        
        if(gg_info.size() == gem_num) {
            while(gg_info.size() == gem_num) {
                if(tmp_r - tmp_l < right - left) {
                    right = tmp_r;
                    left = tmp_l;
                }
            
                gg_info[q.front()]--;
                if(!gg_info[q.front()])
                    gg_info.erase(q.front());
                tmp_l++;
                q.pop();
            }
        }
        
        tmp_r++;
    }
            
    answer[0] = left + 1, answer[1] = right + 1;
    return answer;
}