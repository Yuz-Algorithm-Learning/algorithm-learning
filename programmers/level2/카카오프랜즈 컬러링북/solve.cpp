#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pic;
bool visit[101][101];

int mm, nn;
int cnt;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
    cnt++;
    visit[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= mm || nx < 0 || nx >= nn)
            continue;

        if(pic[ny][nx] == pic[y][x] && !visit[ny][nx])
            dfs(ny, nx);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    pic = picture;
    cnt = 0;
    mm = m;
    nn = n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visit[i][j] = false;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] != 0 && !visit[i][j]) {
                number_of_area++;
                
                cnt = 0;
                dfs(i, j);
                
                if(max_size_of_one_area < cnt)
                    max_size_of_one_area = cnt;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}