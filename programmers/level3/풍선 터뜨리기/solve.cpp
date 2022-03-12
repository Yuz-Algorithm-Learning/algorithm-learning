#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    
    vector<int> left(a.size());
    vector<int> right(a.size());
    
    if(a.size() == 1) return 1;
    if(a.size() == 2) return 2;
    
    int tmp1 = a[0];
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < tmp1) {
            left[i] = a[i];
            tmp1 = a[i];
        } else {
            left[i] = tmp1;
        }
    }
    
    int tmp2 = a[a.size()-1];
    for(int i = a.size()-1; i >= 0; i--) {
        if(a[i] < tmp2) {
            right[i] = a[i];
            tmp2 = right[i];
        } else {
            right[i] = tmp2;
        }
    }
    
    for(int i = 1; i < a.size() - 1; i++) {
        if(left[i - 1] < a[i] && a[i] > right[i + 1]) {
            continue;
        }
        answer++;
    }
    
    return answer;
}