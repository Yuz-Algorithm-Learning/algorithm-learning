#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int cnt[360000]; // 99:59:59 -> 359,999

int make_sec(string t) {
    return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
}

string sec_to_str(int t) {
    int sec = t % 60;
    t /= 60;
    int min = t % 60;
    t /= 60;
    int hour = t;
    
    string ans = "";
    if(hour < 10) ans += "0";
    ans += to_string(hour);
    ans += ":";
    if(min < 10) ans += "0";
    ans += to_string(min);
    ans += ":";
    if(sec < 10) ans += "0";
    ans += to_string(sec);
    
    return ans;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    for(int i = 0; i < logs.size(); i++) {
        int start = make_sec(logs[i].substr(0, 8));
        int end = make_sec(logs[i].substr(9));
        for(int j = start; j < end; j++) {
            cnt[j]++;
        }
    }
    
    int t_play = make_sec(play_time);
    int t_adv = make_sec(adv_time);
    
    int t_start = 0;
    long long tmp = 0;
    long long rst = 0;
    
    for(int i = 0; i < t_adv; i++) {
        tmp += cnt[i];
    }
    
    int left = 0;
    rst = tmp;
    
    for(int i = t_adv; i < t_play; i++) {
        tmp -= cnt[left];
        left++;
        tmp += cnt[i];
        
        if(rst < tmp) {
            rst = tmp;
            t_start = left;
        }
    }
    
    answer = sec_to_str(t_start);
    
    return answer;
}