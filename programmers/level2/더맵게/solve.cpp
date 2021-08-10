#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int sco : scoville)
        pq.push(sco);

    while (pq.size() > 1) {

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int new_sco = first + second * 2;
        pq.push(new_sco);

        answer++;

        if (pq.top() >= K)
            return answer;
    }

    return -1;
}