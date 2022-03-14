#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

bool comp(const tuple<string, int, int> &a, const tuple<string, int, int> &b) {
    if(get<0>(a) == get<0>(b)) 
        return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<tuple<string, int, int>> info;
    
    for(int i = 0; i < files.size(); i++) {
        string head = "";
        int num = 0;

        // HEAD
        int h_idx = 0;
        while(1) {
            if(isdigit(files[i][h_idx])) {
                head = files[i].substr(0, h_idx);
                break;
            }
            h_idx++;
        }
        for(int i = 0; i < head.size(); i++)
            head[i] = tolower(head[i]);

        // NUMBER
        int num_idx = h_idx;
        int num_max_length = 5;
        while(num_max_length--) {
            if(!isdigit(files[i][num_idx])) {
                break;
            }
            num_idx++;
        }
        
        if(num_idx - h_idx <= 5) {
            num = stoi(files[i].substr(h_idx, num_idx - h_idx));
        } else {
            num = stoi(files[i].substr(h_idx, 5));
        }
        
        info.emplace_back(head, num, i);
    }
    
    stable_sort(info.begin(), info.end(), comp);
    
    for(int i = 0; i < info.size(); i++)
        answer.push_back(files[get<2>(info[i])]);

    return answer;
}