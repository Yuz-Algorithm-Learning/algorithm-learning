#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int m_one = 0, zero = 0, p_one = 0;

bool same(int y1, int x1, int y2, int x2) {
    int tmp = map[y1][x1];

    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            if (map[i][j] != tmp)
                return false;
        }
    }

    if (tmp == -1)
        m_one++;
    else if (tmp == 0)
        zero++;
    else
        p_one++;

    return true;
}

void paper(int y1, int x1, int y2, int x2) {

    if (!same(y1, x1, y2, x2)) {
        int weight = (x2 - x1) / 3;

        paper(y1, x1, y1 + weight, x1 + weight);
        paper(y1, x1 + weight, y1 + weight, x1 + 2 * weight);
        paper(y1, x1 + 2 * weight, y1 + weight, x2);

        paper(y1 + weight, x1, y1 + 2 * weight, x1 + weight);
        paper(y1 + weight, x1 + weight, y1 + 2 * weight, x1 + 2 * weight);
        paper(y1 + weight, x1 + 2 * weight, y1 + 2 * weight, x2);

        paper(y1 + 2 * weight, x1, y2, x1 + weight);
        paper(y1 + 2 * weight, x1 + weight, y2, x1 + 2 * weight);
        paper(y1 + 2 * weight, x1 + 2 * weight, y2, x2);
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

    printf("%d\n%d\n%d", m_one, zero, p_one);
}
