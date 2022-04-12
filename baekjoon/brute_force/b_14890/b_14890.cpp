#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, answer = 0;
    cin >> n >> l;

    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 가로줄
    for(int i = 0; i < n; i++) {
        bool only_one = true;
        vector<pair<int, int>> tmp;
        int h = board[i][0];
        tmp.emplace_back(h, 1);
        for(int j = 1; j < n; j++) {
            if(abs(board[i][j] - h) > 1) {
                only_one = false;
                break;
            }
            else if(abs(board[i][j] - h) == 1) {
                tmp.emplace_back(board[i][j], 1);
                h = board[i][j];
            } else {
                tmp[tmp.size() - 1].second += 1;
            }
        }
        
        if(!only_one) continue;

        bool is_road = true;
        for(int j = 0; j < tmp.size(); j++) {
            int num = 0;
            if(j == 0) {
                if(tmp[j].first < tmp[j + 1].first) num += l;
            } else if(j == (tmp.size() - 1)) {
                if(tmp[j - 1].first > tmp[j].first) num += l;
            } else {
                if(tmp[j - 1].first > tmp[j].first) num += l;
                if(tmp[j].first < tmp[j + 1].first) num += l;
            }

            if(tmp[j].second < num) {
                is_road = false;
                break;
            }
        }

        if(is_road) {
            answer++;
        }
    }

    // 세로줄
    for(int j = 0; j < n; j++) {
        bool only_one = true;
        vector<pair<int, int>> tmp;
        int h = board[0][j];
        tmp.emplace_back(h, 1);
        for(int i = 1; i < n; i++) {
            if(abs(board[i][j] - h) > 1) {
                only_one = false;
                break;
            }
            else if(abs(board[i][j] - h) == 1) {
                tmp.emplace_back(board[i][j], 1);
                h = board[i][j];
            } else {
                tmp[tmp.size() - 1].second += 1;
            }
        }
        
        if(!only_one) continue;

        bool is_road = true;
        for(int i = 0; i < tmp.size(); i++) {
            int num = 0;
            if(i == 0) {
                if(tmp[i].first < tmp[i + 1].first) num += l;
            } else if(i == (tmp.size() - 1)) {
                if(tmp[i - 1].first > tmp[i].first) num += l;
            } else {
                if(tmp[i - 1].first > tmp[i].first) num += l;
                if(tmp[i].first < tmp[i + 1].first) num += l;
            }

            if(tmp[i].second < num) {
                is_road = false;
                break;
            }
        }

        if(is_road) {
            answer++;
        }
    }

    cout << answer << '\n';

}