#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

vector<vector<pair<int, int>>> block;
vector<pair<int, int>> block_h_w(7);

void block_rotate(vector<pair<int, int>> &blk) {
    int max_y = 0;
    vector<pair<int, int>> tmp;

    for(int i = 0; i < blk.size(); i++) {
        if(max_y < blk[i].first)
            max_y = blk[i].first;
    }

    for(int i = 0; i < blk.size(); i++)
        tmp.emplace_back(blk[i].second, max_y - blk[i].first);
    
    blk = tmp;
}

void zero_loc(vector<pair<int, int>> &blk) {
    int min_x = 987654321, min_y = 987654321;

    for(int i = 0; i < blk.size(); i++) {
        if(blk[i].first < min_y) min_y = blk[i].first;
        if(blk[i].second < min_x) min_x = blk[i].second;
    }

    for(int i = 0; i < blk.size(); i++) {
        blk[i].first -= min_y;
        blk[i].second -= min_x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    block = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}}
    };
    block_h_w = {
        {1, 4}, {2, 2}, {3, 2}, {3, 2}, {2, 3}, {3, 2}, {3, 2}
    };

    int rst_sum = 0;
    for(int b = 0; b < 7; b++) {
        for(int r = 0; r < 4; r++) {
            for(int i = 0; i <= n - block_h_w[b].first; i++) {
                for(int j = 0; j <= m - block_h_w[b].second; j++) {
                    int tmp_sum = 0;
                    for(int k = 0; k < 4; k++) {
                        tmp_sum += board[block[b][k].first + i][block[b][k].second + j];
                    }
                    rst_sum = max(rst_sum, tmp_sum);
                }
            }
            
            block_rotate(block[b]);
            zero_loc(block[b]);
            int tmp_hw = block_h_w[b].first;
            block_h_w[b].first = block_h_w[b].second;
            block_h_w[b].second = tmp_hw; 
        }
    }
    
    cout << rst_sum << '\n';
}