#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    if (s.size() % 2)
        return 0;

    string tmp = "";
    int idx = 0;
    while (idx < s.size()) {
        if (idx < s.size() - 1 && s[idx] == s[idx + 1]) {
            idx += 2;
        }
        else {
            tmp += s[idx];
            
            int t_size = tmp.size();
            if (t_size > 1) {
                if (tmp[t_size - 1] == tmp[t_size - 2])
                    tmp.erase(t_size - 2, 2);
            }
            idx++;
        }
    }

    if (tmp.size())
        return 0;
    else
        return 1;
}