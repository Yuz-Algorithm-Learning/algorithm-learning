#include <iostream>
#include <vector>

using namespace std;

vector<int> roots;

int find(int x) {
    if(roots[x] == x) return x;
    return roots[x] = find(roots[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    roots[a] = b;
}

bool check(int a, int b) {
    a = find(a);
    b = find(b);
    return (a == b)? true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    roots.resize(n + 1);
    for(int i = 0; i <= n; i++)
        roots[i] = i;
    
    for(int i = 0; i < m; i++) {
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 0)
            merge(a, b);
        else {
            if(check(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
