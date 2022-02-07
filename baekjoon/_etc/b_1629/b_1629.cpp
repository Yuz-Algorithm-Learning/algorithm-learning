#include <iostream>

using namespace std;

long long fast_pow(long long a, long long b, long long c) {
	if (b == 1)
		return a;
	else {
		long long tmp = fast_pow(a, b / 2, c);

		if (b % 2)
			return ((tmp * tmp) % c * a) % c;
		else
			return (tmp * tmp) % c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << fast_pow(a % c, b, c);
}
