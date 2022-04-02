#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int x_value = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    int r, c;
    cin >> r >> c;

    vector<string> water_map(r);
    vector<pair<int, int>> swan;
    queue<pair<int, int>> q_water;

    for(int i = 0; i < r; i++) {
        cin >> water_map[i];
        for(int j = 0; j < c; j++) {
            if(water_map[i][j] == 'L') {
                water_map[i][j] = '.';
                q_water.emplace(i, j);
                swan.emplace_back(i, j);
            } else if (water_map[i][j] == '.') {
                q_water.emplace(i, j);
            }
        }
    }

    int day = 0;
    vector<vector<bool>> visited_swan(r, vector<bool>(c));
    queue<pair<int, int>> curr_swan;
    curr_swan.emplace(swan[0]);
    visited_swan[swan[0].first][swan[0].second] = true;
    while(1) {
        queue<pair<int, int>> next_swan;
        while(!curr_swan.empty()) {
            int y = curr_swan.front().first;
            int x = curr_swan.front().second;
            curr_swan.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= r || nx < 0 || nx >= c) 
                    continue;
                
                if(ny == swan[1].first && nx == swan[1].second) {
                    cout << day++;
                    return 0;
                }

                if(!visited_swan[ny][nx]) {
                    visited_swan[ny][nx] = true;

                    if(water_map[ny][nx] == '.') {
                        curr_swan.emplace(ny, nx);
                    } else if(water_map[ny][nx] == 'X') {
                        next_swan.emplace(ny, nx);
                    }

                }
            }
        }

        curr_swan = next_swan;
        day++;

        int water_size = q_water.size();
        while(water_size--) {
            int y = q_water.front().first;
            int x = q_water.front().second;
            q_water.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= r || nx < 0 || nx >= c) 
                    continue;
                
                if(water_map[ny][nx] == 'X') {
                    water_map[ny][nx] = '.';
                    q_water.emplace(ny, nx);
                }
            }
        }
    }
    
    return 0;
}