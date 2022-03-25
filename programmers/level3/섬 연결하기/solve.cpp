#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> roots;

struct island {
    int cost;
    int a;
    int b;
};

bool comp(island l1, island l2) {
    return l1.cost < l2.cost;
}

int find(int x) {
	if (roots[x] == x) return x;
	return roots[x] = find(roots[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) 
        return false;
    
	roots[y] = x;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    roots.resize(n);
    for(int i = 0; i < n; i++)
        roots[i] = i;
    
    vector<island> v;
    for(int i = 0; i < costs.size(); i++) {
        v.push_back({costs[i][2], costs[i][0], costs[i][1]});
    }
    sort(v.begin(), v.end(), comp);
    
    for(auto is : v) {
        if(merge(is.a, is.b)) {
            answer += is.cost;
        }
    }
    
    return answer;
}