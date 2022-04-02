#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string v[101][101];

string addStr(string s1, string s2) {
    long long ans = 0;
    string rst = "";

    while(!s1.empty() || !s2.empty() || ans) {
        if(!s1.empty()) {
            ans += s1.back() - '0';
            s1.pop_back();
        }
        if(!s2.empty()) {
            ans += s2.back() - '0';
            s2.pop_back();
        }
        
        rst += (ans % 10) + '0';
        ans /= 10;
    }

    reverse(rst.begin(), rst.end());
    return rst;
}

string comb(int n, int k) {
    if(n == k || k == 0) return "1";
    string &rst = v[n][k];

    if(rst != "") return rst;
    rst = addStr(comb(n - 1, k - 1), comb(n - 1, k));
    return rst;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> n >> k;

    cout << comb(n, k);
    return 0;
}