#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int idx_l = 0;
    while(1) {
        if(left < n * idx_l) {
            break;
        }
        idx_l++;
    }
    
    int idx_r = 0;
    while(1) {
        if(right < n * idx_r) {
            break;
        }
        idx_r++;
    }
    
    int idx = idx_l;
    while(idx < idx_r + 1) {
        int next_idx = idx + 1;
        
        for(int i = 0; i < n; i++) {
            if(i < idx) {
                answer.push_back(idx);
            } else {
                idx++;
                answer.push_back(idx);
            }
        }
        
        idx = next_idx;
    }
    
    vector<int> rst;
    int rst_idx = left - n * (idx_l - 1);
    int len = right - left + 1;
    while(len--) {
        rst.push_back(answer[rst_idx++]);
    }

    return rst;
}