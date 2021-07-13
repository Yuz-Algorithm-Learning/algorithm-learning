#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int gate[100001] = { 0 };

int find(int x) {
	if (gate[x] == x)
		return x;
	
	return gate[x] = find(gate[x]);
}

int main()
{
	int G, P;
	int airplane;
	int max_airplane = 0;

	scanf("%d", &G);
	scanf("%d", &P);

	for (int i = 1; i <= G; i++)
		gate[i] = i;

	for (max_airplane = 1; max_airplane <= P; max_airplane++) {
		cin >> airplane;
		
		int root = find(airplane);
		if (root == 0)
			break;

		gate[root] = root - 1;
	}

	printf("%d", max_airplane - 1);
}
