#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, string> graph;
map<string, int> money;

void dfs(string person, int mm) {
    int m2 = mm / 10;
    int m1 = mm - m2;
    
    money[person] += m1;
    
    if(graph[person] == "minho")
        return;
    if(m2 == 0)
        return;

    dfs(graph[person], m2);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < referral.size(); i++) {
        if(referral[i] == "-") {
            referral[i] = "minho";
        }
        graph[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); i++) {
        string person = seller[i];
        int mm = amount[i] * 100;
        dfs(person, mm);
    }
    
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(money[enroll[i]]);
    }
    
    return answer;
}