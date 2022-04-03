#include <iostream>
#include <vector>

using namespace std;

int fiboCycle(int num) {
    int p = 1;
    int a = 1, b = 1, tmp;

    while(1) {
        if(a == 0 && b == 1) {
            break;
        }
        tmp = a;
        a = b;
        b = (b + tmp) % num;

        p++;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p;
    cin >> p;

    int n, m;
    while(p--) {
        cin >> n >> m;
        cout << n << ' ' << fiboCycle(m) << '\n';
    }
}