#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
int tmp = 0, result = 0;
int visit_alpha[26] = { 0 };

void path(vector<vector<char>>& map, int r, int c) {

    visit_alpha[map[r][c] - 65]++;
    tmp++;

	if ((c + 1 < C) && !visit_alpha[map[r][c+1] - 65]) {        // RIGHT
		path(map, r, c + 1);
	}
	if ((r + 1 < R) && !visit_alpha[map[r + 1][c] - 65]) {      // DOWN
		path(map, r + 1, c);
	}
	if ((c - 1 >= 0) && !visit_alpha[map[r][c - 1] - 65]) {     // LEFT
		path(map, r, c - 1);
	}
	if ((r - 1 >= 0) && !visit_alpha[map[r - 1][c] - 65]) {     // UP
		path(map, r - 1, c);
	}

    result = max(tmp, result);
    visit_alpha[map[r][c] - 65]--;
    tmp--;
}

int main()
{   
    scanf("%d %d", &R, &C);

    char c;
    vector<vector<char>> alpha_map(R);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("\n%c", &c);
            alpha_map[i].push_back(c);
        }
    }

    path(alpha_map, 0, 0);

    printf("%d", result);
}
