#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, k;
	scanf("%d", &N);
	scanf("%d", &k);

	int low = 1, high = k;
	int result = 0;
	while (low <= high) {

		int sum = 0;
		int mid = (low + high) / 2;

		for (int i = 1; i <= N; i++)
			sum += min(mid / i, N);

		if (sum < k)
			low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}

	cout << result;
	return 0;
}