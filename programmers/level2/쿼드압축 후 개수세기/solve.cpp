#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> arr;
vector<int> answer(2);

bool is_same_four(int y, int x, int len) {
    int start = arr[y][x];
    
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++) {
            if(start != arr[i][j])
                return false;
        }
    }
    
    return true;
}

void divide_four(int y, int x, int len) {
    int mid_len = len / 2;
    
    if(!is_same_four(y, x, mid_len))
        divide_four(y, x, mid_len);
    else
        answer[arr[y][x]] += 1;
    
    if(!is_same_four(y, x + mid_len, mid_len))
        divide_four(y, x + mid_len, mid_len); 
    else
        answer[arr[y][x + mid_len]] += 1;  
    
    if(!is_same_four(y + mid_len, x, mid_len))
        divide_four(y + mid_len, x, mid_len);
    else
        answer[arr[y + mid_len][x]] += 1;
     
    if(!is_same_four(y + mid_len, x + mid_len, mid_len))
        divide_four(y + mid_len, x + mid_len, mid_len);
    else
        answer[arr[y + mid_len][x + mid_len]] += 1;
    
}

vector<int> solution(vector<vector<int>> a) {
    arr = a;
    
    int s = a[0][0];
    bool is_same = true;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(s != a[i][j]) {
                is_same = false;
            }
        }
    }
    
    if(is_same)
        answer[s] += 1;
    else
        divide_four(0, 0, arr.size());
    
    return answer;
}