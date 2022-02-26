#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows + 1, vector<int>(columns + 1));
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            map[i][j] = (i - 1) * columns + j;
        }
    }

    for(int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        int x_dis = x2 - x1;
        int y_dis = y2 - y1;

        int nx = x1;
        int ny = y1;
        
        int start = map[nx][ny];
        int min_num = start;
        for(int j = 0; j < x_dis; j++) {        /* LEFT */
            map[nx][ny] = map[nx + 1][ny];
            nx++;

            if(map[nx][ny] < min_num)
                min_num = map[nx][ny];
        }
        for(int j = 0; j < y_dis; j++) {        /* BOTTOM */
            map[nx][ny] = map[nx][ny + 1];
            ny++;

            if(map[nx][ny] < min_num)
                min_num = map[nx][ny];
        }
        for(int j = 0; j < x_dis; j++) {        /* RIGHT */
            map[nx][ny] = map[nx - 1][ny];
            nx--;

            if(map[nx][ny] < min_num)
                min_num = map[nx][ny];
        }
        for(int j = 0; j < y_dis - 1; j++) {    /* TOP */
            map[nx][ny] = map[nx][ny - 1];
            ny--;

            if(map[nx][ny] < min_num)
                min_num = map[nx][ny];
        }
        map[nx][ny] = start;

        answer.push_back(min_num);
    }

    return answer;
}