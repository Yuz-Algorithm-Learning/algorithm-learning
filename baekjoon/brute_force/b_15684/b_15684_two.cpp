#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, h;
int ans = 987654321;
vector<vector<bool>> lines;

bool i_to_i() {
    for(int i = 1; i <= n; i++) {
        int tmp_n = i;
        for(int j = 1; j <= h; j++) {
            if(lines[j][tmp_n - 1]) 
                tmp_n -= 1;
            else if(lines[j][tmp_n])
                tmp_n += 1;
        }

        if(i != tmp_n) return false;
    }
    return true;
}

void select_line(int max_line, int hh, int cnt) {
    if(max_line == cnt) {
        if(i_to_i()) {
            cout << max_line << '\n';
            exit(0);
        }
        return;
    }

    for(int i = hh; i <= h; i++) {
        for(int j = 1; j < n; j++) {
            if(!lines[i][j] && !lines[i][j - 1] && !lines[i][j + 1]) {
                lines[i][j] = true;
                select_line(max_line, i, cnt + 1);
                lines[i][j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    lines.resize(h + 1, vector<bool>(n + 1));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lines[a][b] = true;
    }

    for(int i = 0; i < 4; i++)
        select_line(i, 1, 0);

    cout << "-1\n";
}