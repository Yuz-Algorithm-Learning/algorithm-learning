#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> a(n + 1);
	vector<int> topology(n + 1);
	vector<int> result;

	int tmp;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);

		vector<int> num(tmp);
		for (int j = 0; j < tmp; j++) {
			scanf("%d", &num[j]);
		}

		for (int j = 0; j < (tmp - 1); j++) {
			a[num[j]].push_back(num[j + 1]);
			topology[num[j + 1]]++;
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (topology[i] == 0)
			pq.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (pq.empty()) {
			printf("0");
			return 0;
		}

		int x = pq.top();
		pq.pop();
		result.push_back(x);

		for (int j = 0; j < a[x].size(); j++) {
			int next = a[x][j];

			if (--topology[next] == 0)
				pq.push(next);
		}

	}

	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);


}
