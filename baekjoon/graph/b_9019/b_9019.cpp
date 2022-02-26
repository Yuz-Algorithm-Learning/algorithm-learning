#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int a, b;
bool visit[10000];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        
        memset(visit, false, sizeof(visit));
        queue<pair<int, string>> q;
        visit[a] = true;
        q.emplace(a, "");

        while(!q.empty()) {
            int num = q.front().first;
            string command = q.front().second;
            q.pop();

            if(num == b) {
                cout << command << "\n";
                break;
            }
            
            // D
            int curr = num * 2 % 10000;
            if(!visit[curr]) {
                visit[curr] = true;
                q.emplace(curr, command + 'D');
            }
            // S
            curr = (num - 1 < 0)? 9999 : num - 1;
            if(!visit[curr]) {
                visit[curr] = true;
                q.emplace(curr, command + 'S');
            }
            // L
            curr = (num % 1000) * 10 + num / 1000;
            if(!visit[curr]) {
                visit[curr] = true;
                q.emplace(curr, command + 'L');
            }
            // R
            curr = (num % 10) * 1000 + num / 10;
            if(!visit[curr]) {
                visit[curr] = true;
                q.emplace(curr, command + 'R');
            }
            
        }
    }
}