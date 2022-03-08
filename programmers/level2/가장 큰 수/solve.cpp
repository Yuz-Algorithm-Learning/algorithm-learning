#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<string, string> &a, const pair<string, string> &b) {
    return a.first > b.first;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<pair<string, string>> str_num;
    for(int i = 0; i < numbers.size(); i++) {
        string s_num = to_string(numbers[i]);
        
        int rotate = 2;
        string long_num = "";
        if(s_num.size() == 1) {
            rotate = 3;
        }
        
        for(int j = 0; j < rotate; j++) {
            long_num += s_num;
        }
        
        str_num.emplace_back(long_num, s_num);
    }
    
    sort(str_num.begin(), str_num.end(), comp);
    for(auto num : str_num)
        answer += num.second;
    
    return (answer[0] == '0')? "0" : answer;
}