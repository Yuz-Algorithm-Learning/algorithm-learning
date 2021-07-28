#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> power;

	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);

		power.emplace_back(a, b);
	}
	sort(power.begin(), power.end());

	int max_idx = 0;
	vector<int> lis, lis_idx;
	lis.push_back(power[0].second);
	lis_idx.push_back(0);

	for (int i = 1; i < n; i++) {
		if (lis.back() < power[i].second) {
			lis.push_back(power[i].second);
			lis_idx.push_back(++max_idx);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), power[i].second) - lis.begin();
			lis[idx] = power[i].second;
			lis_idx.push_back(idx);
		}
	}

	int find = max_idx;
	vector<int> result;
	for (int i = n - 1; i >= 0; i--) {
		if (lis_idx[i] == find)
			find--;
		else
			result.push_back(power[i].first);
	}

	printf("%d\n", n - (max_idx + 1));
	for (int i = result.size() - 1; i >= 0; i--)
		printf("%d\n", result[i]);
}