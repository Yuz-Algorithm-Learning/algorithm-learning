#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n) {
        if(!(n % 2)) {
            n >>= 1;
        } else {
            ans++;
            n -= 1;
        }
    }

    return ans;
}