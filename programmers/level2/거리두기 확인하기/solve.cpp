#include <string>
#include <vector>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

vector<vector<bool>> visit;
vector<vector<string>> place;

bool is_dis(int idx, int y, int x, bool type) {  /* type: true -> 이전이 P 인 경우 */
    visit[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
            continue;
        
        if(place[idx][ny][nx] == 'P' && !visit[ny][nx]) {
            return false;
        } else if(place[idx][ny][nx] == 'O' && !visit[ny][nx]) {
            if(!type) {
                if(!is_dis(idx, ny, nx, true)) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    place = places;

    for(int i = 0; i < places.size(); i++) {
        bool dis = true;

        for(int y = 0; y < places[i].size(); y++) {
            for(int x = 0; x < 5; x++) {
                if(places[i][y][x] == 'P') {
                    visit.resize(5, vector<bool>(5));
                    if(!is_dis(i, y, x, false)) {
                        dis = false;
                        break;
                    }
                    visit.clear();
                }
            }

            if(!dis) {
                answer.push_back(0);
                break;
            }
        }  

        if(dis)
            answer.push_back(1);      
        
    }
    return answer;
}