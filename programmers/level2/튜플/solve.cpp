#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> num;
    string tmp = "";
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            tmp += s[i];
        } else {
            if(tmp != "") {
                num[stoi(tmp)] += 1;
                tmp = "";
            }
        }
    }
        
    vector<pair<int, int>> vec_num(num.begin(), num.end());
    sort(vec_num.begin(), vec_num.end(), comp);
    
    for(int i = 0; i < vec_num.size(); i++)
        answer.push_back(vec_num[i].first);

    return answer;
}