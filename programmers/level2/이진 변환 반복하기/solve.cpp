#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer(2);

int make_two(int num) {
    int tmp_one = 0;
    
    while(num) {
        if(num % 2 == 1)
            tmp_one++;
        else
            answer[1]++;
        
        num >>= 1;
    }

    return tmp_one;   
}

vector<int> solution(string s) {
    
    int one = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1')
            one++;
    }
    answer[0] = 1;
    answer[1] = s.size() - one;
    
    int next = one;
    while(next != 1) {
        next = make_two(next);
        answer[0]++;
    }
    
    return answer;
}