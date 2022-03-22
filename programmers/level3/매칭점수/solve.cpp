#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <tuple>
#include <sstream>
using namespace std;

struct info {
    int basic;
    double match;
    vector<string> link;
};

int solution(string word, vector<string> pages) {
    int answer = 0;
    
    map<string, int> url;
    map<int, info> url_info;
    
    for(int i = 0; i < word.size(); i++)
        word[i] = tolower(word[i]);
    
    for(int i = 0; i < pages.size(); i++) {
        string url_pattern = "<meta property=\"og:url\"";
        if(pages[i].find(url_pattern) == string::npos)
            continue;

        int url_start_idx = pages[i].find("https://", pages[i].find(url_pattern) + url_pattern.length()) + 8; 
        int url_end_idx = pages[i].find("\"/>", url_start_idx);
        url[pages[i].substr(url_start_idx, url_end_idx - url_start_idx)] = i + 1;
        
        string href_pattern = "<a href=\"https://";
        int idx = 0;
        while(1) {
            idx = pages[i].find(href_pattern, idx + 1);
            if (idx != string::npos) {
                int href_start_idx = idx + href_pattern.size();
                int href_end_idx = pages[i].find("\">", idx);
                url_info[i + 1].link.push_back(pages[i].substr(href_start_idx, href_end_idx - href_start_idx));
            } else
                break;
        }
        
        string body_start_pattern = "<body>";
        string body_end_pattern = "</body>";
        int body_start_idx = pages[i].find(body_start_pattern) + body_start_pattern.size();
        int body_end_idx = pages[i].find(body_end_pattern);
        string body_str = pages[i].substr(body_start_idx, body_end_idx - body_start_idx);
        
        string cur = "";
        int cnt = 0;
        for (int j = 0; j < body_str.length(); j++) {
            if (isalpha(body_str[j]) == 0) {
                if (cur == word) cnt++;
                cur = "";
            } else {
                cur += tolower(body_str[j]);
            }
        }
        url_info[i + 1].basic += cnt;
        
    }

    for(auto ii : url_info) {
        for(string u : ii.second.link) {
            if(url[u]) {
                url_info[url[u]].match += (ii.second.basic / (double)ii.second.link.size());
            }
        }
    }
    
    double max_value = 0;
    for(auto ii : url_info) {
        if(max_value < ii.second.basic + ii.second.match) {
            max_value = ii.second.basic + ii.second.match;
            answer = ii.first - 1;
        }
    }
    
    return answer;
}