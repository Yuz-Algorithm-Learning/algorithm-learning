#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    do {
        for (int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        reverse(arr.begin() + m, arr.end());
    } while (next_permutation(arr.begin(), arr.end()));

}

