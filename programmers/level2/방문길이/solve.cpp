#include <string>
#include <map>
#include <iostream>
using namespace std;

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

int solution(string dirs) {
    int answer = 0;
    map<point, bool> mm;
    
    int y = 0, x = 0;
    for(int i = 0; i < dirs.size(); i++) {
        if(dirs[i] == 'U') {
            if(y < 5) {
                if(!mm[{y, x, y + 1, x}]) {
                    mm[{y, x, y + 1, x}] = true;
                }
                y++;
            }
        } else if(dirs[i] == 'D') {
            if(y > -5) {
                if(!mm[{y - 1, x, y, x}]) {
                    mm[{y - 1, x, y, x}] = true;
                }
                y--;
            }
        } else if(dirs[i] == 'R') {
            if(x < 5) {
                if(!mm[{y, x, y, x + 1}]) {
                    mm[{y, x, y, x + 1}] = true;
                }
                x++;
            }
        } else {
            if(x > -5) {
                if(!mm[{y, x - 1, y, x}]) {
                    mm[{y, x - 1, y, x}] = true;
                }
                x--;
            }
        }
    }
    
    return mm.size();
}