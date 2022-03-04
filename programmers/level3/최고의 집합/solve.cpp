#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int quotient = s / n;
    int remainder = s % n;
    
    if(quotient < 1) {
        answer.push_back(-1);
    } else {
        for(int i = 0; i < n; i++) {
            if (i < n - remainder)
                answer.push_back(quotient);
            else
                answer.push_back(quotient + 1);
        }
    }
    
    return answer;
}