#include <iostream>
#include <algorithm>
#include <vector>

#define G_MAX 1000000

using namespace std;

int main()
{
	int G;
	int curr = 1, think = 1;		// 현재 몸무게, 기억하던 몸무게
	vector<int> weight;
	cin >> G;

	while (curr <= G_MAX) {
		int cal = (curr + think) * (curr - think);
		if (cal < G)
			curr++;
		else if (cal == G) {
			weight.push_back(curr);
			curr++, think++;
		}
		else
			think++;
	}

	if (!weight.empty()) {
		sort(weight.begin(), weight.end());

		for (int i = 0; i < weight.size(); i++)
			cout << weight[i] << "\n";
	}
	else {
		cout << -1;
	}

	return 0;

}

