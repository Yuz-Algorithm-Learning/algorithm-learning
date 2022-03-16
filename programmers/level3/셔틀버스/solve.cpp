#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string time_to_string(int min) {
    int ans_hour = min / 60;
    string str_hour = (ans_hour < 10)? '0' + to_string(ans_hour) : to_string(ans_hour);
    int ans_min = min % 60;
    string str_min = (ans_min < 10)? '0' + to_string(ans_min) : to_string(ans_min);
    return str_hour + ':' + str_min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> bus_time;
    int start_time = 9 * 60;
    
    bus_time.push_back(0);
    while(n) {
        bus_time.push_back(start_time);  
        start_time += t;
        n--;
    }
    
    vector<int> tt;
    for(int i = 0; i < timetable.size(); i++) {
        int time = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2));  
        if(time <= bus_time[bus_time.size() - 1]) {
            tt.push_back(time);
        }
    }
    sort(tt.begin(), tt.end());
    
    int t_idx = 0;
    for(int i = 1; i < bus_time.size() - 1; i++) {
        int mm = 0;
        
        while(t_idx < tt.size()) {
            if(tt[t_idx] <= bus_time[i] && mm < m) {
                mm++;
                t_idx++;
            } else {
                break;
            }
        }
    }
    
    int final_time;
    if(tt.size() - t_idx < m) {
        return time_to_string(bus_time[bus_time.size() - 1]);
    } else {
        final_time = tt[t_idx + m - 1] - 1;
        return time_to_string(final_time);
    }
   
    return answer;
}