#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int s_size = s.size();
    
    while(s_size--) {
        bool is_correct = true;
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++) {
            int tmp = 0;
            
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(s[i] == ')')
                    tmp = 1;
                else if (s[i] == '}')
                    tmp = 2;
                else if (s[i] == ']')
                    tmp = 3;
                
                if(st.empty()) {
                    is_correct = false;
                    break;
                }
                if((st.top() + tmp) != 0) {
                    is_correct = false;
                    break;
                } else
                    st.pop();
                
            } else {
                if (s[i] == '(')
                    st.push(-1);
                else if (s[i] == '{')
                    st.push(-2);
                else if (s[i] == '[')
                    st.push(-3);
            }
        }
        
        if(is_correct && st.empty())
            answer++;
        
        s = s.substr(1) + s[0];
    }
    
    return answer;
}