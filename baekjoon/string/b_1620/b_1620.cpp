#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string str;
    map<string, int> info;
    vector<string> num(n);
    for (int i = 0; i < n; i++) {
        cin >> str;

        info.emplace(str, i);
        num[i] = str;
    }

    for (int i = 0; i < m; i++) {
        cin >> str;

        if (isdigit(str[0]))
            cout << num[stoi(str) - 1] << "\n";
        else
            cout << info[str] + 1 << "\n";
             
    }

    return 0;

}