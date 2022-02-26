#include <string>
#include <vector>

using namespace std;

string answer;

bool is_correct(string str) {
    int tmp = 0;
    
    for(int i = 0; i < str.size(); i++) {
        (str[i] == '(')? tmp++ : tmp--;
        return (tmp < 0)? false : true;
    }

    return true;
}

void make_uv(string str) {
    int l, r, idx;
    l = r = idx = 0;
    
    if(str == "")
        return;

    for(int i = 0; i < str.size(); i++) {
        (str[i] == '(')? l++ : r++;
        
        if(l == r) {
            idx = i;
            break;
        }
    }
    
    string u = str.substr(0, idx + 1);
    string v = str.substr(idx + 1);
    
    if(is_correct(u)) {
        answer += u;
        make_uv(v);
    } else {
        answer += '(';
        make_uv(v);
        answer += ')';
        
        if(!u.empty()) {
            u.erase(0, 1);
            u.pop_back();
            
            for(int i = 0; i < u.size(); i++)
                u[i] = (u[i] == '(')? ')' : '(';
            
            answer += u;
        }
    }
}

string solution(string p) {
    answer = "";
    make_uv(p);
    return answer;
}