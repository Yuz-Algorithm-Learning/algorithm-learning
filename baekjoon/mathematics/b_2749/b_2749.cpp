#include <iostream>
#include <vector>
using namespace std;

long long fibo[1500001];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    long long n;
    cin >> n;

    fibo[1] = 1;
    fibo[2] = 1;
    for(long long i = 3; i < 1500000; i++) {
        fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 1000000;
    }

    cout << fibo[n % 1500000] << '\n';
}