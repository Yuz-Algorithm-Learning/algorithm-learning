#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool genres_comp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

bool play_comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genres_play;                 /* 장르별 재생횟수 합 */
    unordered_map<string, vector<pair<int, int>>> info;     /* key: 장르, value: {재생된 횟수, 인덱스} */
    for(int i = 0; i < plays.size(); i++) {
        genres_play[genres[i]] += plays[i];
        info[genres[i]].emplace_back(plays[i], i);
    }

    vector<pair<string, int>> v_song(genres_play.begin(), genres_play.end());
    sort(v_song.begin(), v_song.end(), genres_comp);
    vector<pair<string, vector<pair<int, int>>>> v_info(info.begin(), info.end());
    for(int i = 0; i < v_info.size(); i++) {
        sort(v_info[i].second.begin(), v_info[i].second.end(), play_comp);
    }

    for(int s = 0; s < v_song.size(); s++) {
        for(int i = 0; i < v_info.size(); i++) {
            if(v_song[s].first == v_info[i].first) {
                int num = (v_info[i].second.size() == 1)? 1 : 2;
                for(int j = 0; j < num; j++)
                    answer.push_back(v_info[i].second[j].second);
            }
        }
    }

    return answer;
}