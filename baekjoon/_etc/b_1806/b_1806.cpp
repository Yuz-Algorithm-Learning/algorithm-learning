#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    queue<int> q;
    int result_num = 987654321;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        q.push(num[i]);
        sum += num[i];

        if (sum > s) {
            while (sum > s) {
                if (q.size() < result_num)
                    result_num = q.size();

                sum -= q.front();
                q.pop();
            }
        }
        if (s != 0 && sum == s) {
            if (q.size() < result_num)
                result_num = q.size();
        }

    }

    if (result_num == 987654321)
        printf("0");
    else
        printf("%d", result_num);
}
