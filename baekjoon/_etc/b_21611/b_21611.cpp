#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, -1, 1};

const int move_dy[] = {0, 1, 0, -1};
const int move_dx[] = {-1, 0, 1, 0};

int n, m;
int shark_y, shark_x;
vector<vector<int>> board;
vector<int> final_v_num;
vector<int> bomb(4);
bool all_zero = false;

bool erase() {
    bool is_erase = false;
    vector<int> v_num;
    int cur_y = shark_y, cur_x = shark_x;
    int dir = 0;
    int cnt = 0;
    int num = 1;

    // 0이 아닌 숫자 v_num에 저장
    while(1) {
        if(cur_x <= 0) break;
        if(cnt == 2) {
            cnt = 0;
            num++;
        }

        int tmp_num = num;
        while(tmp_num--) {
            cur_y += move_dy[dir];
            cur_x += move_dx[dir];
            if(cur_x <= 0) break;   /* 이거 중요 이거 때문에 틀림(75%): board 범위 [(1, 1) ~ (N, N)] */
            if(board[cur_y][cur_x])
                v_num.push_back(board[cur_y][cur_x]);
        }
        
        dir = (dir == 3)? 0 : dir + 1;
        cnt++;
    }
    if(v_num.empty()) {
        all_zero = true;
        return false;
    }

    // v_num의 4개 연속 숫자 지우기
    int same_cnt = 1;
    int curr = v_num[0];
    for(int i = 1; i < v_num.size(); i++) {
        if(curr == v_num[i]) {
            same_cnt++;
        } else {
            same_cnt = 1;
            curr = v_num[i];
        }

        if(same_cnt == 4) {
            is_erase = true;
            if(curr <= 3) bomb[curr] += 4;
            v_num[i] = 0;
            v_num[i - 1] = 0;
            v_num[i - 2] = 0;
            v_num[i - 3] = 0;
        } else if(same_cnt > 4) {
            if(curr <= 3) bomb[curr] += 1;
            v_num[i] = 0;
        }
    }

    // after_v_num 에 남아있는 숫자 저장
    vector<int> after_v_num;
    for(int i = 0; i < v_num.size(); i++) {
        if(v_num[i]) {
            after_v_num.push_back(v_num[i]);
        }
    }
    if(after_v_num.empty()) {
        all_zero = true;
        return false;
    }

    // board로 옮기기
    vector<vector<int>> move_board(n + 1, vector<int>(n + 1));
    cur_y = shark_y, cur_x = shark_x;
    dir = 0;
    cnt = 0;
    num = 1;
    int idx = 0;
    while(idx < after_v_num.size()) {
        if(cur_x <= 0) break;
        if(cnt == 2) {
            cnt = 0;
            num++;
        }

        int tmp_num = num;
        while(tmp_num--) {
            cur_y += move_dy[dir];
            cur_x += move_dx[dir];
            if(cur_x <= 0) break;   /* 이거 중요 이거 때문에 틀림 */
            move_board[cur_y][cur_x] = after_v_num[idx++];
            if(idx >= after_v_num.size()) break;
        }
        
        dir = (dir == 3)? 0 : dir + 1;
        cnt++;
    }

    board = move_board;
    final_v_num = after_v_num;
    return is_erase;
}

void changeBoard() {
    vector<int> v_ch;
    int cur = final_v_num[0];
    int cnt = 1;
    for(int i = 1; i < final_v_num.size(); i++) {
        if(cur == final_v_num[i]) {
            cnt++;
        } else {
            v_ch.push_back(cnt);
            v_ch.push_back(cur);

            cur = final_v_num[i];
            cnt = 1;
        }
    }
    v_ch.push_back(cnt);
    v_ch.push_back(cur);
    
    vector<vector<int>> ch_board(n + 1, vector<int>(n + 1));
    int cur_y = shark_y, cur_x = shark_x;
    int dir = 0;
    cnt = 0;
    int num = 1;
    int idx = 0;
    while(idx < v_ch.size()) {
        if(cur_x <= 0) break;
        if(cnt == 2) {
            cnt = 0;
            num++;
        }

        int tmp_num = num;
        while(tmp_num--) {
            cur_y += move_dy[dir];
            cur_x += move_dx[dir];
            if(cur_x <= 0) break;   /* 이거 중요 이거 때문에 틀림 */
            ch_board[cur_y][cur_x] = v_ch[idx++];
            if(idx >= v_ch.size()) break;
        }
        
        dir = (dir == 3)? 0 : dir + 1;
        cnt++;
    }

    board = ch_board;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    board.resize(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    shark_y = shark_x = (n + 1) / 2;
    while(m--) {
        int d, s;
        cin >> d >> s;

        // 1
        for(int i = 1; i <= s; i++)
            board[shark_y + dy[d] * i][shark_x + dx[d] * i] = 0;

        // 2 구슬 폭발
        while(1) {
            if(!erase()) break;
        }
        if(all_zero) break;     /* board 에 모두 0으로 채워져있다면 끝! */

        // 3 구슬 변화
        changeBoard();

    }

    int sum = 0;
    for(int i = 1; i <= 3; i++) {
        sum += i * bomb[i];
    }
    cout << sum << '\n';
    return 0;

}