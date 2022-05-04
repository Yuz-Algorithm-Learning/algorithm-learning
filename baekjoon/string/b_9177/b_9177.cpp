#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        bool is_s3 = false;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<vector<bool>> visited(s1.size() + 1, vector<bool>(s2.size() + 1));
        visited[0][0] = true;

        while(!q.empty()) {
            int s1_idx = q.front().first;
            int s2_idx = q.front().second;
            q.pop();

            if(s1_idx == s1.size() && s2_idx == s2.size()) {
                is_s3 = true;
                break;
            }

            int s3_idx = s1_idx + s2_idx;
            if(s1_idx < s1.size() && s1[s1_idx] == s3[s3_idx] && !visited[s1_idx + 1][s2_idx]) {
                visited[s1_idx + 1][s2_idx] = true;
                q.emplace(s1_idx + 1, s2_idx);
            }
            if(s2_idx < s2.size() && s2[s2_idx] == s3[s3_idx] && !visited[s1_idx][s2_idx + 1]) {
                visited[s1_idx][s2_idx + 1] = true;
                q.emplace(s1_idx, s2_idx + 1);
            }
        }

        cout << "Data set " << test_case << ": " << ((is_s3)? "yes" : "no") << '\n';

    }

    return 0;
}