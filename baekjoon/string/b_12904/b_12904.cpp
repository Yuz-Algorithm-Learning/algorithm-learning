#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int result = 0;
    while (S.size() < T.size()) {
        if (T[T.size() - 1] == 'A')
            T = T.substr(0, T.size() - 1);
        else {
            T = T.substr(0, T.size() - 1);
            reverse(T.begin(), T.end());
        }
    }

    (S == T) ? printf("1") : printf("0");
    return 0;
}
