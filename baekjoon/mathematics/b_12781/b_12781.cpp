#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll tmp = (p2.first * p3.second + p3.first * p1.second + p1.first * p2.second) - (p3.first * p2.second + p1.first * p3.second + p2.first * p1.second);
    
    if(tmp < 0) return -1;
    else if (tmp == 0) return 0;
    else return 1;
}

bool isCross(pair<ll, ll> s1, pair<ll, ll> e1, pair<ll, ll> s2, pair<ll, ll> e2) {
    int s1e1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    int s2e2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);

    return s1e1 < 0 && s2e2 < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<ll, ll> p[4];
    for(int i = 0; i < 4; i++) {
        cin >> p[i].first >> p[i].second;
    }

    cout << isCross(p[0], p[1], p[2], p[3]) << '\n';
    return 0;
}