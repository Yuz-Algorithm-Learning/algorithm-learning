#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> nn(n);
    for (int i = 0; i < n; i++)
        cin >> nn[i];
    sort(nn.begin(), nn.end());

    vector<string> result;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if (binary_search(nn.begin(), nn.end(), str))
            result.push_back(str);
    }
    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (string re : result)
        cout << re << "\n";
}