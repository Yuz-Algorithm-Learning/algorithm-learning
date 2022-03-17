#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long factorial(int num) {
    long long result = 1;
    for (int i = 1; i <= num; ++i)
        result = result * i;
    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer, tmp;
    for(int i = 1; i <= n; i++){
        tmp.push_back(i);
    }
    if(k == 1) return tmp;

    k--;
    long long pre = factorial(n);

    while(tmp.size() != 1) {
        pre /= n;
        long long div = k / pre;
        long long mod = k % pre;

        answer.push_back(tmp[div]);
        tmp.erase(tmp.begin() + div);
        k = mod;
        n--;
    }
    answer.push_back(tmp[0]);

    return answer;
}