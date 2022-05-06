#include <iostream>
#include <vector>
using namespace std;

vector<int> roots;

int find(int x) {
    if(roots[x] == x) return x;
    return roots[x] = find(roots[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(x < y) roots[y] = x;
    else roots[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    roots.resize(n + 1);
    for(int i = 1; i <= n; i++)
        roots[i] = i;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp) {
                merge(i, j);
            }
        }
    }

    vector<int> trip(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> trip[i];
    }
    
    int check = roots[trip[1]];
    for(int i = 2; i <= m; i++) {
        if(check != roots[trip[i]]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}