#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

struct Info {
    int x;
    int y;
    int type;
    
    bool operator<(const Info& other) const
    {
        if (x != other.x)
            return (x < other.x);
        if (y != other.y)
            return (y < other.y);
        return (type < other.type);
    }
};

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    map<Info, bool> map_info;
    
    for(int i = 0; i < build_frame.size(); i++) {
        if(build_frame[i][2] == 0) {    // 기둥
            if(build_frame[i][3] == 1) {     // 설치
                if(build_frame[i][1] == 0) { // 0 일 때
                    map_info[{build_frame[i][0], 1, 0}] = true;
                } else {
                    if(map_info[{build_frame[i][0], build_frame[i][1], 0}] || 
                       map_info[{build_frame[i][0] - 1, build_frame[i][1], 1}] ||
                       map_info[{build_frame[i][0], build_frame[i][1], 1}]) {
                        map_info[{build_frame[i][0], build_frame[i][1] + 1, 0}] = true;
                    }
                }
            } else {                        // 삭제
                if(map_info[{build_frame[i][0], build_frame[i][1] + 2, 0}]) {       // 기둥이 있다면
                    if(!map_info[{build_frame[i][0] - 1, build_frame[i][1] + 1, 1}] &&
                       !map_info[{build_frame[i][0], build_frame[i][1] + 1, 1}] ) {
                        continue;
                    }
                }
                if(map_info[{build_frame[i][0] - 1, build_frame[i][1] + 1, 1}]) {   // 왼쪽 보가 있다면
                    if(!map_info[{build_frame[i][0] - 1, build_frame[i][1] + 1, 0}] &&
                       (!map_info[{build_frame[i][0] - 2, build_frame[i][1] + 1, 1}] ||
                        !map_info[{build_frame[i][0], build_frame[i][1] + 1, 1}])) {
                        continue;
                    }
                } 
                if(map_info[{build_frame[i][0], build_frame[i][1] + 1, 1}]) {       // 오른쪽 보가 있다면
                    if(!map_info[{build_frame[i][0] + 1, build_frame[i][1] + 1, 0}] &&
                       (!map_info[{build_frame[i][0] - 1, build_frame[i][1] + 1, 1}] ||
                        !map_info[{build_frame[i][0] + 1, build_frame[i][1] + 1, 1}])) {
                        continue;
                    }
                }
                
                map_info[{build_frame[i][0], build_frame[i][1] + 1, 0}] = false;
            }
        } else {                        // 보
            if(build_frame[i][3] == 1) {    // 설치
                if(map_info[{build_frame[i][0], build_frame[i][1], 0}] || 
                   map_info[{build_frame[i][0] + 1, build_frame[i][1], 0}]) 
                {
                    map_info[{build_frame[i][0], build_frame[i][1], 1}] = true;

                } else if(map_info[{build_frame[i][0] - 1, build_frame[i][1], 1}] && 
                   map_info[{build_frame[i][0] + 1, build_frame[i][1], 1}]) 
                {
                    map_info[{build_frame[i][0], build_frame[i][1], 1}] = true;
                }
                
            } else {                        // 삭제
                if(map_info[{build_frame[i][0], build_frame[i][1] + 1, 0}]) {       // 왼쪽 기둥이 있다면
                    if(!map_info[{build_frame[i][0], build_frame[i][1], 0}] &&
                       !map_info[{build_frame[i][0] - 1, build_frame[i][1], 1}] ) {
                        continue;
                    }
                }
                if(map_info[{build_frame[i][0] + 1, build_frame[i][1] + 1, 0}]) {   // 오른쪽 기둥이 있다면
                    if(!map_info[{build_frame[i][0] + 1, build_frame[i][1], 0}] &&
                       !map_info[{build_frame[i][0] + 1, build_frame[i][1], 1}] ) {
                        continue;
                    }
                }
                if(map_info[{build_frame[i][0] - 1, build_frame[i][1], 1}]) {       // 왼쪽 보가 있다면
                    if(!map_info[{build_frame[i][0] - 1, build_frame[i][1], 0}] && 
                       !map_info[{build_frame[i][0], build_frame[i][1], 0}]) {
                        continue;
                    }
                } 
                if(map_info[{build_frame[i][0] + 1, build_frame[i][1], 1}]) {       // 오른쪽 보가 있다면
                    if(!map_info[{build_frame[i][0] + 1, build_frame[i][1], 0}] && 
                       !map_info[{build_frame[i][0] + 2, build_frame[i][1], 0}]) {
                        continue;
                    }
                }
                
                map_info[{build_frame[i][0], build_frame[i][1], 1}] = false;
            }
            
        }
    }
    
    vector<Info> v;
    for(auto &m : map_info) {
        if(m.second) {
            if(m.first.type == 0) {
                v.push_back({m.first.x, m.first.y - 1, m.first.type});
            } else {
                v.push_back({m.first.x, m.first.y, m.first.type});
            }
        }
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        answer.push_back({v[i].x, v[i].y, v[i].type});
    }
    
    return answer;
}