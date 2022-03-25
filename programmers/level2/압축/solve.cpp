#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    
    char alpha = 'A';
    string c_to_str;
    for (int i = 1; i <= 26; i++) {
        c_to_str = alpha++;
        dic[c_to_str] = i;
    }
    
    int new_num = 27;
    int start_idx = 0;
    while(start_idx < msg.size()) {        
        int out_rst = 0;
        string add_word = "";
        
        int num = 1;
        while(1) {
            if(!dic[msg.substr(start_idx, num)]) {
                break;
            }
            
            out_rst = dic[msg.substr(start_idx, num)];
            num++;
            if(start_idx + num > msg.size()) break;
            add_word = msg.substr(start_idx, num);
        }
        
        answer.push_back(out_rst);
        dic[add_word] = new_num++;
        start_idx += (num - 1);
    }
    
    return answer;
}