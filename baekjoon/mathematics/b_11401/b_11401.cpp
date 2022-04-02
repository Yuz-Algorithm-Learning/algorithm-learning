#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll pow(ll a, ll b) {
    if(b == 0)
        return 1;
    if(b % 2) 
        return (pow(a, b - 1) * a) % 1000000007;
    
    ll half = pow(a, b / 2) % 1000000007;
    return half * half % 1000000007;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    ll a = 1, b = 1;    // a = n!, b = k!(n-k)!
    for(ll i = 1; i <= n; i++) {
        a *= i;
        a %= 1000000007;
    }
    for(ll i = 1; i <= k; i++) {
        b *= i;
        b %= 1000000007;
    }
    for(ll i = 1; i <= (n - k); i++) {
        b *= i;
        b %= 1000000007;
    }

    ll b2 = pow(b, 1000000007 - 2);
    cout << a * b2 % 1000000007;

    return 0;
}