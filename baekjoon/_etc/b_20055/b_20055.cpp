#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int len = n * 2;
    vector<pair<int, bool>> con(len + 1);
    for(int i = 1; i <= len; i++) {
        cin >> con[i].first;
    }

    int time = 0;
    while(1) {
        time++;

        // 1
        // 내리기
        if(con[n - 1].second)
            con[n - 1].second = false;

        vector<pair<int, bool>> next_con(len + 1);
        next_con[1] = con[len];
        for(int i = len; i >= 2; i--) {
            next_con[i] = con[i - 1];
        }
        con = next_con;

        // 2
        for(int i = n - 1; i >= 0; i--) {
            if(con[i].second) {
                if(!con[i + 1].second && con[i + 1].first) {
                    con[i + 1].first--;
                    con[i].second = false;
                    if(i + 1 != n)
                        con[i + 1].second = true;
                }
            }
        }

        // 3
        if(con[1].first) {
            con[1].second = true;
            con[1].first--;
        }

        int num = 0;
        for(int i = 1; i <= len; i++) {
            if(con[i].first == 0) {
                num++;
            }
        }
        if(num >= k)
            break;
    }

    cout << time << endl;
    return 0;
}