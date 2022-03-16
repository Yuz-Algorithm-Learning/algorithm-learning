#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char number[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                   'A', 'B', 'C', 'D', 'E', 'F'};

string num_to_str(int num, int n) {
    string num_str = "";
    
    if(num == 0)
        return "0";
    
    while(num > 0) {
        num_str += number[num % n];
        num /= n;
    }
    
    reverse(num_str.begin(), num_str.end());
    return num_str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    int tm = t * m;
    
    int num = 0;
    while(tmp.size() <= tm) {
        tmp += num_to_str(num, n);
        num++;
    }
    
    int idx = p - 1;
    while(answer.size() < t) {
        answer += tmp[idx];
        idx += m;
    }
    
    return answer;
}