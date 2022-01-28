#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> sum_case(11);
    sum_case[1] = 1;
    sum_case[2] = 2;
    sum_case[3] = 4;

    for (int i = 4; i < 11; i++)
        sum_case[i] = sum_case[i - 3] + sum_case[i - 2] + sum_case[i - 1];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        printf("%d\n", sum_case[tmp]);
    }
}
