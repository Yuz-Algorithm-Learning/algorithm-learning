#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int block_size = w * 2 + 1;
    int idx = 1;
    for(int i = 0; i < stations.size(); i++) {
        idx = stations[i] - w - idx;
        if(0 < idx) {
            int one = (idx % block_size)? 1 : 0;
            int add = idx / block_size;
            answer += one + add;
        }
        idx = stations[i] + w + 1;
    }
    if(idx <= n) {
        int num = n - idx + 1;
        int one = (num % block_size)? 1 : 0;
        answer += num / block_size + one;
    }
    
    return answer;
}