#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
vector<int> rc;

/* num H m */
void repeatedCombibation(int idx, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", rc[i]);
        printf("\n");

        return;
    }
    else {
        for (int i = idx; i < num.size(); i++) {
            rc[depth] = num[i];
            repeatedCombibation(i, depth + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    rc.resize(m);

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    repeatedCombibation(0, 0);
}
