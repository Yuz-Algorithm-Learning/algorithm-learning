#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Point p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    int rst = ccw(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

    if(rst == 0) {              /* 일직선 */
        cout << rst << '\n';
    } else if(rst > 0) {        /* 반시계 */
        cout << "1\n";
    } else {                    /* 시계 */
        cout << "-1\n";
    }

    return 0;
}