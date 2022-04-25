#include <iostream>
#include <algorithm>
using namespace std;

int next_turn[33];
int scores[33];
int num[10];
int turn[33];
bool visited[33];
int node_loc[4];

int ans = 0;

void dfs(int cnt, int sum) {
    if(cnt == 10) {
        ans = max(ans, sum);
        return;
    }

    for(int n = 0; n < 4; n++) {
        int prev = node_loc[n];
        int curr = prev;
        int move = num[cnt];

        if(turn[curr] > 0) {
            curr = turn[curr];
            move--;
        }

        while(move--) {
            if(curr == 21)
                break;
            curr = next_turn[curr];
        }

        if(curr != 21 && visited[curr])
            continue;
        
        visited[prev] = false;
        node_loc[n] = curr;
        visited[curr] = true;

        dfs(cnt + 1, sum + scores[curr]);

        visited[curr] = false;
        node_loc[n] = prev;
        visited[prev] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 10; i++)
        cin >> num[i];
    
    for(int i = 0; i < 21; i++) {
        next_turn[i] = i + 1;
    }
    next_turn[21] = 21;
    next_turn[22] = 23, next_turn[23] = 24, next_turn[24] = 25;
    next_turn[25] = 26, next_turn[26] = 27, next_turn[27] = 20;
    next_turn[28] = 29, next_turn[29] = 25;
    next_turn[30] = 31, next_turn[31] = 32, next_turn[32] = 25;
    
    for(int i = 0; i < 21; i++) {
        scores[i] = i * 2;
    }
    scores[22] = 13, scores[23] = 16, scores[24] = 19;
    scores[25] = 25, scores[26] = 30, scores[27] = 35;
    scores[28] = 22, scores[29] = 24;
    scores[30] = 28, scores[31] = 27, scores[32] = 26;

    turn[5] = 22, turn[10] = 28, turn[15] = 30;

    dfs(0, 0);
    
    cout << ans << '\n';
}