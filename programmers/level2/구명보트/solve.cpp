#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int little = 0, big = people.size() - 1;
    while(little <= big) {
        if(little == big) {
            answer++;
            break;
        }
        
        if(people[little] + people[big] <= limit) {
            answer++;
            little++;
            big--;
        } else {
            answer++;
            big--;
        }
    }

    return answer;
}