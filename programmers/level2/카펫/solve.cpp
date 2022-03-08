#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int yellow_sqrt = sqrt(yellow);
    
    for(int h = 1; h <= yellow_sqrt; h++) {
        if(yellow % h == 0) {
            int w = yellow / h;
            int b = ((h + 2) + w) * 2;
            
            if(brown == b) {
                answer.push_back(w + 2);
                answer.push_back(h + 2);
                break;
            }
        }
    }
    
    return answer;
}