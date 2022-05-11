#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> roots(n + 1);
        for(int i = 0; i < n - 1; i++) {
            int t1, t2;
            cin >> t1 >> t2;

            roots[t2] = t1;
        }

        int n1, n2;
        cin >> n1 >> n2;

        int tmp = n1;
        vector<int> n1_roots;
        n1_roots.push_back(n1);
        while(1) {
            tmp = roots[tmp];
            if(tmp == 0) break;

            n1_roots.push_back(tmp);
        }

        tmp = n2;
        while(1) {
            if(find(n1_roots.begin(), n1_roots.end(), tmp) != n1_roots.end()) {
                cout << tmp << '\n';
                break;
            }
            tmp = roots[tmp];
        }

    }

    return 0;
}