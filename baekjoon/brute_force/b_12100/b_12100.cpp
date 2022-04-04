#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, max_value = 0;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

vector<vector<int>> makeMap(vector<vector<int>> m, int dir) {
    vector<vector<int>> tmp(n, vector<int>(n));

    if(dir == 0) {
        for(int i = 0; i < n; i++) {
            queue<int> q;
            int idx = n - 1;
            for(int j = n - 1; j >= 0; j--) {
                if(m[i][j]) {
                    q.push(m[i][j]);
                }

                if(q.size() == 2) {
                    if(q.front() == q.back()) {
                        if(max_value < q.front() * 2)
                            max_value =  q.front() * 2;
                        tmp[i][idx--] = q.front() * 2;
                        q.pop();
                        q.pop();
                    } else {
                        if(max_value < q.front())
                            max_value =  q.front();
                        tmp[i][idx--] = q.front();
                        q.pop();
                    }
                }
            }
            if(!q.empty())
                tmp[i][idx] = q.front();
        }
    } else if(dir == 1) {
        for(int i = 0; i < n; i++) {
            queue<int> q;
            int idx = n - 1;
            for(int j = n - 1; j >= 0; j--) {
                if(m[j][i]) {
                    q.push(m[j][i]);
                }

                if(q.size() == 2) {
                    if(q.front() == q.back()) {
                        if(max_value < q.front() * 2)
                            max_value =  q.front() * 2;
                        tmp[idx--][i] = q.front() * 2;
                        q.pop();
                        q.pop();
                    } else {
                        if(max_value < q.front())
                            max_value =  q.front();
                        tmp[idx--][i] = q.front();
                        q.pop();
                    }
                }
            }
            if(!q.empty())
                tmp[idx][i] = q.front();
        }
    } else if(dir ==2) {
        for(int i = 0; i < n; i++) {
            queue<int> q;
            int idx = 0;
            for(int j = 0; j < n; j++) {
                if(m[i][j]) {
                    q.push(m[i][j]);
                }

                if(q.size() == 2) {
                    if(q.front() == q.back()) {
                        if(max_value < q.front() * 2)
                            max_value =  q.front() * 2;
                        tmp[i][idx++] = q.front() * 2;
                        q.pop();
                        q.pop();
                    } else {
                        if(max_value < q.front())
                            max_value =  q.front();
                        tmp[i][idx++] = q.front();
                        q.pop();
                    }
                }
            }
            if(!q.empty())
                tmp[i][idx] = q.front();
        }
    } else if(dir ==3) {
        for(int i = 0; i < n; i++) {
            queue<int> q;
            int idx = 0;
            for(int j = 0; j < n; j++) {
                if(m[j][i]) {
                    q.push(m[j][i]);
                }

                if(q.size() == 2) {
                    if(q.front() == q.back()) {
                        if(max_value < q.front() * 2)
                            max_value =  q.front() * 2;
                        tmp[idx++][i] = q.front() * 2;
                        q.pop();
                        q.pop();
                    } else {
                        if(max_value < q.front())
                            max_value =  q.front();
                        tmp[idx++][i] = q.front();
                        q.pop();
                    }
                }
            }

            if(!q.empty())
                tmp[idx][i] = q.front();
        }
    }

    return tmp;
}

void dfs(vector<vector<int>> v, int num) {
    if(num == 5) return;

    for(int i = 0; i < 4; i++) {
        dfs(makeMap(v, i), num + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(max_value < map[i][j])
                max_value = map[i][j];
        }
    }
    
    dfs(map, 0);
    cout << max_value << '\n';
    return 0;
}