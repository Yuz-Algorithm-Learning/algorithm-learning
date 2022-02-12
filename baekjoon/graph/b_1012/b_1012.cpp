#include <iostream>
#include <vector>

using namespace std;

int t, m, n, k;
vector<vector<int>> map;
vector<vector<bool>> visit;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;

		if (map[ny][nx] == 1 && !visit[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &m, &n, &k);

		map.resize(n, vector<int>(m, 0));
		visit.resize(n, vector<bool>(m, 0));
		
		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);

			map[b][a] = 1;
		}

		int cnt = 0;
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < m; q++) {
				if (map[p][q] == 1 && !visit[p][q]) {
					cnt++;
					dfs(p, q);
				}
			}
		}

		printf("%d\n", cnt);

		map.clear();
		visit.clear();
	}

	return 0;
}
