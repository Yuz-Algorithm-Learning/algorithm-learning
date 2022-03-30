#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> times;
bool binary_search(long long m, int n) {
    long long num = 0;
    
    for(int i = 0; i < times.size(); i++) {
        num += m / (long long)times[i];

        if(num >= (long long)n) {
            return false;
        }
    }

    return true;
}

long long solution(int n, vector<int> t) {
    long long answer = 0;    
    long long left = 0, right = *max_element(t.begin(), t.end()) * (long long)n;
    times = t;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        if(!binary_search(mid, n)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}