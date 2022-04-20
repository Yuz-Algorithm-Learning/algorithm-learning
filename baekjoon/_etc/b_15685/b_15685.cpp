#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
int visited[101][101] = {0, };

void block_rotate(vector<pair<int, int>> &block) {
    vector<pair<int, int>> tmp_block;

    int max_y = -987654321;
    for(int i = 0; i < block.size(); i++) {
        if(max_y < block[i].first)
            max_y = block[i].first;
    }

    for(int i = 0; i < block.size(); i++) {
        tmp_block.emplace_back(block[i].second, max_y - block[i].first);
    }

    block = tmp_block;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> total_v;
    while(n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<pair<int, int>> tmp_v;
        tmp_v.emplace_back(y, x);
        int ny = y + dy[d];
        int nx = x + dx[d];
        tmp_v.emplace_back(y + dy[d], x + dx[d]);

        while(g--) {
            vector<pair<int, int>> rotate_v = tmp_v;
            block_rotate(rotate_v);
            reverse(rotate_v.begin(), rotate_v.end());

            int yy = rotate_v[0].first - tmp_v[tmp_v.size() - 1].first;
            int xx = rotate_v[0].second - tmp_v[tmp_v.size() - 1].second;
            for(int i = 0; i < rotate_v.size(); i++) {
                rotate_v[i].first -= yy;
                rotate_v[i].second -= xx;
            }
            tmp_v.pop_back();
            tmp_v.insert(tmp_v.end(), rotate_v.begin(), rotate_v.end());
        }
        
        total_v.insert(total_v.end(), tmp_v.begin(), tmp_v.end());    

    }

    for(int i = 0; i < total_v.size(); i++) {
        visited[total_v[i].first][total_v[i].second] = true;
    }

    int ans = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
                ans++;
        }
    }

    cout << ans << '\n';
}