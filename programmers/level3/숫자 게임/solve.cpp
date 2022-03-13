#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int a_idx = 0, b_idx = 0;
    while(a_idx < a.size()) {

        if(a[a_idx] < b[b_idx]) {
            answer++;
            a_idx++;
            b_idx++;
        } else
            a_idx++;
    }

    return answer;
}