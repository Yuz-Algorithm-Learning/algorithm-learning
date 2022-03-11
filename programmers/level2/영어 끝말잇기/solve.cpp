#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    answer[0] = 0, answer[1] = 0;
    
    map<string, bool> word;
    int person = 1;
    int rotate = 1;
    char start = words[0][0];
    
    for(int i = 0; i < words.size(); i++) {
        if(word[words[i]] || words[i][0] != start) {
            answer[0] = person, answer[1] = rotate;
            break;
        }
        
        word[words[i]] = true;
        start = words[i][words[i].size() - 1];
        if(person == n)
            rotate++;
        person = (person < n)? person + 1 : 1;
        
    }

    return answer;
}