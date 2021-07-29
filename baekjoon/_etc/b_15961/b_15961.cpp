#include <iostream>
#include <vector>

using namespace std;

int sushi_num[3001] = { 0 };

int main()
{
    int N, d, k, c;
    scanf("%d %d %d %d", &N, &d, &k, &c);

    vector<bool> is_sushi(d + 1);
    sushi_num[c]++;
    is_sushi[c] = 1;

    int tmp;
    vector<int> sushi(N);
    int max_sum = 0, sum = 1;        // c
    for (int i = 0; i < k; i++) {
        scanf("%d", &sushi[i]);

        if (!is_sushi[sushi[i]]) {
            is_sushi[sushi[i]] = 1;
            sum++;
        }
        sushi_num[sushi[i]]++;
    }

    max_sum = sum;

    for (int i = 0; i < N; i++) {
        // 첫번째 빼기
        sushi_num[sushi[i]]--;
        if (sushi_num[sushi[i]] == 0)
            sum--;

        int idx = i + k;
        if (idx < N)
            scanf("%d", &sushi[idx]);
        else
            idx = i + k - N;

        // 마지막 넣기
        if (sushi_num[sushi[idx]] == 0)
            sum++;
        sushi_num[sushi[idx]]++;

        if (max_sum < sum)
            max_sum = sum;
    }
    printf("%d", max_sum);
}
