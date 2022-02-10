#include <iostream>

using namespace std;

int n, r, c;
int ans;

void z(int y, int x, int len) {
    if (y == r && x == c) {
        printf("%d", ans);
        return;
    }

    if (r >= y && r < y + len && c >= x && c < x + len) {
        z(y, x, len / 2);                       /* 왼쪽 위 */
        z(y, x + len / 2, len / 2);             /* 오른쪽 위 */
        z(y + len / 2, x, len / 2);             /* 왼쪽 아래 */
        z(y + len / 2, x + len / 2, len / 2);   /* 오른쪽 아래 */
    }
    else {
        ans += len * len;
    }
}
int main()
{
    scanf("%d %d %d", &n, &r, &c);

    z(0, 0, 1 << n);
    return 0;
}
