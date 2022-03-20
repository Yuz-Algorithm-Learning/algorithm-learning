#include <string>
#include <vector>
#include <map>
using namespace std;

int cnt = 1;
map<string, int> d;
vector<string> alpha = {"A", "E", "I", "O", "U"};

void dfs(string a) {
    if(a.size() > 5)
        return;
    
    d[a] = cnt++;
    for(int i = 0; i < 5; i++) {
        dfs(a + alpha[i]);
    }
}

int solution(string word) {
    
    for(int i = 0; i < 5; i++) {
        dfs(alpha[i]);
    }
    
    return d[word];
}