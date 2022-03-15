#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();
    
    while(1) {
        if(bitset<20>(++n).count() == num) {
            return n;
        }
    }
}

