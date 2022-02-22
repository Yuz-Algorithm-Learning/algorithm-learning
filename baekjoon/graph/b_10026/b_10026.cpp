#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int blue = 0;
int rg1 = 0;
int rg2 = 0;
vector<vector<char>> map;
vector<vector<bool>> rg;
vector<vector<bool>> visit;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void rgb(int type, int y, int x) {
    visit[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if(type == 1) {
            if(map[ny][nx] == map[y][x] && !visit[ny][nx])
                rgb(type, ny, nx);
        } else {
            if(rg[ny][nx] == 1 && !visit[ny][nx])
                rgb(type, ny, nx);
        }
    }

}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    map.resize(n, vector<char>(n));
    rg.resize(n, vector<bool>(n));
    visit.resize(n, vector<bool>(n));

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < n; j++) {
            map[i][j] = str[j];

            if(str[j] == 'R' || str[j] == 'G') {
                rg[i][j] = true;
            }
        }
    }

    /* type 1: 적록색약이 아닌 사람이 봤을 때의 구역의 수 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j]) {
                if(map[i][j] == 'B')
                    blue++;
                else
                    rg1++;

                rgb(1, i, j);
            }
        }
    }

    visit.clear();
    visit.resize(n, vector<bool>(n));

    /* type 2: 적록색약인 사람이 봤을 때의 구역의 수 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(rg[i][j] == 1 && !visit[i][j]) {
                rg2++;
                rgb(2, i, j);
            }
        }
    }

    cout << blue + rg1 << " " << blue + rg2 << "\n";
}