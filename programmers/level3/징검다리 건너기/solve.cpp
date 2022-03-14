#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> stones;

bool binary_search(int n, int k) {
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++) {
        cnt = (stones[i] - n <= 0)? cnt + 1 : 0;
        
        if(cnt >= k) return true;
    }
    return false; 
}

int solution(vector<int> st, int k) {
    int answer = 0;
    stones = st;
    int left = 1, right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) {
        int mid = (left + right) / 2;
        if(binary_search(mid, k)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}