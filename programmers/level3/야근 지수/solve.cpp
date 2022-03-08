#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    int max_value = 0;
    map<int, int, greater<int>> time;
    for(int i = 0; i < works.size(); i++) {
        if(works[i] > max_value)
            max_value = works[i];
        time[works[i]] += 1;
    }

    while(n--) {
        time[max_value] -= 1;

        if(max_value != 1) {
            time[max_value - 1] += 1;
        }
        if(time[max_value] == 0) {
            time.erase(max_value);
            max_value--;
        }

        if(time.empty())
            break;
    }
    
    for(auto mm : time) {
        for(int i = 0; i < mm.second; i++) {
            answer += pow(mm.first, 2);
        }
    }
    
    return answer;
}