#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> com;
vector<bool> visit;
int ans = 0;

void dfs(int node) {
	visit[node] = true;
	
	for (int next : com[node]) {
		if (visit[next])
			continue;

		dfs(next);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	com.resize(n + 1);
	visit.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		com[a].push_back(b);
		com[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}

	printf("%d", ans);
}
