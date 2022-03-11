#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fi(n + 1);
    fi[0] = 0, fi[1] = 1, fi[2] = 1;
    
    for(int i = 3; i <= n; i++) {
        fi[i] = (fi[i - 2] + fi[i - 1]) % 1234567;
    }
    
    return fi[n];
}