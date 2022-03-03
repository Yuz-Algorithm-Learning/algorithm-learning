#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> block_zip = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, 
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}
};                                      

void block_rotate(vector<pair<int, int>> &block) {
    vector<pair<int, int>> tmp;
    int h = block[3].first + 1;

    for(int i = 0; i < 4; i++) {
        tmp.emplace_back(block[i].second, h - block[i].first - 1);
    }

    block = tmp;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int c, p;
    scanf("%d %d", &c, &p);

    vector<int> field(c);
    for(int i = 0; i < c; i++)
        scanf("%d", &field[i]);
    
    int answer = 0;
    int rotate = 4;
    if(p == 1 || p == 3 || p == 4) {
        rotate = 2;
    } else if (p == 2) {
        rotate = 1;
    }

    while(rotate--) {
        int w = 0;
        for(int i = 0; i < 4; i++){
            if(w < block_zip[p - 1][i].second) {
                w = block_zip[p - 1][i].second;
            }
        }
        w += 1;

        vector<int> bottom(w);
        for(int i = 0; i < 4; i++) {
            if(bottom[block_zip[p - 1][i].second] < block_zip[p - 1][i].first) {
                bottom[block_zip[p - 1][i].second] = block_zip[p - 1][i].first;
            }
        }

        for(int idx = 0; idx < c - w + 1; idx++) {
            bool bottom_same = true;
            int first = bottom[0] + field[idx];

            for(int i = 1; i < w; i++) {
                if(first != (bottom[i] + field[idx + i])) {
                    bottom_same = false;
                    break;
                }
            }

            if(bottom_same)
                answer++;
        }

        block_rotate(block_zip[p - 1]);
        sort(block_zip[p - 1].begin(), block_zip[p - 1].end());
    }

    printf("%d\n", answer);
}