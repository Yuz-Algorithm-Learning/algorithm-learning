#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;

int roots[200001];
int roots_num[200001];

int find(int x) {
    if(roots[x] == x) return x;
    return roots[x] = find(roots[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(y == x) {
        cout << roots_num[x] << '\n';
        return;
    }
    
    if(x < y) {
        roots[y] = x;
        roots_num[x] += roots_num[y];
        cout << roots_num[x] << '\n';
    } else {
        roots[x] = y;
        roots_num[y] += roots_num[x];
        cout << roots_num[y] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int f;
        cin >> f;
        
        memset(roots, 0, sizeof(roots));
        memset(roots_num, 0, sizeof(roots_num));
        map<string, int> info;
        int idx = 1;

        for(int i = 0; i < f; i++) {
            string s1, s2;
            cin >> s1 >> s2;

            if(!info[s1]) {
                roots[idx] = idx;
                roots_num[idx] = 1;
                info[s1] = idx++;
            }
            if(!info[s2]) {
                roots[idx] = idx;
                roots_num[idx] = 1;
                info[s2] = idx++;
            }
            
            merge(info[s1], info[s2]);
        }
    }
}