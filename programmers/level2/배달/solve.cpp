#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) {
    vector<int> distance(n + 1, 987654321);
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
            int next = neighbor.first;
            int next_dis = neighbor.second + dis;
            
            if(next_dis < distance[next]) {
                distance[next] = next_dis;
                pq.emplace(next_dis, next);
            }
        }
    }
    
    return distance;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    n = N;
    
    graph.resize(n + 1);
    for(int i = 0; i < road.size(); i++) {
        graph[road[i][0]].emplace_back(road[i][1], road[i][2]);
        graph[road[i][1]].emplace_back(road[i][0], road[i][2]);
    }
    
    vector<int> rst = dijkstra(1);
    for(int i = 1; i <= n; i++) {
        if(rst[i] <= K)
            answer++;
    }
    
    return answer;
}