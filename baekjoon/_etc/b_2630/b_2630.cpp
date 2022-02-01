#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int w = 0, b = 0;

bool same(int y1, int x1, int y2, int x2) {
    int tmp = map[y1][x1];

    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            if (map[i][j] != tmp)
                return false;
        }
    }

    (tmp == 1) ? b++ : w++;
    return true;
}

void paper(int y1, int x1, int y2, int x2) {
    if (!same(y1, x1, y2, x2)) {
        paper(y1, x1, (y1 + y2) / 2, (x1 + x2) / 2);
        paper(y1, (x1 + x2) / 2, (y1 + y2) / 2, x2);
        paper((y1 + y2) / 2, x1, y2, (x1 + x2) / 2);
        paper((y1 + y2) / 2, (x1 + x2) / 2, y2, x2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    paper(0, 0, n, n);

    printf("%d\n%d", w, b);
}
