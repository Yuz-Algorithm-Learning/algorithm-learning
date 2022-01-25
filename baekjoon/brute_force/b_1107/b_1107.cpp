#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<bool> break_num(10, false);

bool check(int curr) {
    string str = to_string(curr);
    for (int i = 0; i < str.size(); i++) {
        if (break_num[str[i] - '0'])
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int tmp;
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        break_num[tmp] = true;
    }

    int ans_min = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        if (check(i)) {
            int tmp_min = abs(n - i) + to_string(i).size();
            ans_min = min(ans_min, tmp_min);
        }
    }

    printf("%d", ans_min);
}
