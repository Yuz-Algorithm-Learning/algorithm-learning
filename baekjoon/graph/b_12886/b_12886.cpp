#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1501][1501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;
    if(sum % 3 != 0) {
        cout << "0\n";
        return 0;
    }

    queue<pair<int, int>> q;
    q.emplace(a, b);
    visited[a][b] = true;

    while(!q.empty()) {
        int t1 = q.front().first;
        int t2 = q.front().second;
        q.pop();
        int t3 = sum - t1 - t2;

        if(t1 == t2 && t2 == t3) {
            cout << "1\n";
            return 0;
        }

        vector<int> tmp = {t1, t2, t3};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(tmp[i] < tmp[j]) {
                    int n1 = tmp[i] * 2;
                    int n2 = tmp[j] - tmp[i];

                    if(!visited[n1][n2]) {
                        visited[n1][n2] = true;
                        q.emplace(n1, n2);
                    }
                }
            }
        }
        
    }

    cout << "0\n";
    return 0;
}