#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, s;
    cin >> g >> s;
    s = (s < 0)? -s : s;

    map<char, int> w1_map, w2_map;
    string w1, w2;
    cin >> w1 >> w2;

    for(int i = 0; i < g; i++)
        w1_map[w1[i]] += 1;

    int answer = 0;
    int len = 0;
    for(int i = 0; i < s; i++) {
        w2_map[w2[i]] += 1;
        len++;

        if(len == g) {
            len--;
            
            bool is_same = true;
            for(auto a : w1_map) {
                if(w2_map[a.first] != a.second) {
                    is_same = false;
                    break;
                }
            }

            if(is_same)
                answer++;
            
            w2_map[w2[i + 1 - g]] -= 1;
        }
    }

    cout << answer << "\n";
    return 0;
}