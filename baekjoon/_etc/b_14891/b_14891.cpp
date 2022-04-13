#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> wheel(5, vector<int>(8));

    for(int i = 1; i <= 4; i++) {
        for(int j = 0; j < 8; j++) {
            scanf("%1d", &wheel[i][j]);
        }
    }
    
    int num, w_num, dir;
    vector<int> w_top(5, 0);
    scanf("%d", &num);
    while(num--) {
        scanf("%d %d", &w_num, &dir);

        vector<int> next_dir(5, 0);
        int cur_r = w_num;
        next_dir[cur_r] = dir;
        while(cur_r + 1 <= 4) {          // RIGHT
            int curr = w_top[cur_r] + 2;
            int next = w_top[cur_r + 1] - 2;
            if(curr > 7) curr -= 8;
            if(next < 0) next += 8;
            
            if(wheel[cur_r + 1][next] == wheel[cur_r][curr]) {
                break;
            } else {
                next_dir[cur_r + 1] = next_dir[cur_r] * -1;
            }

            cur_r++;
        }

        int cur_l = w_num;
        while(cur_l - 1 >= 1) {          // LEFT
            int curr = w_top[cur_l] - 2;
            int next = w_top[cur_l - 1] + 2;
            if(curr < 0) curr += 8;
            if(next > 7) next -= 8;
            
            if(wheel[cur_l - 1][next] == wheel[cur_l][curr]) {
                break;
            } else {
                next_dir[cur_l - 1] = next_dir[cur_l] * -1;
            }

            cur_l--;
        }

        for(int i = 1; i <= 4; i++) {
            if(next_dir[i] == 0)
                continue;
            else if (next_dir[i] == 1) {
                w_top[i] -= 1;
                if(w_top[i] < 0) w_top[i] += 8;
            } else {
                w_top[i] += 1;
                if(w_top[i] > 7) w_top[i] -= 8;
            }
        }
    }

    int sum = 0;
    (wheel[1][w_top[1]] == 0)? sum += 0 : sum += 1;
    (wheel[2][w_top[2]] == 0)? sum += 0 : sum += 2;
    (wheel[3][w_top[3]] == 0)? sum += 0 : sum += 4;
    (wheel[4][w_top[4]] == 0)? sum += 0 : sum += 8;

    printf("%d\n", sum);
}