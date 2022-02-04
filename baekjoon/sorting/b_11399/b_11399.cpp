#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> atm(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &atm[i]);
	}

	sort(atm.begin(), atm.end());

	int result = 0;
	for (int i = 1; i < n; i++) {
		atm[i] += atm[i - 1];
		result += atm[i];
	}
	
	printf("%d", result + atm[0]);
}
