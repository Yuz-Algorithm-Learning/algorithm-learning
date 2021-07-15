#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int animal[41] = { 0 };

    int tmp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);

        if (tmp > N - 1 || animal[tmp] == 2) {
            cout << 0;
            return 0;
        }

        animal[tmp]++;
    }

    bool one = false;
    int sum = 0,  result = 1;
    for (int i = 0; i < N; i++) {
        if (animal[i] == 2) {
            if (!one)
                result *= 2;
            else
                break;
        }
        else if (animal[i] == 1)
            one = true;
        else
            break;

        sum += animal[i];
    }

    if (one)
        result *= 2;
    if (sum != N)
        result = 0;

    cout << result;

    return 0;
}
