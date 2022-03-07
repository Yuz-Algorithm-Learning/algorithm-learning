#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int end_time = jobs[0][0] + jobs[0][1];
    int idx = 1, total_time = jobs[0][1];
    while(idx < jobs.size()) {
        if(jobs[idx][0] <= end_time) {
            pq.emplace(jobs[idx][1], jobs[idx][0]);
            idx++;
            continue;
        }

        if(!pq.empty()) {
            int start = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            end_time += time;
            total_time += (end_time - start);
        } else {
            end_time = jobs[idx][0] + jobs[idx][1];
            total_time += (end_time - jobs[idx][0]);
            idx++;
        }
    }

    while(!pq.empty()) {
        int start = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        end_time += time;
        total_time += (end_time - start);
    }

    return total_time / jobs.size();
}