#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> arr;
    vector<bool> visit(n, false);
    for (int i = 1; i <= n; i++)
        arr.push_back(i);
    for (int i = 0; i < m; i++)
        visit[i] = true;

    do {
        for (int i = 0; i < arr.size(); i++) {
            if (visit[i])
                printf("%d ", arr[i]);
        }
        printf("\n");
    } while (prev_permutation(visit.begin(), visit.end()));

}