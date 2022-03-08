#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    int min = 987654321, max = -987654321;
    
    string num;
    while(ss >> num) {
        int tmp = (num[0] != '-')? stoi(num) : -stoi(num.substr(1)); 
        if(tmp < min)
            min = tmp;
        if(tmp > max)
            max = tmp;
    }
    
    answer = to_string(min) + " " + to_string(max);
    return answer;
}