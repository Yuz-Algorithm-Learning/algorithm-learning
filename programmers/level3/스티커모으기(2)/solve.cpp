#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    if(sticker.size() == 1) {
        return sticker[0];
    }
    
    vector<pair<int, int>> st1(sticker.size());
    for(int i = 2; i < sticker.size() - 1; i++) {
        st1[i].first = max(st1[i - 1].first, st1[i - 1].second);
        st1[i].second = st1[i - 1].first + sticker[i];
    }
    answer = sticker[0] + max(st1[sticker.size() - 2].first, st1[sticker.size() - 2].second);
    
    vector<pair<int, int>> st2(sticker.size());
    for(int i = 1; i < sticker.size(); i++) {
        st2[i].first = max(st2[i - 1].first, st2[i - 1].second);
        st2[i].second = st2[i - 1].first + sticker[i];
    }
    answer = max({answer, st2[sticker.size() - 1].first, st2[sticker.size() - 1].second});
        
    return answer;
}