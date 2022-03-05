#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> info;
    for(int i = 0; i < clothes.size(); i++) {
        info[clothes[i][1]] += 1;
    }

    for(map<string, int>::iterator it = info.begin(); it != info.end(); it++) {
        answer *= (it->second + 1);
    }
    
    return answer - 1;
}