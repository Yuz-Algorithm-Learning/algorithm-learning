#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;
    vector<vector<int>> info(v + 1, vector<int>(v + 1, INF));
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        info[a][b] = c;
    }

    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            if(i == k) continue;

            for(int j = 1; j <= v; j++) {
                if(j == k) continue;

                info[i][j] = min(info[i][j], info[i][k] + info[k][j]);
            }
        }
    }

    int min_ans = INF;
    for(int i = 1; i <= v; i++) {
        min_ans = min(min_ans, info[i][i]);
    }

    if(min_ans != INF)
        cout << min_ans << '\n';
    else
        cout << "-1\n";

    int tmp = INF + INF;
    cout << tmp << endl;
    return 0;
}