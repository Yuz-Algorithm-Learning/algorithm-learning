#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string site, pw;
    map<string, string> info;
    for(int i = 0; i < n; i++) {
        cin >> site >> pw;
        info.emplace(site, pw);
    }

    for(int i = 0; i < m; i++) {
        cin >> site;
        cout << info[site] << "\n";
    }
}