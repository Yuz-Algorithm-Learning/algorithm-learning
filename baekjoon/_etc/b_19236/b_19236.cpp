#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int sum = 0;

void fishMove(vector<vector<pair<int, int>>> &space, vector<pair<int, int>> &fish_loc) {
    for(int f = 1; f <= 16; f++) {
        int fish_y = fish_loc[f].first;
        int fish_x = fish_loc[f].second;
        if(fish_y == -1)
            continue;
        
        int fish_dir = space[fish_y][fish_x].second;

        for(int i = 0; i <= 8; i++) {
            int next_dir = fish_dir + i;
            if(next_dir > 8)
                next_dir -= 8;
            
            int ny = fish_y + dy[next_dir];
            int nx = fish_x + dx[next_dir];

            if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || space[ny][nx].first == 17)
                continue;
            
            space[fish_y][fish_x].second = next_dir;
            fish_loc[f] = {ny, nx};
            if(space[ny][nx].first != 0) {
                fish_loc[space[ny][nx].first] = {fish_y, fish_x};
            }
            swap(space[fish_y][fish_x], space[ny][nx]);
            break;
        }
    }
}

void sharkMove(vector<vector<pair<int, int>>> &space, vector<pair<int, int>> &fish_loc, int shark_y, int shark_x, int total_eat) {
    vector<vector<pair<int, int>>> before_space = space;
    vector<pair<int, int>> before_fish_loc = fish_loc;

    int shark_dir = space[shark_y][shark_x].second;

    vector<pair<int, int>> shark_move;
    for(int n = 1; n <= 3; n++) {
        int s_ny = shark_y + n * dy[shark_dir];
        int s_nx = shark_x + n * dx[shark_dir];

        if(s_ny < 0 || s_ny >= 4 || s_nx < 0 || s_nx >= 4)
            break;
        
        if(space[s_ny][s_nx].first)
            shark_move.emplace_back(s_ny, s_nx);
    }

    if(shark_move.empty()) {
        sum = max(sum, total_eat);
        return;
    }

    for(int i = 0; i < shark_move.size(); i++) {
        space = before_space;
        fish_loc = before_fish_loc;

        int sy = shark_move[i].first;
        int sx = shark_move[i].second;
        int eat = space[sy][sx].first;

        fish_loc[eat] = {-1, -1};
        space[shark_y][shark_x].second = space[sy][sx].second;
        space[sy][sx].first = 0;
        space[sy][sx].second = 0;
        swap(space[shark_y][shark_x], space[sy][sx]);

        fishMove(space, fish_loc);
        sharkMove(space, fish_loc, sy, sx, total_eat + eat);
    }
}

int main() {
    vector<vector<pair<int, int>>> space(4);
    vector<pair<int, int>> fish_loc(17);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            space[i].emplace_back(a, b);
            fish_loc[a] = {i, j};
        }
    }
    
    int shark_y = 0, shark_x = 0;
    sum += space[0][0].first;
    fish_loc[space[0][0].first] = {-1, -1};
    space[0][0].first = 17;

    fishMove(space, fish_loc);
    sharkMove(space, fish_loc, shark_y, shark_x, sum);

    cout << sum << '\n';
    return 0;
}