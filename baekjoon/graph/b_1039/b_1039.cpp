#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    int k;
    cin >> n >> k;

    queue<string> q;
    q.push(n);
    int tmp_k = 0;
    while(tmp_k < k) {
        int q_size = q.size();
        map<string, bool> visited;

        while(q_size--) {
            string curr = q.front();
            q.pop();

            for(int i = 0; i < curr.size() - 1; i++) {
                for(int j = i + 1; j < curr.size(); j++) {
                    if(i == 0 && curr[j] == '0')
                        continue;

                    swap(curr[i], curr[j]);
                    if(!visited[curr]) {
                        visited[curr] = true;
                        q.push(curr);
                    }
                    swap(curr[i], curr[j]);
                }
            }
        }

        tmp_k++;
    }

    int max_ans = 0;
    while(!q.empty()) {
        max_ans = max(max_ans, stoi(q.front()));
        q.pop();
    }

    if(max_ans == 0)
        cout << "-1\n";
    else
        cout << max_ans << '\n';

    return 0;

}