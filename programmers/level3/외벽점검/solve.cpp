#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {    
    int weak_len = weak.size();
    int dist_len = dist.size();
    
    for(int i = 0; i < weak_len - 1; i++)
        weak.push_back(n + weak[i]); 

    sort(dist.begin(), dist.end(), greater<int>());
    for(int i = 1; i <= dist_len; i++) {        // 투입한 친구 수
        for(int j = 0; j < weak_len; j++) {     // 시작 위치
            vector<int> tmp;                    // 친구 뽑기
            for(int t = 0; t < i; t++)
                tmp.push_back(dist[t]);
            
            do {
                int idx = 0;
                for(int t = 0; t < tmp.size(); t++) {
                    int start_dis = weak[j + idx] + tmp[t];
                    while(weak[j + idx + 1] <= start_dis) 
                        idx++;
                    idx++;
                }
                
                if(idx >= weak_len)
                    return i;
                
            } while(prev_permutation(tmp.begin(), tmp.end()));
    
        }
    }
    
    return -1;
}


