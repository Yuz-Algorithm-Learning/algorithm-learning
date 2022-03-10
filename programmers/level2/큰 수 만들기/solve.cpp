#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num_size = number.size() - k;
    
    int start_idx = 0;
    char max_value;
    while(num_size) {
        max_value = '0';
        for(int i = start_idx; i < number.size() - (num_size - 1); i++) {
            if(max_value < number[i]) {
                start_idx = i;
                max_value = number[i];
            }
        }
        
        answer += max_value;
        start_idx++;
        num_size--;
    }

    return answer;
}