#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int h = 3, w = 3;
vector<vector<int>> board;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int cal(vector<int> v, vector<int> &next_v) {
    map<int, int> tmp_num;
    for(int i = 0; i < v.size(); i++)
        tmp_num[v[i]]++;

    vector<pair<int, int>> tmp_v;
    for(auto num : tmp_num) {
        tmp_v.emplace_back(num.first, num.second);
    } 
    sort(tmp_v.begin(), tmp_v.end(), comp);

    int size = (tmp_v.size() > 50)? 50 : tmp_v.size();
    for(int i = 0; i < size; i++) {
        next_v.push_back(tmp_v[i].first);
        next_v.push_back(tmp_v[i].second);
    }

    return size * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;
    r--, c--;

    board.resize(100, vector<int>(100));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    if(board[r][c] == k) {
        cout << "0\n";
        return 0;
    }

    int t = 1;
    while(t <= 100) {
        if(h >= w) {
            vector<vector<int>> next_board(100, vector<int>(100));
            int max_r = 0;
            for(int i = 0; i < h; i++) {
                vector<int> tmp_r;
                for(int j = 0; j < w; j++) {
                    if(board[i][j] > 0)
                        tmp_r.push_back(board[i][j]);
                }

                vector<int> next_line;
                max_r = max(max_r, cal(tmp_r, next_line));

                for(int j = 0; j < next_line.size(); j++) {
                    next_board[i][j] = next_line[j];
                }
            }
            w = max_r;
            board = next_board;
        } else {
            vector<vector<int>> next_board(100, vector<int>(100));
            int max_c = 0;
            for(int j = 0; j < w; j++) {
                vector<int> tmp_c;
                for(int i = 0; i < h; i++) {
                    if(board[i][j] > 0)
                        tmp_c.push_back(board[i][j]);
                }

                vector<int> next_line;
                max_c = max(max_c, cal(tmp_c, next_line));

                for(int i = 0; i < next_line.size(); i++) {
                    next_board[i][j] = next_line[i];
                }
            }
            h = max_c;
            board = next_board;
        }
        
        if(board[r][c] == k)
            break;
        
        t++;
    }

    if(t > 100) {
        cout << "-1\n";
    } else {
        cout << t << '\n';
    }
    return 0;
}