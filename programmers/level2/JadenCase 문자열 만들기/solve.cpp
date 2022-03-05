#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ' && (i + 1) != s.size()) {
            s[i + 1] = toupper(s[i + 1]);
        }
    }
    s[0] = toupper(s[0]);
    
    return s;
}