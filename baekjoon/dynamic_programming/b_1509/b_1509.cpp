#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define INF 987654321

using namespace std; 

string str;
int dp[2501][2501];

int is_palindrome(int start, int end) {
    if (start >= end)
        return 1;

    int &rst = dp[start][end];
    if (rst != -1)
        return rst;

    if (str[start] == str[end])
        return rst = is_palindrome(start + 1, end - 1);
    else
        return rst = 0;
}

int main()
{
    cin >> str;
    str.insert(0, " ");

    vector<int> min_rst(str.size(), INF);
    min_rst[0] = 0;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i < str.size(); i++) {
        for (int j = 1; j <= i; j++) {
            if (is_palindrome(j, i))
                min_rst[i] = min(min_rst[i], min_rst[j - 1] + 1);
        }
    }

    printf("%d", min_rst[str.size() - 1]);
}
