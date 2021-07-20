#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> weight(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &weight[i]);

    sort(weight.begin(), weight.end());

    int before_sum = 0;
    for (int i = 0; i < N; i++) {
        if (before_sum + 1 < weight[i])
            break;

        before_sum += weight[i];
    }
    cout << before_sum + 1;
}