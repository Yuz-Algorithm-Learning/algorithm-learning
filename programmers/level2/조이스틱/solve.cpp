#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    vector<int> not_a;
    not_a.push_back(0);
    for(int i = 0; i < name.size(); i++) {
        if(name[i] == 'A')
            continue;
        if(i != 0)
            not_a.push_back(i);
        
        if(name[i] <= 'N') {
            answer += (name[i] - 'A');
        } else {
            answer += ('Z' - name[i] + 1);
        }
    }
    
    int move = 987654321;
    for(int i = 0; i < not_a.size() - 1; i++) {
        int tmp = not_a[i] * 2 + name.size() - not_a[i + 1];
        move = min(move, tmp);
    }
    for(int i = not_a.size() - 1; i > 0; i--) {
        int tmp = (name.size() - not_a[i]) * 2 + not_a[i - 1];
        move = min(move, tmp);
    }
    
    move = min(move, not_a[not_a.size() - 1]);
    answer += move;
    
    return answer;
}