#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long cal(long long a, long long b, char op) {
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else
        return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> num;
    vector<char> oper;
    int start = 0;
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            num.push_back(stoll(expression.substr(start, i - start)));
            oper.push_back(expression[i]);
            start = i + 1;
        }
    }
    num.push_back(stoll(expression.substr(start)));
    
    vector<int> per = {0, 1, 2};
    string str_op = "+-*";    
    do {
        vector<long long> tmp_num = num;
        vector<char> tmp_oper = oper;
        
        for(int i = 0; i < 3; i++) {

            int idx = 0;
            while(idx < tmp_oper.size()) {
                if(tmp_oper[idx] == str_op[per[i]]) {
                    long long ans = cal(tmp_num[idx], tmp_num[idx + 1], tmp_oper[idx]);
            
                    tmp_num.erase(tmp_num.begin() + idx);
                    tmp_num.erase(tmp_num.begin() + idx);
                    tmp_num.insert(tmp_num.begin() + idx, ans);
                    
                    tmp_oper.erase(tmp_oper.begin() + idx);

                } else {
                    idx++;
                }
            }

        }
        answer = max(answer, abs(tmp_num[0]));
    } while (next_permutation(per.begin(), per.end()));
    
    return answer;
}