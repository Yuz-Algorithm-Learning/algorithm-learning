#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> info;
    
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string type, id, name;
        ss >> type >> id >> name;
        
        if(type == "Enter" || type == "Change") {
            info[id] = name;
        }
    }

    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string type, id, name;
        ss >> type >> id >> name;
        
        if(type == "Enter") {
            answer.push_back(info[id] + "님이 들어왔습니다.");
        } else if(type == "Leave") {
            answer.push_back(info[id] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}