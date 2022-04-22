#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    long long minus = 0, plus = 0;
    int a_size = a.size();
    
    vector<long long> total_num(a_size);
    for(int i = 0; i < a_size; i++) {
        if(a[i] < 0)
            minus += a[i];
        else
            plus += a[i];

        total_num[i] = (long long)a[i];
    }

    if(minus + plus != 0)
        return -1;
        
    vector<int> entry(a_size);                  /* 나의 이웃 개수 */
    vector<vector<int>> connect_info(a_size);   /* 양방향 연결 저장 */
    for(int i = 0; i < edges.size(); i++) {
        connect_info[edges[i][0]].push_back(edges[i][1]);
        connect_info[edges[i][1]].push_back(edges[i][0]);
        entry[edges[i][0]]++;
        entry[edges[i][1]]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < entry.size(); i++) {
        if(entry[i] == 1) {
            pq.push(i);
        }
    }
    
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        for(int i = 0; i < connect_info[curr].size(); i++) {
            int next = connect_info[curr][i];
            
            if(entry[next] <= 0)
                continue;
            
            total_num[next] += total_num[curr];
            answer += abs(total_num[curr]);
            
            if(--entry[next] == 1) {
                pq.push(next);
            }
        }
        
        entry[curr] = 0;
        total_num[curr] = 0;
    }
    
    return answer;
}