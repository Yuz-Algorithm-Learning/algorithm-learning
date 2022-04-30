#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int dy[5][3] = {
	{0, 0, 0},
	{-1, 0, 1},
	{-1, 0, 1},
	{-1, -1, -1},
	{1, 1, 1},
};
const int dx[5][3] = {
	{0, 0, 0},
	{1, 1, 1},
	{-1, -1, -1},
	{-1, 0, 1},
	{-1, 0, 1},
};

struct point {
	int y, x;
};

vector<vector<int>> board;
int wall[25][25][25][25] = { 0, };
int r, c, k;

vector<vector<int>> spread(int sy, int sx, int dir) {
	queue<point> q;
	vector<vector<bool>> visited(r + 1, vector<bool>(c + 1));
	vector<vector<int>> tmp_board(r + 1, vector<int>(c + 1));

	tmp_board[sy + dy[dir][1]][sx + dx[dir][1]] = 5;
	visited[sy + dy[dir][1]][sx + dx[dir][1]] = true;
	q.push({ sy + dy[dir][1], sx + dx[dir][1] });

	int num = 4;
	while (!q.empty()) {
		int q_size = q.size();

		while (q_size--) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			for (int i = 0; i < 3; i++) {
				int ny = y + dy[dir][i];
				int nx = x + dx[dir][i];

				if (ny <= 0 || ny > r || nx <= 0 || nx > c)
					continue;

				if (!visited[ny][nx]) {
					if (i == 1) {
						if (wall[y][x][ny][nx])
							continue;
					}
					else {
						if (dir == 1 || dir == 2) {
							if (wall[y][x][ny][x] || wall[ny][x][ny][nx])
								continue;
						}
						else {
							if (wall[y][x][y][nx] || wall[y][nx][ny][nx])
								continue;
						}
					}

					visited[ny][nx] = true;
					tmp_board[ny][nx] = num;
					q.push({ ny, nx });
				}

			}
		}

		num--;
		if (num == 0)
			break;
	}
	
	return tmp_board;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	vector<point> fan;
	board.resize(r + 1, vector<int>(c + 1));
	vector<pair<int, int>> check;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 5) {
				fan.push_back({ i, j });
			}
			if (board[i][j] == 5) {
				check.push_back({ i, j });
			}
		}
	}
	
	int w;
	cin >> w;
	for (int i = 0; i < w; i++) {
		int fy, fx, t;
		cin >> fy >> fx >> t;

		if (t == 0) {
			wall[fy - 1][fx][fy][fx] = true;
			wall[fy][fx][fy - 1][fx] = true;
		}
		else {
			wall[fy][fx][fy][fx + 1] = true;
			wall[fy][fx + 1][fy][fx] = true;
		}
	}

	int choco = 0;
	vector<vector<int>> rst_board(r + 1, vector<int>(c + 1));
	while (1) {
		for (int f = 0; f < fan.size(); f++) {
			int dir = board[fan[f].y][fan[f].x];

			vector<vector<int>> tmp_rst = spread(fan[f].y, fan[f].x, dir);
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					rst_board[i][j] += tmp_rst[i][j];
				}
			}

		}

		// 온도 조절
		vector<vector<int>> tmp_tem(r + 1, vector<int>(c + 1));
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j < c; j++) {
				if (wall[i][j][i][j + 1])
					continue;

				int diff = abs(rst_board[i][j] - rst_board[i][j + 1]) / 4;
				if (diff > 0) {
					if (rst_board[i][j] < rst_board[i][j + 1]) {
						tmp_tem[i][j] += diff;
						tmp_tem[i][j + 1] -= diff;
					}
					else {
						tmp_tem[i][j + 1] += diff;
						tmp_tem[i][j] -= diff;
					}
				}
			}
		}
		for (int j = 1; j <= c; j++) {
			for (int i = 1; i < r; i++) {
				if (wall[i][j][i + 1][j])
					continue;

				int diff = abs(rst_board[i][j] - rst_board[i + 1][j]) / 4;
				if (diff > 0) {
					if (rst_board[i][j] < rst_board[i + 1][j]) {
						tmp_tem[i][j] += diff;
						tmp_tem[i + 1][j] -= diff;
					}
					else {
						tmp_tem[i + 1][j] += diff;
						tmp_tem[i][j] -= diff;
					}
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				rst_board[i][j] += tmp_tem[i][j];
			}
		}

		// 바깥 온도 감소
		for (int i = 2; i <= r - 1; i++) {
			if (rst_board[i][1])
				rst_board[i][1] -= 1;
			if (rst_board[i][c])
				rst_board[i][c] -= 1;
		}
		for (int j = 2; j <= c - 1; j++) {
			if (rst_board[1][j])
				rst_board[1][j] -= 1;
			if (rst_board[r][j])
				rst_board[r][j] -= 1;
		}
		if (rst_board[1][1]) rst_board[1][1] -= 1;
		if (rst_board[1][c]) rst_board[1][c] -= 1;
		if (rst_board[r][1]) rst_board[r][1] -= 1;
		if (rst_board[r][c]) rst_board[r][c] -= 1;

		choco++;


		// CHECK
		int cnt = 0;
		for (int i = 0; i < check.size(); i++) {
			if (rst_board[check[i].first][check[i].second] >= k)
				cnt++;
			else
				break;
		}

		if (cnt == check.size()) {
			break;
		}
		if (choco > 100) {
			choco = 101;
			break;
		}

	}

	cout << choco << '\n';
	return 0;
}
