#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> input(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &input[i]);

    int max_idx = 0;
    vector<int> lis, lis_idx; 
    lis.push_back(input[0]);
    lis_idx.push_back(0);

    for (int i = 1; i < N; i++) {
        if (lis.back() < input[i]) {
            lis.push_back(input[i]);
            lis_idx.push_back(++max_idx);
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
            lis[idx] = input[i];
            lis_idx.push_back(idx);
        }
    }

    int find = max_idx;
    vector<int> result;
    for (int i = N - 1; i >= 0; i--) {
        if (lis_idx[i] == find) {
            result.push_back(input[i]);
            find--;
        }
        if (find == -1)
            break;
    }

    printf("%d\n", max_idx + 1);
    for (int i = result.size() - 1; i >= 0; i--)
        printf("%d ", result[i]);
}
