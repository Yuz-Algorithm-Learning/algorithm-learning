#include <iostream>
#include <vector>

#define MAX 987654321
#define CITY 16

using namespace std;

int cost[CITY][CITY];
int dp[CITY][1 << CITY] = { 0 };
int n, all;

int TSP(int curr, int visit) {
	if (visit == all) {
		if (cost[curr][0] != 0)
			return cost[curr][0];
		else
			return MAX;
	}

	int& ref = dp[curr][visit];
	if (ref != 0)
		return ref;

	ref = MAX;
	for (int i = 1; i < n; i++) {
		if (((visit & 1 << i) == 0) && (cost[curr][i] != 0)) {
			ref = min(ref, TSP(i, (visit | (1 << i))) + cost[curr][i]);
		}
			
	}

	return ref;
}

int main() {
	scanf("%d", &n);
	all = (1 << n) - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	printf("%d", TSP(0, 1));
	return 0;
}