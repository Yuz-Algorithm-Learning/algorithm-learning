#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> jump(2001);
    jump[1] = 1, jump[2] = 2, jump[3] = 3;
    
    for(int i = 4; i <= n; i++) 
        jump[i] = (jump[i - 2] + jump[i - 1]) % 1234567;
    
    return jump[n];
}