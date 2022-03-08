#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<pair<string, bool>>> info;
vector<string> answer;
int tickets_size, airport = 0;

bool dfs(string ap_start){
    bool is_airport = false;
    
    for(auto& ap : info[ap_start]) {
        if(!ap.second) {
            is_airport = true;
            ap.second = true;
            answer.push_back(ap.first);
            airport++;
            
            if(!dfs(ap.first)) {
                is_airport = false;
                ap.second = false;
                answer.pop_back();
                airport--;
            }
        }
    }
    
    if(airport == tickets_size)
        return true;
    
    return (!is_airport)? false : true;

}

vector<string> solution(vector<vector<string>> tickets) {
    tickets_size = tickets.size();
    for(int i = 0; i < tickets.size(); i++)
        info[tickets[i][0]].emplace_back(tickets[i][1], false);
    
    for(auto& air : info)
        sort(air.second.begin(), air.second.end());

    answer.push_back("ICN");
    dfs("ICN");

    return answer;
}