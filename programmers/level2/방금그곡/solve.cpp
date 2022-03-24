#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct Info {
    int song_len;
    int idx;
    string title;
};

bool comp (Info &a, Info &b) {
    if(a.song_len == b.song_len)
        return a.idx < b.idx;
    return a.song_len > b.song_len;
}

string solution(string mm, vector<string> musicinfos) {
    string answer = "(None)";
    
    string m = "";
    for(int i = 0; i < mm.size(); i++) {
        if(mm[i] == '#') {
            m[m.size() - 1] = tolower(m[m.size() - 1]);
        } else {
            m += mm[i];
        }
    }
    
    vector<Info> v;
    for(int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);
        string str;
        vector<string> tmp;
        while(getline(ss, str, ',')) {
            tmp.push_back(str);
        }

        int t1 = stoi(tmp[0].substr(0, 2)) * 60 + stoi(tmp[0].substr(3, 2));
        int t2 = stoi(tmp[1].substr(0, 2)) * 60 + stoi(tmp[1].substr(3, 2));
        
        string tmp_3 = "";
        for(int i = 0; i < tmp[3].size(); i++) {
            if(tmp[3][i] == '#') {
                tmp_3[tmp_3.size() - 1] = tolower(tmp_3[tmp_3.size() - 1]);
            } else {
                tmp_3 += tmp[3][i];
            }
        }

        if(t2 - t1 < tmp_3.size()) {
            tmp_3 = tmp_3.substr(0, t2 - t1);
        } else {
            string str_tmp = "";
            for(int t = 0; t <= (t2 - t1); t++) {
                str_tmp += tmp_3[t % tmp_3.size()];
            }
            tmp_3 = str_tmp;
        }
        
        if(m.size() <= tmp_3.size()) {
            if(tmp_3.find(m) != string::npos)
                v.push_back({t2 - t1, i, tmp[2]});
        }
    }
    
    sort(v.begin(), v.end(), comp);
    if(v.size() != 0)
        answer = v[0].title;
    
    return answer;
}