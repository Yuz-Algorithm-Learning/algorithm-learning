#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> input;
vector<int> front_lis_idx, back_lis_idx;

void LISfunc(vector<int> &lis_idx) {
    vector<int> lis;
    int max_idx = 0;

    lis.push_back(input[0]);
    lis_idx.push_back(0);

    for (int i = 0; i < n; i++) {
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
}

int main()
{
    scanf("%d", &n);

    input.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    LISfunc(front_lis_idx);
    reverse(input.begin(), input.end());
    LISfunc(back_lis_idx);

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, front_lis_idx[i] + back_lis_idx[n - i + 1] + 1);

    printf("%d", answer);
}
