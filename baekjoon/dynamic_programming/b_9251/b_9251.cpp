#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int x = a.size() + 1;   // 7
    int y = b.size() + 1;   // 7

    vector<vector<int>> lcs(y, vector<int>(x, 0));

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {

            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (b[i - 1] == a[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);          

        }
    }

    cout << lcs[b.size()][a.size()];
}
