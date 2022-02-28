#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define INF 987654321

using namespace std;

vector<vector<int>> graph;

int dijkstra(int start, int v) {
    vector<int> distance(v, INF);
    distance[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    
    while(!pq.empty()) {
        int curr = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if(distance[curr] < dis)
            continue;
        
        for(auto neighbor : graph[curr]) {
            int next = neighbor;
            int next_dis = dis + 1;
            
            if(distance[next] > next_dis) {
                distance[next] = next_dis;
                pq.emplace(next_dis, next);
            }
        }
    }
    
    int ans = 0;
    int max_idx = max_element(distance.begin() + 1, distance.end()) - distance.begin();
    for(int i = 1; i < v; i++){
        if(distance[i] == distance[max_idx])
            ans++;
    }
    
    return ans;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.resize(n + 1);
    for(int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    answer = dijkstra(1, n + 1);
    return answer;
}