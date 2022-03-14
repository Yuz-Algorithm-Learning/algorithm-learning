#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    deque<int> dq;
    
    string type, num;
    for(int i = 0; i < operations.size(); i++) {
        stringstream ss(operations[i]);
        ss >> type >> num;
        
        if(type == "D") {
            if(num == "1") {
                if(!dq.empty()) {
                    dq.pop_back();
                }
            } else {
                if(!dq.empty()) {
                    dq.pop_front();
                }
            }
        } else {
            dq.push_back(stoi(num));
            sort(dq.begin(), dq.end());
        }
    }
    
    if(dq.empty()) {
        answer[0] = 0, answer[1] = 0;
    } else {
        answer[0] = dq.back(), answer[1] = dq.front();
    }
    
    return answer;
}