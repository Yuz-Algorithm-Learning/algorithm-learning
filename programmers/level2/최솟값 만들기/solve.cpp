#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    
    int sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }

    return sum;
}