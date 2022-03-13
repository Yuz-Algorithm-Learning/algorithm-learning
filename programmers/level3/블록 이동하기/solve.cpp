#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

vector<vector<int>> board;
int board_size;

typedef struct point{
    int p1_y;
    int p1_x;
    int p2_y;
    int p2_x;

    bool operator<(const point& other) const
    {
        if (p1_x != other.p1_x)
            return (p1_x < other.p1_x);
        if (p1_y != other.p1_y)
            return (p1_y < other.p1_y);
        if (p2_x != other.p2_x)
            return (p2_x < other.p2_x);
        if (p2_y != other.p2_y)
            return (p2_y < other.p2_y);
    }
} point;


int bfs(point start) {
    map<point, bool> visit;
    queue<pair<point, int>> q;
    q.emplace(start, 0);
    visit[{0, 0, 0, 1}] = 1;
    
    while(!q.empty()) {
        point coord = q.front().first;
        int num = q.front().second;
        q.pop();

        if((coord.p1_x == board_size - 1 && coord.p1_y == board_size - 1) 
        || (coord.p2_x == board_size - 1 && coord.p2_y == board_size - 1)) {
            return num;
        }

        point tmp1;
        if((coord.p2_y - coord.p1_y) == 0) {  // [가로인 상황]
            // left
            if(coord.p1_x - 1 >= 0 && board[coord.p1_y][coord.p1_x - 1] == 0) {
                tmp1 = {coord.p1_y, coord.p1_x - 1, coord.p1_y, coord.p1_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // right
            if(coord.p2_x + 1 < board_size && board[coord.p2_y][coord.p2_x + 1] == 0) {
                tmp1 = {coord.p2_y, coord.p2_x, coord.p2_y, coord.p2_x + 1};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // down & rotate
            if(coord.p1_y + 1 < board_size && coord.p2_y + 1 < board_size 
            && board[coord.p1_y + 1][coord.p1_x] == 0 && board[coord.p2_y + 1][coord.p2_x] == 0) {
                tmp1 = {coord.p1_y + 1, coord.p1_x, coord.p2_y + 1, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p1_y, coord.p1_x, coord.p1_y + 1, coord.p1_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p2_y, coord.p2_x, coord.p2_y + 1, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // up & rotate
            if(coord.p1_y - 1 >= 0 && coord.p2_y - 1 >= 0 
            && board[coord.p1_y - 1][coord.p1_x] == 0 && board[coord.p2_y - 1][coord.p2_x] == 0) {
                tmp1 = {coord.p1_y - 1, coord.p1_x, coord.p2_y - 1, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p1_y - 1, coord.p1_x, coord.p1_y, coord.p1_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p2_y - 1, coord.p2_x, coord.p2_y, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
        } 
        else {  // [세로인 상황]
            // up
            if(coord.p1_y - 1 >= 0 && board[coord.p1_y - 1][coord.p1_x] == 0) {
                tmp1 = {coord.p1_y - 1, coord.p1_x, coord.p1_y, coord.p1_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // down
            if(coord.p2_y + 1 < board_size && board[coord.p2_y + 1][coord.p2_x] == 0) {
                tmp1 = {coord.p2_y, coord.p2_x, coord.p2_y + 1, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // right & rotate
            if(coord.p1_x + 1 < board_size && coord.p2_x + 1 < board_size
                && board[coord.p1_y][coord.p1_x + 1] == 0 && board[coord.p2_y][coord.p2_x + 1] == 0) {
                tmp1 = {coord.p1_y, coord.p1_x + 1, coord.p2_y, coord.p2_x + 1};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p1_y, coord.p1_x, coord.p1_y, coord.p1_x + 1};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p2_y, coord.p2_x, coord.p2_y, coord.p2_x + 1};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
            // left & rotate
            if(coord.p1_x - 1 >= 0 && coord.p2_x - 1 >= 0
                && board[coord.p1_y][coord.p1_x - 1] == 0 && board[coord.p2_y][coord.p2_x - 1] == 0) {
                tmp1 = {coord.p1_y, coord.p1_x - 1, coord.p2_y, coord.p2_x - 1};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p1_y, coord.p1_x - 1, coord.p1_y, coord.p1_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
                tmp1 = {coord.p2_y, coord.p2_x - 1, coord.p2_y, coord.p2_x};
                if(!visit[tmp1]) {
                    visit[tmp1] = 1;
                    q.emplace(tmp1, num + 1);
                }
            }
        }
    }

    return 0;
}

int solution(vector<vector<int>> bb) {
    board = bb;
    board_size = bb.size();
    int answer = 0;

    return bfs({0, 0, 0, 1}); 
}