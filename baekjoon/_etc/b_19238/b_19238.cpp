#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, oil;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<vector<int>> board;
vector<vector<int>> start_board;
vector<vector<vector<int>>> end_board;

int find_person(int &num, int &yy, int &xx) {
    int time = 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));
    queue<pair<int, int>> q;
    q.emplace(yy, xx);
    visited[yy][xx] = true;

    vector<pair<int, int>> tmp;

    while(!q.empty()) {
        int q_size = q.size();
        bool is_person = false;

        while(q_size--) {
            int y = q.front().first;
            int x = q.front().second;
            if(start_board[y][x] > 0) {
                is_person = true;
                break;
            }
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny <= 0 || ny > n || nx <= 0 || nx > n)
                    continue;
                
                if(!visited[ny][nx] && board[ny][nx] != 1) {
                    visited[ny][nx] = true;
                    q.emplace(ny, nx);
                }
            }
        }

        if(is_person) {
            q_size += 1;
            while(q_size--) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if(start_board[y][x]) {
                    tmp.emplace_back(y, x);
                }
            }

            break;
        }

        time++;
    }

    if(!tmp.empty()) {
        sort(tmp.begin(), tmp.end());
        yy = tmp[0].first;
        xx = tmp[0].second;
        num = start_board[yy][xx];
        start_board[yy][xx] = 0;
    } else {
        time = -1;
    }

    return time;
}

int find_goal(int &num, int &yy, int &xx) {
    int time = 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));
    queue<pair<int, int>> q;
    q.emplace(yy, xx);
    visited[yy][xx] = true;

    while(!q.empty()) {
        int q_size = q.size();

        bool is_find = false;
        while(q_size--) {
            int y = q.front().first;
            int x = q.front().second;
            for(int e = 0; e < end_board[y][x].size(); e++) {
                if(end_board[y][x][e] == num) {
                    is_find = true;
                    end_board[y][x][e] = 0;
                    yy = y;
                    xx = x;
                    break;
                }
            }
            if(is_find) break;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny <= 0 || ny > n || nx <= 0 || nx > n)
                    continue;
                
                if(!visited[ny][nx] && board[ny][nx] != 1) {
                    visited[ny][nx] = true;
                    q.emplace(ny, nx);
                }
            }   
        }   

        if(is_find)
            return time;

        time++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> oil;

    board.resize(n + 1, vector<int>(n + 1));
    start_board.resize(n + 1, vector<int>(n + 1));
    end_board.resize(n + 1, vector<vector<int>>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    int taxi_y, taxi_x;
    cin >> taxi_y >> taxi_x;
    for(int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        start_board[a][b] = i;
        end_board[c][d].push_back(i);;
    }

    int p_num = 0;
    for(int i = 0; i < m; i++) {
        int taxi_to_person = find_person(p_num, taxi_y, taxi_x);
        if(taxi_to_person == -1) {
            cout << "-1\n";
            return 0;
        }

        int person_to_goal = find_goal(p_num, taxi_y, taxi_x);
        if(person_to_goal == -1) {
            cout << "-1\n";
            return 0;
        }

        int move = taxi_to_person + person_to_goal;
        if(oil < move) {
            cout << "-1\n";
            return 0;
        }

        oil = oil - move + 2 * person_to_goal;
    }

    cout << oil << '\n';
    return 0;
}