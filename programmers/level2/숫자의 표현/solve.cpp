#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n) {
    queue<int> q;
    int answer = 0;
    
    int num = 1;
    int sum = 0;
    while(num <= n) {
        q.push(num);
        sum += num;
        num++;
        
        while(sum > n) {
            sum -= q.front();
            q.pop();
        }
        if(sum == n) answer++;

    }
    return answer;
}