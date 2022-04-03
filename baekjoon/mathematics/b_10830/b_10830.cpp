#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, b;
vector<vector<long long>> v;
vector<vector<long long>> rst;

void cal(vector<vector<long long>> v1, vector<vector<long long>> v2) {
    vector<vector<long long>> tmp(n, vector<long long>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int m = 0; m < n; m++) {
                tmp[i][j] += v1[i][m] * v2[m][j];
            }
            tmp[i][j] = tmp[i][j] % 1000;
        }
    }

    rst = tmp;
}

void solve(long long num) {
    if(num == 1) {
        cal(rst, v);
        return;
    }
    
    if(num % 2) {
        solve(num / 2);
        cal(rst, rst);
        cal(rst, v);
    } else {
        solve(num / 2);
        cal(rst, rst);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n >> b;

    v.resize(n, vector<long long>(n));
    rst.resize(n, vector<long long>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
        rst[i][i] = 1;
    }

    solve(b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << rst[i][j] << ' ';
        }
        cout << '\n';
    }
}
    
