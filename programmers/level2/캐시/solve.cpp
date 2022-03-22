#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    int cache_cnt = 0;
    map<string, int> m;
    
    for(int i = 0; i < cities.size(); i++)
        for(int j = 0; j < cities[i].size(); j++)
            cities[i][j] = tolower(cities[i][j]);
    
    for(int i = 0; i < cities.size(); i++) {        
        if(cache_cnt < cacheSize) {
            if(!m[cities[i]]) {
                m[cities[i]] = i + 1;
                answer += 5;
                cache_cnt++;
            } else {
                m[cities[i]] = i + 1;
                answer += 1;
            }
        } else {
            if(cacheSize == 0) {
                answer += 5;
            } else {
                if(!m[cities[i]]) {
                    int min_idx = 987654321;
                    string min_str = "";
                    for(auto mm : m) {
                        if(mm.second != 0 && mm.second < min_idx) {
                            min_str = mm.first;
                            min_idx = mm.second;
                        }
                    }
                    m.erase(min_str);

                    m[cities[i]] = i + 1;
                    answer += 5;
                } else {
                    m[cities[i]] = i + 1;
                    answer += 1;
                }
            }
        }
    }
       
    return answer;
}