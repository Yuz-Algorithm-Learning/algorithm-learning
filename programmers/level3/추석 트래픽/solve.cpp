#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<double, double>> re_time;   /* 시작시간, 끝시간 */
    for(int i = 0; i < lines.size(); i++) {
        stringstream ss(lines[i]);

        string date, time, sec;
        ss >> date >> time >> sec;

        double end_time = stod(time.substr(0, 2)) * 3600 + stod(time.substr(3, 2)) * 60 + stod(time.substr(6));
        double start_time = end_time - stod(sec.substr(0, sec.size() - 1)) + 0.001;

        re_time.emplace_back(start_time, end_time);
    }

    for(int i = 0; i < re_time.size(); i++) {
        double start = re_time[i].first;
        double end = re_time[i].second;
        int tmp = 1;

        for(int j = i + 1; j < re_time.size(); j++) {
            if(re_time[j].first < end + 1) {
                tmp++;
            }
        }
        answer = max(answer, tmp);
    }

    return answer;
}