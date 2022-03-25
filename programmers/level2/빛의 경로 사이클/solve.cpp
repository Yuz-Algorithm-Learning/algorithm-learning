#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int n, m;
bool visited[502][502][4];
vector<string> grid;
int cycle_len = 0;

void move_cycle(int y, int x, int dir, int len) {
    if(visited[y][x][dir]) {
        cycle_len = len;
        return;
    }
    visited[y][x][dir] = true;
    
    if(grid[y][x] == 'L')
        dir = dir? dir - 1 : 3;
    else if (grid[y][x] == 'R')
        dir = (dir != 3)? dir + 1 : 0;
    
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    
    if(ny < 0) ny = n - 1;
    if(nx < 0) nx = m - 1;
    if(ny >= n) ny = 0;
    if(nx >= m) nx = 0;
    
    move_cycle(ny, nx, dir, len + 1);
}

vector<int> solution(vector<string> g) {
    vector<int> answer;
    
    grid = g;
    n = grid.size();
    m = grid[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                if(visited[i][j][k])
                    continue;
                
                cycle_len = 0;
                move_cycle(i, j, k, 0);
                answer.push_back(cycle_len);
                
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}