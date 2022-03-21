#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, vector<vector<int>> &ans) {
    if(n == 0)
        return;
    
    hanoi(n - 1, a, 6 - (a + b), ans);
    ans.push_back({a, b});
    hanoi(n - 1, 6 - (a + b), b, ans); 
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}